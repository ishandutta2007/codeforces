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
P a[105];
ll t[105], d[105], p[105];
ll dp[105][2005], rec[105][2005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n){
		cin >> t[i] >> d[i] >> p[i], d[i]--;
		a[i] = P(d[i], i);
	}
	sort(a+1, a+n+1);
	
	rep(i, 0, n) rep(j, 0, 2000) dp[i][j] = inf;
	dp[0][0] = 0;
	
	rep(i, 0, n-1){
		ll id = a[i+1].second;
		rep(j, 0, 2000){
			if(dp[i+1][j] > dp[i][j]){
				dp[i+1][j] = dp[i][j];
				rec[i+1][j] = j;
			}
			if(dp[i][j]+t[id] <= d[id] && j+p[id] <= 2000){
				if(dp[i+1][j+p[id]] > dp[i][j] + t[id]){
					dp[i+1][j+p[id]] = dp[i][j] + t[id];
					rec[i+1][j+p[id]] = j;
				}
			}
		}
	}
	
	ll J;
	for(int i = 2000; i >= 0; i--){
		if(dp[n][i] < inf/2){
			J = i;
			break;
		}
	}
	cout << J << endl;
	
	vector<ll> ans;
	for(int i = n; i >= 1; i--){
		if(J > rec[i][J]) ans.push_back(a[i].second);
		J = rec[i][J];
	}
	cout << ans.size() << endl;
	reverse(all(ans));
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}