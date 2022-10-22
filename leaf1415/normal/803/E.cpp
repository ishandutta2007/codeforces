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

ll n, k;
string s;
ll dp[1005][2005];
int zero = 1002;

int main(void)
{
	ios::sync_with_stdio(0);
	
	cin >> n >> k >> s;
	s = "#" + s;
	
	rep(i, 0, n) rep(j, -k, k) dp[i][zero+j] = -inf;
	dp[0][zero+0] = 0;
	
	rep(i, 0, n-1){
		rep(j, -k, k){
			rep(l, -1, 1){
				if(dp[i][zero+j] < -inf/2) continue;
				if(s[i+1] != '?'){
					if(s[i+1] != 'W' && l == 1) continue;
					if(s[i+1] != 'L' && l == -1) continue;
					if(s[i+1] != 'D' && l == 0) continue;
				}
				ll nj = j + l;
				if(abs(nj) > k) continue;
				if(i+1 != n && abs(nj) == k) continue;
				dp[i+1][zero+nj] = j;
			}
		}
	}
	ll p = -inf;
	if(dp[n][zero+k] > -inf/2) p = k;
	if(dp[n][zero-k] > -inf/2) p = -k;
	if(p < -inf/2){
		cout << "NO" << endl;
		return 0;
	}
	
	/*rep(i, 0, n){
		rep(j, -k, k) cout << dp[i][zero+j] << " ";
		cout << endl;
	}*/
	
	for(int i = n; i >= 1; i--){
		if(dp[i][zero+p] == p) s[i] = 'D';
		if(dp[i][zero+p] < p) s[i] = 'W';
		if(dp[i][zero+p] > p) s[i] = 'L';
		p = dp[i][zero+p];
	}
	cout << s.substr(1) << endl;
	
	return 0;
}