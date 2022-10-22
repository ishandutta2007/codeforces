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
#define outl(x) cout << (x) << endl
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll h, w;
char c[255][255];
ll dp[2][15][1<<15][2][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> h >> w;
	rep(y, 1, h){
		rep(x, 1, w){
			cin >> c[x][y];
		}
	}
	if(h > w){
		rep(y, 1, h) rep(x, 1, h){
			if(x > y) swap(c[x][y], c[y][x]);
		}
		swap(h, w);
	}
	
	ll H = 1<<h;
	dp[0][0][0][0][0] = 1;
	rep(i, 0, w-1){
		rep(j, 0, h-1){
			ll ni = i+(j+1)/h, nj = (j+1)%h;
			rep(k, 0, H-1) rep(l, 0, 1) rep(m, 0, 1) dp[ni%2][nj][k][l][m] = 0;
			rep(k, 0, H-1){
				rep(l, 0, 1){
					rep(m, 0, 1){
						if(c[i+1][j+1] == 'x'){
							(dp[(ni%2)][nj][k&~(1<<j)][0][m] += dp[i%2][j][k][l][m]) %= mod;
							continue;
						}
						
						if(j < h-1) (dp[(ni%2)][nj][k|(1<<j)][1][m] += dp[i%2][j][k][l][m]) %= mod;
						else (dp[(ni%2)][nj][k|(1<<j)][0][m] += dp[i%2][j][k][l][m]) %= mod;
						
						ll nl = l;
						if(j == h-1) nl = 0;
						if((k & (1<<j)) == 0 && l == 0){
							if(m == 0) (dp[(ni%2)][nj][k][nl][1] += dp[i%2][j][k][l][m]) %= mod;
						}
						else (dp[(ni%2)][nj][k][nl][m] += dp[i%2][j][k][l][m]) %= mod;
					}
				}
			}
		}
	}
	
	ll ans = 0;
	rep(k, 0, H-1) rep(m, 0, 1) ans += dp[w%2][0][k][0][m], ans %= mod;
	cout << ans << endl;
	
	return 0;
}