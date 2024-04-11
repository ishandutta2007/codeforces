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

ll h, w, k;
ll a[105][105];

ll calc(ll x, ll y)
{
	ll ret = 0;
	rep(i, 0, k-1){
		if(y+i > h) break;
		ret += a[x][y+i];
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w >> k;
	rep(y, 1, h) rep(x, 1, w) cin >> a[x][y];
	
	ll ans = 0, cnt = 0;
	rep(x, 1, w){
		ll mx = -1, mx_id, id = 0;
		rep(y, 1, h){
			if(a[x][y] == 0) continue;
			ll res = calc(x, y);
			if(mx < res) mx = res, mx_id = id;
			id++;
		}
		if(mx >= 1) ans += mx, cnt += mx_id;
	}
	cout << ans << " " << cnt << endl;
	
	return 0;
}