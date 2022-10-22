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

ll n, Q, c;
ll sum[15][105][105];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q >> c;
	c++;
	
	ll x, y, s;
	rep(i, 1, n){
		cin >> x >> y >> s;
		sum[s][x][y]++;
	}
	
	rep(i, 0, c-1){
		rep(y, 1, 100){
			rep(x, 1, 100){
				sum[i][x][y] += sum[i][x-1][y] + sum[i][x][y-1] - sum[i][x-1][y-1];
			}
		}
	}
	
	ll t, sx, sy, tx, ty;
	rep(i, 1, Q){
		cin >> t >> sx >> sy >> tx >> ty;
		ll ans = 0;
		rep(i, 0, c-1){
			ll tmp = sum[i][tx][ty] - sum[i][sx-1][ty] - sum[i][tx][sy-1] + sum[i][sx-1][sy-1];
			ans += (t + i) % c * tmp;
		}
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}