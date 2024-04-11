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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << (x) << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h, w;
ll a[105][105], b[105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(i, 1, h) rep(j, 1, w) cin >> a[i][j];
	
	ll ans = inf, ans_i;
	rep(i, 0, 500){
		ll cnt = 0;
		rep(j, 1, h) rep(k, 1, w) b[j][k] = 0;
		
		bool flag = true;
		rep(j, 1, w) b[1][j] += i; cnt += i;
		rep(j, 1, w){
			ll x = a[1][j]-b[1][j];
			if(x < 0) flag = false;
			rep(k, 1, h) b[k][j] += x; cnt += x;
		}
		rep(j, 2, h){
			ll x = a[j][1]-b[j][1];
			if(x < 0) flag = false;
			rep(k, 1, w) b[j][k] += x; cnt += x;
		}
		rep(j, 1, h) rep(k, 1, w) if(a[j][k] != b[j][k]) flag = false;
		if(flag){
			if(ans > cnt) ans = cnt, ans_i = i;
		}
	}
	
	if(ans > inf/2){
		cout << -1 << endl;
		return 0;
	}
	
	cout << ans << endl;
	rep(j, 1, h) rep(k, 1, w) b[j][k] = 0;
		
	rep(j, 1, w) b[1][j] += ans_i;
	rep(j, 1, ans_i) cout << "row " << 1 << endl;
	
	rep(j, 1, w){
		ll x = a[1][j]-b[1][j];
		rep(k, 1, h) b[k][j] += x;
		rep(k, 1, x) cout << "col " << j << endl;
	}
	rep(j, 2, h){
		ll x = a[j][1]-b[j][1];
		rep(k, 1, w) b[j][k] += x;
		rep(k, 1, x) cout << "row " << j << endl;
	}
	
	return 0;
}