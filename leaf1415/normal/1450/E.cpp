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

struct edge{
	ll to, cost;
	edge(ll a, ll b){
		to = a, cost = b;
	}
};

ll n, m;
vector<edge> G[205];
ll color[205];
ll dist[205][205];
ll h[205];

bool dfs(int v, int p, int c)
{
	color[v] = c;
	for(auto e : G[v]){
		ll u = e.to;
		if(u == p) continue;
		if(color[u] == -c) continue;
		if(color[u] == c) return false;
		if(!dfs(u, v, -c)) return false;
	}
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	ll u, v, t;
	rep(i, 1, m){
		cin >> u >> v >> t;
		G[u].push_back(edge(v, 1));
		if(t == 1) G[v].push_back(edge(u, -1));
		else G[v].push_back(edge(u, 1));
	}
	if(!dfs(1, -1, 1)){
		cout << "NO" << endl;
		return 0;
	}
	
	rep(i, 1, n){
		rep(j, 1, n){
			dist[i][j] = inf;
			if(i == j) dist[i][j] = 0;
		}
	}
	
	rep(i, 1, n){
		for(auto e : G[i]){
			chmin(dist[i][e.to], e.cost);
		}
	}
	
	rep(k, 1, n){
		rep(i, 1, n){
			rep(j, 1, n){
				chmin(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
	
	ll ans = -inf, ans_i;
	rep(i, 1, n){
		rep(j, 1, n){
			if(i == j && dist[i][j] < 0){
				cout << "NO" << endl;
				return 0;
			}
			if(ans < dist[i][j]){
				ans = dist[i][j];
				ans_i = i;
			}
		}
	}
	
	cout << "YES" << endl;
	cout << ans << endl;
	rep(i, 1, n) h[i] = dist[ans_i][i];
	rep(i, 1, n) cout << h[i] << " "; cout << endl;
	
	return 0;
}