#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	ll res = n;
	ll mult = n;
	for (int lca = 1; lca < n; ++lca) {
		ll tmp = (mult * (n-1-lca))% MOD;
		res += (tmp * (lca + 1)) % MOD;
		mult = (mult * (n-lca)) % MOD;
	}
	res %= MOD;
	cout << res << '\n';

	// 0: 4   4
	// 1: 8   4*2
	// 2: 12  4*3*1

	// 0: 5   5
	// 1: 

	// LCA with next is k -> add k+1 to res

	// 1 2 3 4 	2
	// 1 2 4 3 	1
	// 1 3 2 4 	2
	// 1 3 4 2 	1
	// 1 4 2 3 	2
	// 1 4 3 2 	0
	// 2 1 3 4 	2
	// 2 1 4 3 	1
	// 2 3 1 4 	2
	// 2 3 4 1 	1
	// 2 4 1 3 	2
	// 2 4 3 1 	0
	// 3 1 2 4	2
	// 3 1 4 2	1
	// 3 2 1 4	2
	// 3 2 4 1	1
	// 3 4 1 2	2
	// 3 4 2 1	0
	// 4 1 2 3	2
	// 4 1 3 2	1
	// 4 2 1 3	2
	// 4 2 3 1	1
	// 4 3 1 2	2
	// 4 3 2 1	0
}