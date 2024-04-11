#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 110
#define MOD 998244353
#define ll long long
#define rep(i, n) for(int i = 0; i < n; ++i)
#define rep2(i, a, b) for(int i = a; i <= b; ++i)
#define rep3(i, a, b) for(int i = a; i >= b; --i)
#define eb emplace_back
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
struct Setup_io {
	Setup_io() {
		ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
		cout << fixed << setprecision(15);
	}
} setup_io;



int main() {
	int t, n;
	int a[N];
	int c[N][N];
	int dp[N][N];
	int ans;
	bool ex[N];
	cin >> t;
	rep(tt, t) {
		cin >> n;
		rep(i, n)cin >> a[i];
		rep(j, n + 1) {
			rep(i, j) {
				rep(k, N)ex[k] = false;
				rep2(k, i, j - 1) {
					if (a[k] < N)ex[a[k]] = true;
				}
				rep(k, N) {
					if (!ex[k]) {
						c[i][j] = k + 1;
						break;
					}
				}
			}
		}
		ans = 0;
		rep(j, n + 1) {
			rep(i, j) {
				dp[i][j] = c[i][j];
				rep2(k, i + 1, j - 1)dp[i][j] = max(dp[i][j], dp[i][k] + c[k][j]);
				ans += dp[i][j];
			}
		}
		cout << ans << endl;
	}
	return 0;
}