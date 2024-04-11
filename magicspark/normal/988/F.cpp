#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,a,b) for (auto i = a; i < b; i++)
#define fill(a,b,x) for (auto it = a; it != b; ++it) *it = x;
#define all(v) v.begin(), v.end()

constexpr int N = 2001;
constexpr int M = 2001;
ll Inf = 1e12;
ll dp[N][M];
bool rain[N];
int umb[M][2];
int a, n, m;

int main() {
	cin >> a >> n >> m;
	rep(i,0,n) {
		int x, y;
		cin >> x >> y;
		rep(j,x + 1,y + 1) {
			rain[j] = true;
		}
	}
	rep(i,0,m) {
		cin >> umb[i][0] >> umb[i][1];
	}
	rep(i,0,a + 1) {
		fill(dp[i], dp[i] + m + 1, Inf);
	}
	dp[0][0] = 0;
	rep(i,1,a+1) {
		int id = 0;
		rep(j,1,m+1) {
			if (dp[i-1][j] < dp[i-1][id]) {
				id = j;
			}
		}
		if (!rain[i]) {
			dp[i][0] = dp[i-1][id];
		}
		rep(j,1,m+1) {
			if (umb[j-1][0] >= i) {
				continue;
			}
			if (umb[j-1][0] == i - 1) {
				dp[i][j] = dp[i - 1][id] + umb[j-1][1];
				continue;
			}
			else {
				dp[i][j] = dp[i-1][j] + umb[j-1][1];
			}
		}
	}
//	rep(i,0,a+1) {
//		rep(j,0,m+1) {
//			cerr << (dp[i][j] < Inf ? dp[i][j] : -1) << " ";
//		}
//		cerr << "\n";
//	}
	ll ans = dp[a][0];
	rep(i,1,m + 1) {
		ans = min(ans, dp[a][i]);
	}
	if (ans >= Inf) {
		ans = -1;
	}
	cout << ans;
}