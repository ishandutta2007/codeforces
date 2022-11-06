#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

#define N 200100
#define MOD 1000000007 //998244353
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

int n, m;
int dp[5010][5010];
char a[5010];
int ca[5010][26];
int cb[5010][26];
char b[5010];
int ans;


int main() {
	rep(i, 5010) {
		rep(j, 5010) {
			dp[i][j] = 0;
		}
		rep(j, 26) {
			ca[i][j] = -1;
			cb[i][j] = -1;
		}
		a[i] = 0;
		b[i] = 0;
	}
	cin >> n >> m;
	cin >> a;
	cin >> b;
	rep(i, n) {
		if (i > 0) {
			rep(j, 26)ca[i][j] = ca[i - 1][j];
			ca[i][(a[i - 1] - 'a')] = i - 1;
		}
	}
	rep(i, m) {
		if (i > 0) {
			rep(j, 26)cb[i][j] = cb[i - 1][j];
			cb[i][(b[i - 1] - 'a')] = i - 1;
		}
	}
	ans = 0;
	rep(i, n) {
		rep(j, m) {
			if (a[i] == b[j]) {
				dp[i][j] = 2;
				rep(ii, 26) {
					if ((ca[i][ii] >= 0) && (cb[j][ii] >= 0)) {
						dp[i][j] = max(dp[i][j], dp[ca[i][ii]][cb[j][ii]] + 4 + (ca[i][ii] - i) + (cb[j][ii] - j));
					}
				}
				ans = max(ans, dp[i][j]);
             //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
			}
		}
	}
	cout << ans << endl;

	return 0;
}