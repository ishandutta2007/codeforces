#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
	int id, f, s;
	ll cost;
	bool operator < (const edge &o) const{
		return cost < o.cost;
	}
}e[200200];
int n, m, par[200200], to[200200][20], lev[200200];
ll ans, out[200200], val[200200][20];
vector<pair<int,ll>> v[200200];

int f(int a){
	if(a == par[a]) return a;
	return par[a] = f(par[a]);
}

void dfs(int cur, int par){
	lev[cur] = lev[par] + 1;
	for(auto nxt : v[cur]) if(nxt.first != par){
		to[nxt.first][0] = cur;
		val[nxt.first][0] = nxt.second;
		dfs(nxt.first, cur);
	}
}

ll lca(int a, int b){
	ll re = 0;
	if(lev[a] < lev[b]) swap(a, b);
	for(int i=0;i<=18;i++) if((1<<i) & (lev[a]-lev[b])) re = max(re, val[a][i]), a = to[a][i];
	if(a == b) return re;
	for(int i=18;i>=0;i--) if(to[a][i] != to[b][i]) re = max({re, val[a][i], val[b][i]}), a = to[a][i], b = to[b][i];
	return max({re, val[a][0], val[b][0]});
}

int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=m;i++){
		cin >> e[i].f >> e[i].s >> e[i].cost;
		if(e[i].f > e[i].s) swap(e[i].f, e[i].s);
		e[i].id = i;
	}

	for(int i=1;i<=n;i++) par[i] = i;
	sort(e+1, e+1+m);
	for(int i=1;i<=m;i++){
		int a = f(e[i].f), b = f(e[i].s);
		if(a != b){
			par[a] = b;
			ans += e[i].cost;
			v[e[i].f].push_back({e[i].s, e[i].cost});
			v[e[i].s].push_back({e[i].f, e[i].cost});
		}
	}

	dfs(1, 0);
	for(int j=1;j<=18;j++) for(int i=1;i<=n;i++) val[i][j] = max(val[i][j-1], val[to[i][j-1]][j-1]), to[i][j] = to[to[i][j-1]][j-1];

	for(int i=1;i<=m;i++) out[e[i].id] = ans + e[i].cost - lca(e[i].f, e[i].s);
	for(int i=1;i<=m;i++) cout << out[i] << '\n';
}