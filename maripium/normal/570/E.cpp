#include <bits/stdc++.h>
using namespace std;

const int N = 505;
const int mod = 1e9 + 7;
const pair<int,int> Go[] = {{1, 0}, {0, 1}};
const pair<int,int> Back[] = {{-1, 0}, {0, -1}};

int n, m;
char a[N][N];
int dp[2][N][N];


bool valid(int x,int y) {
	return x > 0 && x <= n && y > 0 && y <= m; 
}

void add(int &x,int y) {
	x += y;	while(x >= mod) x -= mod; while(x < 0) x += mod;
}

int main() {
	ios_base::sync_with_stdio(false);	cin.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n; ++i)
		for (int j = 1;j <= m; ++j) cin >> a[i][j];
	
	if (a[1][1] != a[n][m]) return cout << 0 << endl,0;
	dp[0][1][n] = 1;
	
	for (int cnt = 0;cnt < (m + n - 2) >> 1; ++cnt) {
		for (int X1 = 1;X1 <= n; ++X1) for (int X2 = 1;X2 <= n; ++X2) {
			if (dp[0][X1][X2] == 0) continue;
			int Y1 = cnt + 2 - X1, Y2 = m + n - cnt - X2;
			if (!valid(X1, Y1) || !valid(X2, Y2)) continue;
			for (int i = 0;i < 2; ++i) for (int j = 0;j < 2; ++j) {
				int nxtX1 = X1 + Go[i].first, nxtY1 = Y1 + Go[i].second;
				int nxtX2 = X2 + Back[j].first, nxtY2 = Y2 + Back[j].second;
				if (!valid(nxtX1, nxtY1) || !valid(nxtX2, nxtY2)) continue;
				if (a[nxtX1][nxtY1] == a[nxtX2][nxtY2]) add(dp[1][nxtX1][nxtX2], dp[0][X1][X2]);
			}
		}
		
		for (int X1 = 1;X1 <= n; ++X1) for (int X2 = 1;X2 <= n; ++X2) {
			dp[0][X1][X2] = dp[1][X1][X2];
			dp[1][X1][X2] = 0;
		}
	}
	int ans = 0;
	if ((m + n) & 1) {
		for (int i = 1;i <= n; ++i) for (int j = 0;j < 2;++j) {
			int nxt = i + Go[j].first;
			if (nxt > 0 && nxt  <= n) add(ans, dp[0][i][nxt]);
		}
	}
	
	else for (int i = 1;i <= n;++i) add(ans, dp[0][i][i]);
	
	cout << ans << endl;
}