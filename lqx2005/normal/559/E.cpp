#include <bits/stdc++.h>
#define a first
#define l second
#define pi pair<int, int>
using namespace std;
const int N = 100 + 10;
int n;
pi seg[N];
int dp[N][N][2];

void chkmax(int &x, int y) {
	if(x < y) x = y;
}

int main() {
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> seg[i].a >> seg[i].l;
	sort(seg + 1, seg + n + 1);
	seg[0].a = -1e9, seg[0].l = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <= i; j++) {
			for(int p = 0; p < 2; p++) {
				int x = j, y = p, now = seg[j].a + seg[j].l * p, nowr = now;
				if(nowr < seg[i + 1].a + seg[i + 1].l) {
					x = i + 1, y = 1;
					now = seg[i + 1].a + seg[i + 1].l;
				}
				int L = max(nowr, seg[i + 1].a), R = now;
				chkmax(dp[i + 1][x][y], dp[i][j][p] + (R - L));
				x = j, y = p, now = nowr;
				for(int k = i + 1; k <= n; k++) {
					if(seg[k].a > now) {
						now = seg[k].a;
						x = k, y = 0;
					}
					L = max(nowr, seg[k].a - seg[k].l), R = now;
					chkmax(dp[k][x][y], dp[i][j][p] + R - L);
					if(seg[k].a + seg[k].l > now) {
						now = seg[k].a + seg[k].l;
						x = k, y = 1;
					}
				}
			}
		}
	}
	for(int j = 1; j <= n; j++) {
		for(int p = 0; p < 2; p++) {
			chkmax(ans, dp[n][j][p]);
		}
	}
	cout << ans << endl;
	return 0;
}