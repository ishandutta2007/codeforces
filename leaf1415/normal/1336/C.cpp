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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<llint, llint> P;

string s, t;
string revs;
llint dp[3005][3005];
llint dp2[3005][3005];

llint modpow(llint a, llint n)
{
	if(n == 0) return 1;
	if(n % 2){
		return ((a%mod) * (modpow(a, n-1)%mod)) % mod;
	}
	else{
		return modpow((a*a)%mod, n/2) % mod;
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s >> t;
	llint S = s.size(), T = t.size();
	
	revs = s;
	reverse(revs.begin(), revs.end());
	revs = "#" + revs;
	
	llint ans = 0;
	for(int i = 0; i <= S; i++) dp[i][0] = 1;
	for(int i = 0; i < S; i++){
		for(int j = 0; j <= T; j++){
			if(j < T && revs[i+1] == t[j]){
				dp[i+1][j+1] += dp[i][j];
				dp[i+1][j+1] %= mod;
				if(j+1 == T){
					ans += modpow(2, S-(i+1)) * dp[i][j] % mod;
					ans %= mod;
				}
			}
			dp[i+1][j] += dp[i][j];
			dp[i+1][j] %= mod;
			
		}
	}
	
	/*bool flag = true;
	for(int i = 0; i < T; i++){
		if(s[i] != t[i]) flag = false;
	}
	if(flag){
		ans += modpow(2, S-T), ans %= mod;
	}*/
	
	//llint ans = 0;
	s = "#" + s, t = "#" + t;
	for(int i = 0; i < T; i++) dp2[i][i+1] = 1;
	//ans += dp[S][T];
	
	for(int i = T; i >= 0; i--){
		for(int j = 0; j <= T; j++){
			llint p = j-i-1;
			if(i >= 1 && s[p+1] == t[i]){
				dp2[i-1][j] += dp2[i][j];
				dp2[i-1][j] %= mod;
			}
			if(j <= T && s[p+1] == t[j]){
				dp2[i][j+1] += dp2[i][j];
				dp2[i][j+1] %= mod;
				if(j+1 == T+1){
					//cout << i << " " << j << " " << dp2[i][j] << " " << dp[S-(p+1)][i] << endl;
					if(S-(p+1) >= 0) ans += dp2[i][j] * dp[S-(p+1)][i] % mod;
					else ans += dp2[i][j];
					ans %= mod;
				}
			}
		}
	}
	
	/*for(int i = 0; i <= S; i++){
		for(int j = 0; j <= T; j++){
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for(int i = 0; i <= T+1; i++){
		for(int j = 0; j <= T+1; j++){
			cout << dp2[i][j] << " ";
		}
		cout << endl;
	}*/
	
	/*llint ans = 0;
	for(int i = 0; i <= T; i++){
		llint p = (T+1)-i-1;
		cout << dp2[i][T+1] << " " << dp[S-(p+1)][i] << endl;
		if(S-(p+1) >= 0) ans += dp2[i][T+1] * dp[S-(p+1)][i] % mod;
		else ans += dp2[i][T+1];
		ans %= mod;
	}*/
	cout << ans << endl;
	
	return 0;
}