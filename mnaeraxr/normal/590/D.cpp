#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef pair<int,int> pii;
typedef vector<int> vi;

const int maxn = 152;
const int oo = 0x3f3f3f3f;

int dp[2][maxn][maxn * maxn];
int v[maxn];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k, s;
	cin >> n >> k >> s;
	for (int i = 1; i <= n; ++i)
		cin >> v[i];

	if (s >= n * (n - 1) / 2)
	{
		sort(v + 1, v + n + 1);
		int ans = 0;
		for (int i = 1; i <= k; ++i)
			ans += v[i];
		cout << ans << endl;
		exit(0);
	}

	memset(dp, oo, sizeof dp);
	int cur = 0, prev = 1;
	memset(dp[prev][0], 0, sizeof dp[prev][0]);

	for (int i = 1; i <= n; ++i){
		for (int j = 0; j <= min(i, k); ++j){
			for (int w = 0; w <= s; ++w){
				dp[cur][j][w] = oo;
				dp[cur][j][w] = min(dp[cur][j][w], dp[prev][j][w]);
				if (j && w - (i - j) >= 0){
					// cout << v[j] << " " << dp[prev][j - 1][w - (j - 1)] << endl;
					dp[cur][j][w] = min(dp[cur][j][w], v[i] + dp[prev][j - 1][w - (i - j)]);
					// cout << "--> ";
				}
				// cout << i << " " << j << " " << w << " " << dp[cur][j][w] << endl;
			}
		}
		swap(cur, prev);
	}

	cout << dp[prev][k][s] << endl;

	return 0;
}