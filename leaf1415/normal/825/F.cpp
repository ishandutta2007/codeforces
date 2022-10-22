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
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n;
string s;
bool same[8005][8005];
int times[8005][8005];
ll keta[8005];
ll dp[8005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> s;
	n = s.size();
	s = "#" + s;
	
	rep(i, 1, 8000) keta[i] = keta[i/10] + 1;
	
	rep(len, 1, n){
		ll cnt = 0;
		for(int l = n-len; l >= 1; l--){
			ll r = l+len;
			if(s[l] == s[r]) cnt++;
			else cnt = 0;
			if(cnt >= len) same[l][r-1] = true;
		}
	}
	for(int r = n; r >= 1; r--){
		rep(l, 1, r){
			if(same[l][r]) times[l][r] = times[r+1][r+r-l+1] + 1;
			else times[l][r] = 1;
		}
	}
	
	/*rep(i, 1, n){
		rep(j, 1, n){
			cout << times[i][j] << " ";
		}
		cout << endl;
	}*/
	
	rep(i, 0, n) dp[i] = inf;
	dp[0] = 0;
	
	rep(i, 0, n-1){
		rep(r, i+1, n){
			int mul = 1, t = times[i+1][r], len = r-i;
			rep(k, 1, t){
				chmin(dp[i+k*len], dp[i] + keta[k] + len);
			}
		}
	}
	cout << dp[n] << endl;
	
	return 0;
}