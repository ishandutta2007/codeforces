#include <iostream>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
ll a[505][505];
ll dp[505][505], dp2[505][505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	rep(i, 0, n-1) rep(j, 0, n-1) cin >> a[i][j];

	rep(i, 0, n-1){
		dp[i][i] = 1;
		dp2[i][i+1] = 1;
	}
	rep(len, 2, n){
		rep(l, 0, n-1){
			ll r = (l + len - 1);
			if(r >= n) break;
			if(len >= 3){
				rep(i, l+1, r-1){
					if(a[l][i] == 0) continue;
					dp2[l][r] += dp2[l][i] * dp2[i][r] % mod, dp2[l][r] %= mod;
				}
				dp2[l][r] += dp[l+1][r], dp2[l][r] %= mod;
			}
		}
		rep(l, 0, n-1){
			ll r = (l + len - 1);
			if(r >= n) break;
			rep(i, l+1, r){
				if(a[l][i] == 0) continue;
				dp[l][r] += dp2[l][i] * dp[i][r] % mod, dp[l][r] %= mod;
			}
		}
	}
	cout << dp[0][n-1] << endl;

	return 0;
}