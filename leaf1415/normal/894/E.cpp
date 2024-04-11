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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

ll n, m, s;
ll u[1000005], v[1000005], w[1000005];
vector<ll> G[1000005], revG[1000005];
vector<P> g[1000005];
vector<int> topo;
bool used[1000005];
int scc[1000005];
ll sum[1000005], dp[1000005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}
void tpsort2(int v)
{
	used[v] = true;
	for(int i = 0; i < g[v].size(); i++){
		if(!used[g[v][i].first]) tpsort2(g[v][i].first);
	}
	topo.push_back(v);
}
void sccdfs(int v, int id)
{
	used[v] = true;
	scc[v] = id;
	for(int i = 0; i < revG[v].size(); i++){
		if(!used[revG[v][i]]) sccdfs(revG[v][i], id);
	}
}

ll calc(ll x)
{
	ll ub = 1e6, lb = 0, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(mid*(mid+1)/2 <= x) lb = mid;
		else ub = mid;
	}
	
	ll n = lb, ans = x * (n+1);
	ans -= (n*(n+1)*(2*n+1)/6 + n*(n+1)/2) / 2;
	return ans;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	rep(i, 1, m){
		cin >> u[i] >> v[i] >> w[i];
		G[u[i]].push_back(v[i]);
		revG[v[i]].push_back(u[i]);
	}
	cin >> s;
	
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	int id = 1;
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++) if(!used[topo[i]]) sccdfs(topo[i], id++);
	ll c = id-1;
	
	rep(i, 1, m){
		if(scc[u[i]] == scc[v[i]]) sum[scc[u[i]]] += calc(w[i]);
		else g[scc[u[i]]].push_back(P(scc[v[i]], w[i]));
	}
	
	topo.clear();
	for(int i = 1; i <= c; i++) used[i] = false;
	for(int i = 1; i <= c; i++) if(!used[i]) tpsort2(i);
	reverse(topo.begin(), topo.end());
	
	rep(i, 1, c) dp[i] = -inf;
	dp[scc[s]] = sum[scc[s]];
	for(auto v : topo){
		for(auto p : g[v]){
			ll u = p.first, w = p.second;
			chmax(dp[u], dp[v] + w + sum[u]);
		}
	}
	
	ll ans = 0;
	rep(i, 1, c) chmax(ans, dp[i]);
	cout << ans << endl;
	
	return 0;
}