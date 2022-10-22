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

struct edge{
	ll to, id;
	edge(){}
	edge(ll a, ll b){
		to = a, id = b;
	}
};

ll n, k, d;
ll p[300005];
vector<edge> G[300005];
ll dist[300005];
bool used[300005];

void bfs(vector<edge> G[], int S, llint dist[])
{
	queue<int> Q;
	Q.push(S);
	
	for(int i = 1; i <= n+1; i++) dist[i] = inf;
	dist[S] = 0;
	
	while(Q.size()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < G[v].size(); i++){
			ll u = G[v][i].to;
			if(dist[u] < inf/2) continue;
			used[G[v][i].id] = true;
			Q.push(u);
			dist[u] = dist[v] + 1;
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k >> d;
	rep(i, 1, k) cin >> p[i];
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
	}
	rep(i, 1, k) G[n+1].push_back(edge(p[i], 0));
	
	bfs(G, n+1, dist);
	
	vector<ll> ans;
	rep(i, 1, n-1) if(!used[i]) ans.push_back(i);
	
	cout << ans.size() << endl;
	for(auto x : ans) cout << x << " "; cout << endl;
	
	return 0;
}