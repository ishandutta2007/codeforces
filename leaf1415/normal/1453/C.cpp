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

ll T;
ll n;
ll a[2005][2005];
ll ans[10];
ll u[10], d[10], l[10], r[10];

void calc()
{
	rep(i, 0, 9) u[i] = inf, d[i] = -inf;
	rep(y, 1, n) rep(x, 1, n){
		chmin(u[a[x][y]], y);
		chmax(d[a[x][y]], y);
	}
	
	rep(y, 1, n){
		rep(i, 0, 9) l[i] = inf, r[i] = -inf;
		rep(x, 1, n){
			chmin(l[a[x][y]], x);
			chmax(r[a[x][y]], x);
		}
		rep(i, 0, 9){
			//cout << y << " " << i << " " << l[i] << " " << r[i] << endl;
			if(l[i] > inf/2) continue;
			chmax(ans[i], (r[i]-l[i])*max(y-1, n-y));
			chmax(ans[i], max(n-l[i], r[i]-1)*max(d[i]-y, y-u[i]));
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	while(T--){
		cin >> n;
		char c;
		rep(y, 1, n) rep(x, 1, n) cin >> c, a[x][y] = c-'0';
		
		rep(i, 0, 9) ans[i] = 0;
		
		calc();
		rep(x, 1, n){
			rep(y, 1, n){
				if(x > y) continue;
				swap(a[x][y], a[y][x]);
			}
		}
		calc();
		
		/*rep(y, 1, n){
			rep(x, 1, n) cout << a[x][y]; cout << endl;
		}*/
		
		rep(i, 0, 9) cout << ans[i] << " "; cout << endl;
	}
	
	return 0;
}