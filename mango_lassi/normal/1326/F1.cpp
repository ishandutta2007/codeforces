#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 14;
const int H = 7;
const int M = 9908;
vector<int> dp[M][N]; // Ways to produce this adjacency string on these wise men ending on this wise man
int adj[N][N]; // Are wise men i and j friends?
int cou[N+1][N+1]; // Number of ways to choose A from B
ll ans[1 << (N-1)];
int rev[1 << H];

int ump[M];
int imp[1<<N];

int unmap(int ind, int n) {
	int k = 0;
	while(k < n && ind >= cou[n][k]) {
		ind -= cou[n][k];
		++k;
	}
	int res = 0;
	for (int i = 0; i < n && k > 0; ++i) {
		if (ind < cou[n-1-i][k-1]) {
			res |= 1 << i;
			--k;
		} else {
			ind -= cou[n-1-i][k-1];
		}
	}
	return res;
}
int mapInd(int mask, int n) {
	int k = __builtin_popcount(mask);
	int ind = 0;
	for (int j = 0; j < k; ++j) ind += cou[n][j];
	for (int i = 0; i < n && k > 0; ++i) {
		if (mask & (1 << i)) --k;
		else ind += cou[n-1-i][k-1];
	}
	return ind;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	int h = (n+1) / 2;
	int h2 = n - h;

	for (int k = 0; k <= n; ++k) {
		cou[k][0] = 1;
		for (int j = 1; j <= k; ++j) {
			cou[k][j] = cou[k-1][j] + cou[k-1][j-1];
		}
	}

	int m = 0;
	for (int j = 0; j < min(h+1, n); ++j) m += cou[n][j];

	for (int mask = 0; mask < (1 << n); ++mask) imp[mask] = mapInd(mask, n);
	for (int j = 0; j < m; ++j) ump[j] = unmap(j, n);

	for (int mask = 0; mask < (1 << (h2 - 1)); ++mask) {
		for (int j = 0; j < h2 - 1; ++j) {
			if (mask & (1 << j)) rev[mask] |= 1 << (h2 - 2 - j);
		}
	}


	for (int a = 0; a < n; ++a) {
		string row;
		cin >> row;
		for (int b = 0; b < n; ++b) {
			adj[a][b] = (row[b] == '1');
		}
	}

	for (int ind = 1; ind < m; ++ind) {
		int mask = ump[ind];
		int k = __builtin_popcount(mask);
		for (int b = 0; b < n; ++b) {
			if (! (mask & (1 << b))) continue;
			if (k == 1) {
				dp[ind][b] = {1};
			} else {
				dp[ind][b].resize(1 << (k-1), 0);

				int sub = mask ^ (1 << b);
				int subind = imp[sub];
				for (int a = 0; a < n; ++a) {
					if (! (sub & (1 << a))) continue;
					for (int v = 0; v < dp[subind][a].size(); ++v) {
						dp[ind][b][v | (adj[a][b] << (k-2))] += dp[subind][a][v];
					}
				}
			}
		}
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		if (__builtin_popcount(mask) == h) {
			int revmask = ((1 << n) - 1) ^ mask;

			int ind = imp[mask];
			int revind = imp[revmask];

			for (int a = 0; a < n; ++a) {
				if (! (mask & (1 << a))) continue;

				for (int b = 0; b < n; ++b) {
					if (! (revmask & (1 << b))) continue;
					
					for (int y = 0; y < (1 << (h2-1)); ++y) {
						for (int x = 0; x < (1 << (h-1)); ++x) {
							ans[x | (adj[a][b] << (h-1)) | (rev[y] << h)] += (ll)dp[ind][a][x] * dp[revind][b][y];
						}
					}
				}
			}
		}
	}
	for (int x = 0; x < (1 << (n-1)); ++x) cout << ans[x] << ' '; cout << '\n';
}