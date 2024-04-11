#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1<<18;
ll seg1[2 * N]; // Sum of difficulty of active tasks below this
ll seg2[2 * N]; // Sum of amount of active tasks below this
int h;

void actv(int i, int v) {
	i += h;
	seg1[i] = v;
	seg2[i] = 1;
	while(i > 1) {
		i >>= 1;
		seg1[i] = seg1[2*i] + seg1[2*i+1];
		seg2[i] = seg2[2*i] + seg2[2*i+1];
	}
}

ll sum(ll* arr, int a, int b, int i = 1, int ia = 0, int ib = h-1) {
	if (ib < a || b < ia) return 0;
	if (a <=ia && ib<= b) return arr[i];
	int mid = (ia + ib) >> 1;
	return sum(arr, a, b, 2*i, ia, mid) + sum(arr, a, b, 2*i+1, mid+1, ib);
}

// Finds maximum res <= b where arr[a .. res] <= v
// Can return a-1
int bins(ll* arr, int a, int b, ll v) {
	int low = a-1;
	int high = b;
	while(low < high) {
		int mid = (low + high + 1) >> 1;
		if (sum(arr, a, mid) <= v) low = mid;
		else high = mid - 1;
	}
	return low;
}

void solve() {
	int n, m;
	ll t;
	cin >> n >> m >> t;

	h = 1;
	while(h < n) h <<= 1;
	
	vector<pair<int, int>> tasks(n);
	for (int i = 0; i < n; ++i) {
		cin >> tasks[i].first;
		tasks[i].second = i;
	}
	sort(tasks.begin(), tasks.end());

	ll res = 0;
	int d = 1;
	for (int j = 0; j < tasks.size();) {
		int cd = tasks[j].first;
		if (cd > t) break;
		while(j < tasks.size()) {
			if (tasks[j].first != cd) {
				break;
			} else {
				actv(tasks[j].second, cd);
				++j;
			}
		}

		// Binary search segtree three times times
		// Maximum prefix we can do with double cost
		int mpref = bins(seg1, 0, n-1, t / 2);
		// Amount of elements in the prefix
		int cou = sum(seg2, 0, mpref);
		cou -= cou % m;
		// Maximum prefix we can do in groups of m with double cost
		mpref = bins(seg2, 0, n-1, cou);
		// Maximum prefix we can do with real cost
		ll cost = 2 * sum(seg1, 0, mpref);
		int tmp = bins(seg1, mpref + 1, n-1, t - cost);
		// We cannot have a new piece in this one
		tmp = min(tmp, bins(seg2, mpref + 1, n-1, m));
		// Maximum amount we can do with real cost
		int off = sum(seg2, 0, tmp);

		if (off >= res) {
			res = off;
			d = cd;
		}
	}
	cout << res << ' ' << d << '\n';
	
	// Clean global arrays
	for (int i = 0; i < 2*h; ++i) {
		seg1[i] = 0;
		seg2[i] = 0;
	}
}

int main() {
	int c;
	cin >> c;
	for (int i = 0; i < c; ++i) solve();
}