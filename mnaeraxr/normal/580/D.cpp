#include <bits/stdc++.h>

using namespace std;

typedef long long int64;

const int maxn = 19;

int64 dp[maxn][1 << maxn];
int64 val[maxn];
int64 mat[maxn][maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m, k;
	cin >> n >> m >> k;

	for (int i = 0; i < n; ++i)
		cin >> val[i];

	for (int i = 0; i < k; ++i){
		int u, v;
		int64 c;
		cin >> u >> v >> c;
		u--; v--;
		mat[u][v] = c;
	}

	int64 ans = 0;

	for (int i = 1; i < (1 << n); ++i){
		int t = __builtin_popcount(i);
		for (int j = 0; j < n; ++j){
			if (i & (1 << j)){
				int mask = i ^ (1 << j);
				if (mask == 0) dp[j][i] = val[j];
				else{
					for (int k = 0; k < n; ++k){
						if (mask & (1 << k))
							dp[j][i] = max(dp[j][i], val[j] + dp[k][mask] + mat[k][j]);
					}
				}
				if (t == m)
					ans = max(ans, dp[j][i]);
			}
		}
	}

	cout << ans << endl;

	return 0;
}