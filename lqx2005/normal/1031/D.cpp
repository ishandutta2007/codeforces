#include <bits/stdc++.h>
#define broken cerr << "running on " << __FUNCTION__ <<" "<< __LINE__ << endl
#define x first
#define y second
#define sz(a) int((a).size())
#define pi pair<int, int>
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N = 2000 + 10;
int n, k;
int dp[N][N], A[N][N];
int rnk[N][N], nxt[N][N];
pi sa[N];
char s[N][N];
int main() {
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		cin >> (s[i] + 1);
		for(int j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (s[i][j] == 'a');
		}
	}
	int mx = 0;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i + j - 1 - dp[i][j] <= k) {
				A[i + 1][j] = A[i][j + 1] = 1;
				mx = max(mx, i + j - 1);
			}
		}
	}
	int tot = 0;
	for(int i = 2 * n - 1; i >= mx + 1; i--) {
		tot = 0;
		for(int j = max(1, i - n + 1); j <= min(n, i); j++) {
			int x = j, y = i - j + 1;
			rnk[x][y] = n + 1;
			if(x + 1 <= n && rnk[x][y] > rnk[x + 1][y]) rnk[x][y] = rnk[x + 1][y], nxt[x][y] = 1;
			if(y + 1 <= n && rnk[x][y] > rnk[x][y + 1]) rnk[x][y] = rnk[x][y + 1], nxt[x][y] = -1;
			sa[++tot] = {x, y};
		}
		sort(sa + 1, sa + tot + 1, [&](pi a, pi b) {
			if(s[a.x][a.y] != s[b.x][b.y]) return s[a.x][a.y] < s[b.x][b.y];
			return rnk[a.x][a.y] < rnk[b.x][b.y];
		});
		int uni = 1;
		rnk[sa[1].x][sa[1].y] = 1;
		for(int j = 2; j <= tot; j++) {
			int px = sa[j - 1].x, py = sa[j - 1].y, x = sa[j].x, y = sa[j].y;
			uni += !(s[px][py] == s[x][y] && rnk[px][py] == rnk[x][y]);
			rnk[x][y] = uni;
		}
	}
	A[1][1] = 1;
	int ax = -1, ay = -1;
	for(int i = 1; i <= tot; i++) {
		if(A[sa[i].x][sa[i].y]) {
			ax = sa[i].x, ay = sa[i].y;
			break;
		}
	}
	if(mx == 2 * n - 1) {
		for(int i = 1; i <= 2 * n - 1; i++) cout << "a";
		cout << endl;
		return 0;
	}
	string ans;
	for(int x = ax, y = ay; ; ) {
		ans += s[x][y];
		if(nxt[x][y] == 0) break;
		else if(nxt[x][y] == 1) x++;
		else y++;
	}
	for(int i = 1; i <= ax + ay - 2; i++) cout << "a";
	cout << ans << endl;
	return 0;
}