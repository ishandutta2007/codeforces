#include <bits/stdc++.h>
#define par pair<int, int>
#define x first
#define y second
#define mp make_pair
#define sz(a) int((a).size())
using namespace std;
typedef double db;
typedef long long ll;
const int N = 2e3 + 10, P = 1e9 + 7;
int n, m;
char s[2][N], w[N];
int l[2][N][N], r[2][N][N];
int dp[N][N][2];
int solve() {
	memset(l, 0, sizeof(l)), memset(r, 0, sizeof(r)), memset(dp, 0, sizeof(dp));
	for(int i = 0; i <= 1; i++) {
		for(int j = 1; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				if(s[i][j] == w[k]) {
					l[i][j][k] = l[i][j - 1][k - 1] + 1;
				}
			}
		}
		for(int j = n; j >= 1; j--) {
			for(int k = 1; k <= m; k++) {
				if(s[i][j] == w[k]) {
					r[i][j][k] = r[i][j + 1][k - 1] + 1;
				}
			}
		}
	}
	for(int i = 0; i <= n; i++) {
		dp[i][0][0]++, dp[i][0][1]++;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			int len = j - i + 1;
			for(int k = 0; k <= 1; k++) {
				if(r[k][i][len] >= len && l[k ^ 1][j][len * 2] >= len) {
					dp[j][len * 2][k ^ 1]++;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= m; j++) {
			for(int k = 0; k <= 1; k++) {
				if(w[j + 1] == s[k][i + 1]) {
					(dp[i + 1][j + 1][k] += dp[i][j][k]) %= P;
					if(w[j + 2] == s[k ^ 1][i + 1]) {
						(dp[i + 1][j + 2][k ^ 1] += dp[i][j][k]) %= P;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i <= n; i++) {
		for(int k = 0; k <= 1; k++) {
			(ans += dp[i][m][k]) %= P;
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			if((m - j) & 1) continue;
			if(m - j <= 2) continue;
			int len = (m - j) / 2;
			for(int k = 0; k <= 1; k++) {
				if(r[k ^ 1][i + 1][m] >= len && l[k][i + len][m - len] >= len) {
					(ans += dp[i][j][k]) %= P;
				}
			}
		}
	}
	return ans;
}
int main() {
	cin >> (s[0] + 1) >> (s[1] + 1);
	n = strlen(s[0] + 1);
	cin >> (w + 1);
	m = strlen(w + 1);
	if(m == 1) {
		int cnt = 0;
		for(int k = 0; k <= 1; k++) for(int i = 1; i <= n; i++) if(s[k][i] == w[1]) cnt++;
		cout << cnt << endl;
		return 0;
	}
	int ans = solve();
	reverse(w + 1, w + m + 1);
	(ans += solve()) %= P;
	if(m % 2 == 0) {
		for(int i = 1; i <= n - m / 2 + 1; i++) {
			int len = m / 2, j = i + len - 1;
			for(int k = 0; k <= 1; k++) {
				if(r[k][i][len] >= len && l[k ^ 1][j][len * 2] >= len) {
					(ans += P - 1) %= P;
				}
			}
		}
		if(m > 2) {
			for(int i = 0; i <= n - m / 2; i++) {
				int len = m / 2;
				for(int k = 0; k <= 1; k++) {
					if(r[k ^ 1][i + 1][m] >= len && l[k][i + len][m - len] >= len) {
						(ans += P - 1) %= P;
					}
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}