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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 

ll n, p, d;
bool b[1005][2];
ll sum[1005];
ll dp[60][1005][55][2];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> d;
	ll r, x;
	rep(i, 0, 1){
		cin >> r;
		rep(j, 1, r) cin >> x, b[x][i] = true;
	}
	rep(i, 1, n){
		sum[i] = sum[i-1];
		if(b[i][0] || b[i][1]) sum[i]++;
	}
	
	rep(i, 0, n) rep(j, 0, p) rep(k, 0, d) rep(l, 0, 1) dp[i%55][j][k][l] = -inf;
	dp[0][0][0][0] = 0;
	
	rep(i, 0, n-1){
		rep(j, 0, p){
			rep(k, 0, d){
				rep(l, 0, 1){
					ll cost = 0;
					if(k > 0 && b[i+1][l]) cost = 1;
					chmax(dp[(i+1)%55][j][max(0LL, k-1)][l], dp[i%55][j][k][l] + cost);
					
					if(k == 0){
						rep(m, 0, 1){
							ll cost = 0;
							if(b[i+1][m]) cost = 1;
							if(j+1 <= p) chmax(dp[(i+1)%55][j+1][d-1][m], dp[i%55][j][k][l] + cost);
						}
						ll ni = min(n, i+d);
						if(j+2 <= p) chmax(dp[ni%55][j+2][0][0], dp[i%55][j][k][l] + sum[ni]-sum[i]);
					}
					else{
						ll ni = min(n, i+k);
						if(j+1 <= p) chmax(dp[ni%55][j+1][d-(ni-i)][1-l], dp[i%55][j][k][l] + sum[ni]-sum[i]);
					}
				}
			}
		}
		rep(j, 0, p) rep(k, 0, d) rep(l, 0, 1) dp[i%55][j][k][l] = -inf;
	}
	
	ll ans = 0;
	rep(j, 0, p) rep(k, 0, d) rep(l, 0, 1) chmax(ans, dp[n%55][j][k][l]);
	cout << ans << endl;
	
	return 0;
}