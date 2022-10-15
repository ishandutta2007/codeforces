#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

#define N (1 << 20)
const int INF = 0x3f3f3f3f;
int n, m, mm, K, ans;
int a[N], b[N];
bool q[N]; 
int dp[N][2][2], cnt[N];

int main() {
	read(n); read(K);
	for (int i = 1; i <= K; i++) read(b[i]), b[i]--;
	sort(b + 1, b + K + 1);
	m = 1 << n;
	mm = m / 4;
	for (int i = 1; i <= K; i++) {
		int x = mm + b[i] / 4;	
		cnt[x]++;
		if (!ans) ans++;
		if (!q[b[i] / 2]) ans++;
		q[b[i] / 2] = 1;
	}
	memset(dp, 200, sizeof dp);
	for (int i = mm * 2 - 1; i >= mm; i--) {
		if (cnt[i] >= 2) {
			dp[i][1][1] = 3;
			dp[i][1][0] = 2;
			dp[i][0][1] = 1;
			dp[i][0][0] = -INF;
		}
		else if (cnt[i] == 1) {
			dp[i][1][1] = -INF;
			dp[i][1][0] = 2;
			dp[i][0][1] = 1;
			dp[i][0][0] = -INF;
		}
		else {
			dp[i][1][1] = -INF;
			dp[i][1][0] = -INF;
			dp[i][0][1] = -INF;
			dp[i][0][0] = 0;
		}
	}
	for (int i = mm - 1; i; i--) {
		int l = i * 2, r = i * 2 + 1;
		for (int u = 0; u <= 1; u++)
			for (int v = 0;v <= 1; v++) if (dp[l][u][v] >= 0)
				for (int w = 0; w <= 1; w++)
					for (int x = 0; x <= 1; x++) if (dp[r][w][x] >= 0) {
						dp[i][max(u, w)][max(v, x)] = max(dp[i][max(u, w)][max(v, x)], dp[l][u][v] + dp[r][w][x] + max(u, w) * 2 + max(v, x));
					}
	}
	int tt = 0;
		for (int u = 0; u <= 1; u++)
			for (int v = 0;v <= 1; v++) if (dp[1][u][v] >= 0)
				tt = max(tt, dp[1][u][v]);
	cout << ans +  tt << endl;
}