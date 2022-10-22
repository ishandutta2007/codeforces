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

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

llint n, m;
llint a[500005];
llint b[500005];
bool fix[500005];
bool used[500005];
llint dp[500005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, n) cin >> a[i], a[i] -= i;
	rep(i, 1, m) cin >> b[i], fix[b[i]] = true;
	
	rep(i, 2, m){
		if(a[b[i-1]] > a[b[i]]){
			cout << -1 << endl;
			return 0;
		}
	}
	
	llint l = -inf;
	rep(i, 1, n){
		if(fix[i]){
			used[i] = true;
			l = a[i];
		}
		else{
			if(a[i] < l) used[i] = true;
		}
	}
	//for(int i = 1; i <= n; i++)  cout << used[i] << " "; cout << endl;
	
	
	llint r = inf;
	for(int i = n; i >= 1; i--){
		if(fix[i]){
			used[i] = true;
			r = a[i];
		}
		else{
			if(a[i] > r) used[i] = true;
		}
	}
	
	llint ans = 0;
	vector<llint> vec;
	for(int i = 1; i <= n; i++){
		if(used[i] && !fix[i]) ans++;
		else vec.push_back(a[i]);
	}
	
	//for(int i = 1; i <= n; i++)  cout << a[i] << " "; cout << endl;
	//cout << ans << endl;
	
	for(int i = 0; i <= n; i++) dp[i] = inf;
	dp[0] = -inf;
	
	for(int i = 0; i < vec.size(); i++){
		llint p = upper_bound(dp, dp+n+1, vec[i]) - dp;
		dp[p] = vec[i];
	}
	ans += (int)vec.size() - (lower_bound(dp, dp+n+1, inf/2) - dp - 1);
	cout << ans << endl;
	
	return 0;
}