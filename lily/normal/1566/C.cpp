#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair <int, int> pii;
void read(int &a) {scanf("%d", &a);}
void read(LL &a) {scanf("%lld", &a);}
const int N = 1e5 + 5;
const int INF = 0x3f3f3f3f;
int n;
char s[N], t[N];
int dp[N][4], cnt[4];
int main() {
	cnt[0] = 0;
	cnt[1] = 1;
	cnt[2] = 0;
	cnt[3] = 2;
	int T;
	read(T);
	while (T--) {
		scanf("%d", &n);
		scanf("%s", s + 1);
		scanf("%s", t + 1);
		for (int i = 0; i <= n + 1; i ++) for (int j = 0; j < 4; j++) dp[i][j] = -INF;
		dp[0][0] = 0;
		dp[0][1] = -INF;
		dp[0][2] = -INF;
		dp[0][3] = -INF;
		for (int i = 1; i <= n; i++) {
			int cur_mask = (1 << (s[i] - '0')) | (1 << (t[i] - '0'));
			for (int j = 0; j < 4; j++) {
				dp[i][cur_mask] = max(dp[i][cur_mask], dp[i - 1][j] + cnt[j]);
				dp[i][j | cur_mask] = max(dp[i][j | cur_mask], dp[i - 1][j]);
			}
		}
		int ans = 0;
		for (int j = 0; j < 4; j++) {
			ans = max(ans, dp[n][j] + cnt[j]);
		}
		printf("%d\n", ans);
	}
}