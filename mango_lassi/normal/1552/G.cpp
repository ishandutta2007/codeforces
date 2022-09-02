#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 40;
const int K = 10;
ll inds[K];
ll nxt[K][N + 1];
ll as[K];
int k;
bool res = 1;

void dfs(int i, ll cur) {
	if (i == k) {
		res &= (__builtin_popcountll(cur + 1) == 1); // TRUE IFF all 1's in a prefix
	} else {
		int bs = __builtin_popcountll(inds[i] & cur);
		ll rem = cur & (~inds[i]);
		for (int a = 0; a <= as[i]; ++a) dfs(i + 1, rem | nxt[i][bs + a]);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n >> k;

	// check all 2^n bitmasks -> sufficient
	// what bitmasks do we not need to try?

	// need to only choose number of 1's in first operation
	// need only choose number of 1's in second operation / first operation
	// need only choose humber of 1's in third operatoin / first operation / second operation
	// ...
	
	// a_i: number of positions in i'th operation and not in operations before it
	//	-> time complexity: product of (a_i + 1)
	//		worst case: all a_i equal 4
	//		-> 5^10 ~ 1e7 work!
	//	just need O(1) check per array of counts
	//	-> do in DFS order

	ll seen = 0;
	for (int i = 0; i < k; ++i) {
		int m;
		cin >> m;

		inds[i] = 0;
		nxt[i][0] = 0;
		for (int c = 0; c < m; ++c) {
			ll j;
			cin >> j;
			--j;
			inds[i] |= (1ll << j);
			nxt[i][c + 1] = inds[i];
		}
		as[i] = __builtin_popcountll(inds[i] ^ (inds[i] & seen));
		seen |= inds[i];
	}

	dfs(0, 0);
	res &= (n == 1) || (seen == ((1ll << n) - 1));
	if (res) cout << "ACCEPTED\n";
	else cout << "REJECTED\n";

}