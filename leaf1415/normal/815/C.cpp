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
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, b;
ll c[5005], d[5005];
ll num[5005];
vector<int> G[5005];
ll dp[5005][5005][2];
ll dp2[2][5005][2];

void dfs(int v)
{
	for(auto u : G[v]) dfs(u);
	
	ll sum = 0, deg = G[v].size();
	dp2[0][0][0] = 0;
	rep(i, 0, deg-1){
		int u = G[v][i];
		rep(j, 0, sum+num[u]) rep(k, 0, 1) dp2[(i+1)&1][j][k] = inf;
		rep(j, 0, sum){
			rep(k, 0, 1){
				rep(l, 0, num[u]){
					rep(m, 0, 1){
						chmin(dp2[(i+1)&1][j+l][k|m], dp2[i&1][j][k] + dp[u][l][m]);
					}
				}
			}
		}
		sum += num[u];
	}
	rep(j, 0, n) rep(k, 0, 1) dp[v][j][k] = inf;
	rep(j, 0, sum){
		rep(k, 0, 1){
			chmin(dp[v][j+1][1], dp2[deg&1][j][k] + c[v]-d[v]);
			if(k == 0){
				chmin(dp[v][j][k], dp2[deg&1][j][k]);
				chmin(dp[v][j+1][k], dp2[deg&1][j][k] + c[v]);
			}
		}
	}
	num[v] = sum+1;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> b;
	rep(i, 1, n){
		ll p;
		cin >> c[i] >> d[i];
		if(i >= 2){
			cin >> p;
			G[p].push_back(i);
		}
	}
	dfs(1);
	
	ll ans = 0;
	rep(j, 0, n) rep(k, 0, 1) if(dp[1][j][k] <= b) chmax(ans, j);
	cout << ans << endl;
	
	return 0;
}