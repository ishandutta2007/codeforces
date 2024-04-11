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

ll h, w, k, Q;
ll a[505][505];
ll dp[505][505];

bool check(ll t)
{
	rep(y, 1, h){
		rep(x, 1, w){
			if(a[x][y] > t) dp[x][y] = 0;
			else dp[x][y] = min(dp[x-1][y], min(dp[x][y-1], dp[x-1][y-1])) + 1;
			if(dp[x][y] >= k) return true;
		}
	}
	return false;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k >> Q;
	rep(y, 0, h) rep(x, 0, w) a[x][y] = inf;
	
	ll x, y, t;
	rep(i, 1, Q){
		cin >> y >> x >> t;
		a[x][y] = t;
	}
	
	ll ub = 1e9+7, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	if(ub > 1e9+3) ub = -1;
	cout << ub << endl;
	
	return 0;
}