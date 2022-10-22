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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n;
string s;
ll dp[100005][3][2];
P rec[100005][3][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	
	rep(i, 0, n) rep(j, 0, 2) rep(k, 0, 1) dp[i][j][k] = -inf;
	dp[0][0][0] = 0;
	
	rep(i, 0, n-1){
		ll c = s[i] - '0';
		rep(j, 0, 2){
			rep(k, 0, 1){
				if(dp[i+1][j][k] < dp[i][j][k]){
					dp[i+1][j][k] = dp[i][j][k];
					rec[i+1][j][k] = P(j, k);
				}
				ll nk = k;
				if(c > 0) nk = 1;
				if(c == 0 && k == 0) continue;
				if(dp[i+1][(j+c)%3][nk] < dp[i][j][k] + 1){
					dp[i+1][(j+c)%3][nk] = dp[i][j][k] + 1;
					rec[i+1][(j+c)%3][nk] = P(j, k);
				}
			}
		}
	}
	
	if(dp[n][0][1] <= 0){
		for(auto c : s){
			if(c == '0'){
				cout << 0 << endl;
				return 0;
			}
		}
		cout << -1 << endl;
		return 0;
	}
	
	string ans; ll J = 0, K = 1;
	for(int i = n; i >= 1; i--){
		ll NJ = rec[i][J][K].first, NK = rec[i][J][K].second;
		if(dp[i-1][NJ][NK] < dp[i][J][K]) ans += s[i-1];
		J = NJ, K = NK;
	}
	reverse(all(ans));
	cout << ans << endl;
	
	return 0;
}