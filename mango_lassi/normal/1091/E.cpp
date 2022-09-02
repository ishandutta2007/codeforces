#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll INF = (ll)1e18;
const int N = 1<<20;
ll mins[2*N]; // Min of subtree
ll tags[2*N]; // Add this to subtree

void push(int i) {
	if (tags[i] != 0) {
		mins[i] += tags[i];
		if (i < N) {
			tags[2*i] += tags[i];
			tags[2*i+1] += tags[i];
		}
		tags[i] = 0;
	}
}
void add(int a, int b, ll v, int i = 1, int ia = 0, int ib = N-1) {
	push(i);
	if (b < ia || ib < a) return;
	if (a <= ia && ib <= b) {
		tags[i] += v;
		push(i);
	} else {
		int mid = (ia + ib) >> 1;
		add(a, b, v, 2*i, ia, mid);
		add(a, b, v, 2*i+1, mid+1, ib);
		mins[i] = min(mins[2*i], mins[2*i+1]);
	}
}

ll get(int a, int b, int i = 1, int ia = 0, int ib = N-1) {
	push(i);
	if (b < ia || ib < a) return INF;
	if (a <= ia && ib <= b) return mins[i];
	int mid = (ia + ib) >> 1;
	ll res = INF;
	res = min(res, get(a, b, 2*i, ia, mid));
	res = min(res, get(a, b, 2*i+1, mid+1, ib));
	return res;
}

// Find smallest i such that vals[i] <= v
int bins(const vector<ll>& vals, ll v) {
	int low = 0;
	int high = vals.size();
	while(low != high) {
		int mid = (low + high) >> 1;
		if (vals[mid] <= v) high = mid;
		else low = mid + 1;
	}
	return low;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	// Use the erds-gallai theorem
	// Possible iff d_1 + ... + d_n is even and
	// \sum_{i = 1}^{k} d_{i} <= k(k-1) + \sum_{i = k+1}^{n} min(d_i, k)
	// k(k-1) + \sum_{i = k+1}^{n} min(d_i, k) - \sum_{i = 1}^{k} d_i
	// -> Trivial with add and min segtree
	
	// Read input
	int parity = 0;
	vector<ll> ds(n);
	for (int i = 0; i < n; ++i) {
		cin >> ds[i];
		parity ^= ds[i] % 2;
	}
	
	// Sort to non-decreasing order
	for (int i = 0; i < n; ++i) ds[i] *= -1;
	sort(ds.begin(), ds.end());
	for (int i = 0; i < n; ++i) ds[i] *= -1;

	// Calc suffix and prefix sums of ds
	vector<ll> ss(n+1, 0);
	for (int i = n-1; i >= 0; --i) ss[i] = ss[i+1] + ds[i];
	
	vector<ll> ps(n, 0);
	ps[0] = ds[0];
	for (int i = 1; i < n; ++i) ps[i] = ps[i-1] + ds[i];

	// Calc initial values of inequality
	for (int i = 0; i < n; ++i) {
		int ind = bins(ds, i+1);
		int inte = max(i+1, ind);
		ll lst = (ll)(i+1)*(inte - (i+1)) + ss[inte];
		ll val = (ll)i*(i+1) - ps[i] + lst;
		
		// val = k(k-1) + \sum_{i = k+1}^{n} min(d_i, k) - \sum_{i = 1}^{k} d_i
		// cout << "Val at " << i << ": " << val << ' ' << lst << endl;
		
		add(i, i, val);
	}
	
	// Find answer
	// Always decrement from largest (last) number
	vector<int> perm;
	for (int i = 0; i < n;) {
		int j = i+1;
		for (; j < n; ++j) {
			if (ds[j] != ds[i]) break;
		}
		for (int z = j-1; z >= i; --z) perm.push_back(z);
		i = j;
	}

	vector<int> res;
	if ((get(0, n-1) >= 0) && (parity == 0)) res.push_back(0);
	for (int j = 0; j < n; ++j) {
		int i = perm[j];
		if (ds[i] == 0) break;

		// Subtract one from ds at position perm[j]
		parity ^= 1;
		add(i, n-1, 1); // Subtract from second sum
		add(ds[i]-1, i-1, -1); // Subtract from first sum
		// cout << "Add 1 to " << i << ", " << n-1 << '\n';
		// cout << "Add -1 to " << ds[i] << ", " << i-1 << '\n';
		// cout << "Min: " << get(0, n-1) << '\n';

		// Check that all conditions hold
		if ((get(0, n-1) >= 0) && (parity == 0)) res.push_back(j+1);
	}

	if (res.empty()) {
		cout << "-1\n";
	} else {
		for (auto it : res) cout << it << ' '; cout << '\n';
	}
}