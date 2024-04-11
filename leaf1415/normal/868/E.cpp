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
#define inf 1e9

using namespace std;

typedef int llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct edge{
	int to, cost;
	edge(){}
	edge(int a, int b){
		to = a, cost = b;
	}
};

ll n, s, m;
int x[55];
vector<edge> G[55];
int parent[55];
int dp[55][55][55], dp2[55][55][55];
int tdp[55][55];
int sum[55];

int &at(int u, int v, int a, int b)
{
	if(parent[u] == v) return dp2[u][a][b];
	else return dp[v][a][b];
}

void dfs(int v, int p, int x)
{
	vector<edge> vec;
	parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i].to;
		if(u == p) continue;
		dfs(u, v, x);
		vec.push_back(G[v][i]);
	}
	int d = vec.size();
	if(d == 0){
		rep(j, 1, x){
			if(x == j) at(p, v, x, j) = 0;
			else at(p, v, x, j) = at(v, p, x-j, x-j) + G[v][0].cost;
		}
		return;
	}
	
	rep(j, 0, d){
		rep(k, 0, x){
			tdp[j][k] = -inf;
		}
	}
	tdp[0][0] = inf;
	
	rep(j, 0, d-1){
		int u = vec[j].to, c = vec[j].cost;
		rep(k, 0, x){
			chmax(tdp[j+1][k], tdp[j][k]);
			rep(l, 1, x){
				if(k+l <= x) chmax(tdp[j+1][k+l], min(tdp[j][k], at(v, u, x, l) + c));
			}
		}
	}
	rep(j, 1, x) at(p, v, x, j) = tdp[d][j];
}

void dfs2(int v, int p, int x)
{
	if(p == 0 && G[v].size() == 1){
		int u = G[v][0].to;
		rep(j, 1, x){
			if(x == j) at(u, v, x, j) = 0;
			else at(u, v, x, j) = at(v, u, x-j, x-j) + G[v][0].cost;
		}
	}
	else{
		for(int z = 0; z < G[v].size(); z++){
			int u = G[v][z].to;
			if(u == p) continue;
			
			vector<edge> vec;
			for(int i = 0; i < G[v].size(); i++){
				if(i == z) continue;
				vec.push_back(G[v][i]);
			}
			int d = vec.size();
			
			rep(j, 0, d){
				rep(k, 0, x){
					tdp[j][k] = -inf;
				}
			}
			tdp[0][0] = inf;
			
			rep(j, 0, d-1){
				int u = vec[j].to, c = vec[j].cost;
				rep(k, 0, x){
					chmax(tdp[j+1][k], tdp[j][k]);
					rep(l, 1, x){
						if(k+l <= x) chmax(tdp[j+1][k+l], min(tdp[j][k], at(v, u, x, l) + c));
					}
				}
			}
			rep(j, 1, x) at(u, v, x, j) = tdp[d][j];
		}
	}
	
	for(auto e : G[v]){
		if(e.to == p) continue;
		dfs2(e.to, v, x);
	}
}

void sumdfs(int v, int p)
{
	for(auto e : G[v]){
		if(e.to == p) continue;
		sumdfs(e.to, v);
		sum[v] += sum[e.to];
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v, w;
	rep(i, 1, n-1){
		cin >> u >> v >> w;
		G[u].push_back(edge(v, w));
		G[v].push_back(edge(u, w));
	}
	cin >> s >> m;
	rep(i, 1, m) cin >> x[i], sum[x[i]]++;
	
	if(n == 2){
		cout << G[1][0].cost << endl;
		return 0;
	}
	
	rep(i, 1, m) dfs(1, 0, i), dfs2(1, 0, i);
	sumdfs(s, 0);
	
	/*rep(i, 1, n){
		for(auto e : G[i]){
			rep(j, 1, m){
				rep(k, 1, j) cout << i << " " << e.to << " " << j << " " << k << " " << at(i, e.to, j, k) << endl;
			}
		}
	}*/
	
	int ans = inf;
	for(auto e : G[s]){
		if(sum[e.to]) chmin(ans, at(s, e.to, m, sum[e.to]) + e.cost);
	}
	cout << ans << endl;
	
	return 0;
}