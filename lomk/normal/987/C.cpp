/*input
5
2 4 5 4 10
40 30 20 10 40



*/
#include <bits/stdc++.h>
using namespace std;
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define mp make_pair
#define int long long
#define N 3005
#define bit(x,y) ((x>>y)&1LL)
#define For(i,l,r) for(int i=l; i<r; i++)

int n;
int s[N];
int c[N];
int dp[N][4];
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> s[i];
	for (int i = 1; i <= n; i++) cin >> c[i];
	memset(dp, 127, sizeof(dp));
	for (int i = 1; i <= n; i++) dp[i][1] = c[i];
	for (int k = 2; k <= 3; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= i - 1; j++) {
				if (s[i] > s[j])
					dp[i][k] = min(dp[i][k], dp[j][k - 1] + c[i]);
			}
		}
	}
	int ans = 1e18;
	for (int i = 1; i <= n; i++) ans = min(ans, dp[i][3]);
	if (ans > 1e15) cout << -1 << endl;
	else cout << ans << endl;
}