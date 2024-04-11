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
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h, w;
char c[20][200];
ll l[25], r[25];
ll dp[25][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	for(int i = h; i >= 1; i--) rep(j, 0, w+1) cin >> c[i][j];
	
	ll H = 0;
	rep(i, 1, h){
		l[i] = w+1, r[i] = 0;
		rep(j, 1, w) if(c[i][j] == '1') H = i, chmin(l[i], j), chmax(r[i], j);
	}
	h = H;
	
	if(h == 0){
		cout << 0 << endl;
		return 0;
	}
	
	rep(i, 0, h){
		rep(j, 0, 1){
			dp[i][j] = inf;
		}
	}
	dp[0][0] = 0;
	
	//rep(i, 1, h) cout << l[i] << " " << r[i] << endl;
	
	rep(i, 0, h-1){
		rep(j, 0, 1){
			ll cost = 0, pos;
			if(j == 0) cost += r[i+1], pos = r[i+1];
			else cost += w+1 - l[i+1], pos = l[i+1];
			rep(k, 0, 1){
				ll ncost = cost;
				if(i+1 < h){
					if(k == 0) ncost += pos;
					else ncost += w+1 - pos;
				}
				chmin(dp[i+1][k], dp[i][j] + ncost + 1);
			}
		}
	}
	cout << min(dp[h][0], dp[h][1]) - 1 << endl;
	
	return 0;
}