#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
#define N 101
#define M 10010
#define MOD 500000007 //998244353
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

int dp[N][M];

int main() {
	int n;
	int a[N];
	int b[N];
	int sa = 0;
	int sb = 0;
	int ans = 0;
	
	cin >> n;
	rep(i, n) {
		cin >> a[i] >> b[i];
		sa += a[i];
		sb += b[i];
	}
	rep(i, N)rep(j, M)dp[i][j] = MOD;
	dp[0][0] = 0;
	rep(i, n) {
		rep3(ii, i, 0) {
			rep3(j, M - a[i] - 1, 0) {
				if (dp[ii + 1][j + a[i]] > (dp[ii][j] + b[i]))dp[ii + 1][j + a[i]] = dp[ii][j] + b[i];
			}
		}
	}
	rep3(i, n - 1, 0) {
		ans = 0;
			rep(j, M) {
				ans = max(ans, min((2 * sb) - dp[i][j], 2 * (sa - j)));
			}
		if (ans % 2 == 1) {
			ans /= 2;
			cout << ans << ".5";
		}
		else {
			ans /= 2;
			cout << ans;
		}
		if (i > 0)cout << " ";
		else cout << endl;
	}

	return 0;
}