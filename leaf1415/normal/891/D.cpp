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
typedef pair<int, int> P;
typedef pair<llint, P> E;

int n, m;
vector<int> G[500005];
int parent[500005];
int dp[500005][2][2], dp2[500005][2][2];
int tdp[500005][2][2], ldp[500005][2][2], rdp[500005][2][2];

int& get(int u, int v, int i, int j)
{
	if(parent[u] == v) return dp2[u][i][j];
	return dp[v][i][j];
}

void dfs(int v, int p)
{
	parent[v] = p;
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v);
	}
	
	int d = G[v].size();
	rep(i, 0, d) rep(j, 0, 1) rep(k, 0, 1) tdp[i][j][k] = 0;
	tdp[0][0][0] = 1;
	
	rep(i, 0, d-1){
		int u = G[v][i];
		if(u == p){
			rep(j, 0, 1) rep(k, 0, 1) tdp[i+1][j][k] = tdp[i][j][k];
			continue;
		}
		rep(j, 0, 1) rep(k, 0, 1){
			rep(l, 0, 1) rep(m, 0, 1){
				if(j+l <= 1 && k+m <= 1){
					tdp[i+1][j+l][k+m] += tdp[i][j][k] * get(v, u, l, m);
				}
			}
		}
	}
	
	rep(i, 0, 1) rep(j, 0, 1) get(p, v, i, j) = tdp[d][1-i][j];
	get(p, v, 0, 1) += tdp[d][0][0];
}

void dfs2(int v, int p)
{
	int d = G[v].size();
	
	rep(i, 0, d) rep(j, 0, 1) rep(k, 0, 1) ldp[i][j][k] = 0;
	ldp[0][0][0] = 1;
	
	rep(i, 0, d-1){
		int u = G[v][i];
		rep(j, 0, 1) rep(k, 0, 1){
			rep(l, 0, 1) rep(m, 0, 1){
				if(j+l <= 1 && k+m <= 1){
					ldp[i+1][j+l][k+m] += ldp[i][j][k] * get(v, u, l, m);
				}
			}
		}
	}
	
	rep(i, 0, d) rep(j, 0, 1) rep(k, 0, 1) rdp[i][j][k] = 0;
	rdp[d][0][0] = 1;
	
	for(int i = d; i >= 1; i--){
		int u = G[v][i-1];
		rep(j, 0, 1) rep(k, 0, 1){
			rep(l, 0, 1) rep(m, 0, 1){
				if(j+l <= 1 && k+m <= 1){
					rdp[i-1][j+l][k+m] += rdp[i][j][k] * get(v, u, l, m);
				}
			}
		}
	}
	
	rep(i, 0, d-1){
		int u = G[v][i];
		if(u == p) continue;
		rep(j, 0, 1) rep(k, 0, 1){
			rep(l, 0, 1) rep(m, 0, 1){
				if(j+l >= 2 || k+m >= 2) continue;
				ll lval = ldp[i][j][k];
				ll rval = rdp[i+1][l][m];
				get(u, v, 1-(j+l), k+m) += lval * rval;
			}
		}
		get(u, v, 0, 1) += get(u, v, 1, 0);
	}
	
	for(auto u : G[v]){
		if(u == p) continue;
		dfs2(u, v);
	}
}

ll ans = 0;
ll calcdfs(int v, int p)
{
	ll ret = 1;
	for(auto u : G[v]){
		if(u == p) continue;
		ll res = calcdfs(u, v);
		ans += (ll)get(u, v, 0, 1) * (ll)get(v, u, 0, 1);
		if(get(u, v, 0, 0) * get(v, u, 0, 0)) ans += res * (n-res);
		ret += res;
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	dfs(1, 0);
	dfs2(1, 0);
	
	calcdfs(1, -1);
	cout << ans << endl;
	
	return 0;
}