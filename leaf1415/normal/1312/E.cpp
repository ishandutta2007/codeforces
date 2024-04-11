#include <iostream>
#include <algorithm>
#include <set>
#define llint long long
#define mod 998244353
#define inf 1e18
#define rep(i, s, t) for(llint (i) = (s); (i) <= (t); (i)++)

using namespace std;

llint n;
llint a[505];
llint dp[505][505];
llint dp2[505];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) dp[i][i] = a[i];
	rep(len, 2, n){
		rep(l, 1, n){
			llint r = l+len-1;
			if(r > n) break;
			dp[l][r] = -1;
			rep(k, l+1, r){
				if(dp[l][k-1] != -1 && dp[l][k-1] == dp[k][r]){
					dp[l][r] = dp[l][k-1]+1;
					break;
				}
			}
		}
	}
	
	/*rep(l, 1, n){
		rep(r, 1, n){
			cout << dp[l][r] << " ";
		}
		cout << endl;
	}*/
	
	rep(i, 1, n) dp2[i] = -inf;
	rep(i, 0, n-1){
		dp2[i+1] = max(dp2[i+1], dp2[i]);
		rep(j, i+1, n){
			if(dp[i+1][j] > 0) dp2[j] = max(dp2[j], dp2[i] + j-i-1);
		}
	}
	cout << n-dp2[n] << endl;
	
	return 0;
}