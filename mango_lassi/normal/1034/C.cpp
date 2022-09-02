#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 1e6;
int vals[N];
vector<int> conns[N];
vector<ll> sums;
ll counts[N+1];

ll dfs(int i = 0, int p = 0) {
	ll s = vals[i];
	for (auto t : conns[i]) {
		if (t == p) continue;
		s += dfs(t, i);
	}
	sums.push_back(s);
	return s;
}

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) cin >> vals[i];
	for (int i = 0; i+1 < n; ++i) {
		int p;
		cin >> p;
		--p;
		conns[i+1].push_back(p);
		conns[p].push_back(i+1);
	}

	ll tree_sum = dfs();
	for (int i = 0; i < sums.size(); ++i) {
		ll v = gcd(sums[i], tree_sum);

		ll j = tree_sum / v;
		if (j <= n) ++counts[j];
	}

	for (int i = n; i > 0; --i) {
		for (int j = 2; (i*j <= n); ++j) counts[i*j] += counts[i];
	}
	
	for (int i = 1; i <= n; ++i) {
		if (counts[i] == i) {
			counts[i] = 1;
		} else {
			counts[i] = 0;
		}
	}
	
	for (int i = n; i > 0; --i) {
		if (counts[i] == 1) {
			for (int j = 2; (i*j) <= n; ++j) {
				counts[i] += counts[i*j];
			}
			counts[i] %= MOD;
		}
	}
	cout << counts[1] << '\n';

	// A value X works iff S % X == 0 at 
	// take the GCD of sum(TREE) and sum of subtree S. Now, for a value X to work, it has to be >= max(a_i), and divide exactly sum(TREE) / X of these values.
	// If value V works, and value V*K works, they can be layered

	// How to solve if a_i = 1 for all i?
	// With a given value, calculate in O(n) whether the tree can be divided into pieces with that value.
	// Let S be the sum of values in the tree.
	// Now, if we have a value D we want, then must be D | S, S / D <= n, exists some T such that S(T) = D, and can(D)
}