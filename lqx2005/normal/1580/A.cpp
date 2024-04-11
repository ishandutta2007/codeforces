#include <bits/stdc++.h>
#define i64 long long
using namespace std;
const int N = 400 + 10;
int n, m;
int a[N][N], row[N][N], column[N];

void solve() {
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		char w;
		for(int j = 1; j <= m; j++) {
			cin >> w;
			a[i][j] = w - '0';
			row[i][j] = row[i - 1][j] + a[i][j];
		}
	}
	int ans = INT_MAX / 2;
	for(int i = 1; i <= n; i++) {
		for(int j = i + 4; j <= n; j++) {
			for(int k = 1; k <= m; k++) {
				column[k] = column[k - 1] + !a[i][k] + !a[j][k] + (row[j - 1][k] - row[i][k]);
			}
			int now = INT_MAX / 2;
			for(int k = 3; k < m; k++) {
				now = min(now, j - i - 1 - (row[j - 1][k - 2] - row[i][k - 2]) - column[k - 2]);
				ans = min(ans, now + column[k] + j - i - 1 - (row[j - 1][k + 1] - row[i][k + 1]));
			}
		}
	}
	cout << ans << endl;
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T--; ) {
		solve();
	}	
	return 0;
}