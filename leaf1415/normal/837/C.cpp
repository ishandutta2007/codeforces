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

ll n, h, w;
ll x[105], y[105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> h >> w;
	rep(i, 1, n) cin >> x[i] >> y[i];
	
	ll ans = 0;
	rep(i, 1, n) rep(j, 1, n){
		if(i >= j) continue;
		
		if(x[i]+x[j] <= w && max(y[i], y[j]) <= h) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(x[i]+y[j] <= w && max(y[i], x[j]) <= h) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(y[i]+x[j] <= w && max(x[i], y[j]) <= h) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(y[i]+y[j] <= w && max(x[i], x[j]) <= h) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		
		if(x[i]+x[j] <= h && max(y[i], y[j]) <= w) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(x[i]+y[j] <= h && max(y[i], x[j]) <= w) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(y[i]+x[j] <= h && max(x[i], y[j]) <= w) chmax(ans, x[i]*y[i] + x[j]*y[j]);
		if(y[i]+y[j] <= h && max(x[i], x[j]) <= w) chmax(ans, x[i]*y[i] + x[j]*y[j]);
	}
	cout << ans << endl;
	
	return 0;
}