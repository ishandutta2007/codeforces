#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
llint s[5005], t[5005];
llint a[5005], b[5005], g[5005], lca[5005];
llint mn[5005];
vector<llint> G[5005];

int Prev[5005][13];
int depth[5005];

void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);
	
	for(int i = 12; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 12; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i < n; i++){
		cin >> s[i] >> t[i];
		G[s[i]].push_back(t[i]);
		G[t[i]].push_back(s[i]);
	}
	cin >> m;
	for(int i = 1; i <= m; i++) cin >> a[i] >> b[i] >> g[i];
	
	predfs(1, 0, 0);
	for(int i = 1; i < 13; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	for(int i = 1; i <= n; i++) mn[i] = 1;
	for(int i = 1; i <= m; i++){
		lca[i] = getLCA(a[i], b[i]);
		llint p = a[i];
		while(p != lca[i]){
			mn[p] = max(mn[p], g[i]);
			p = Prev[p][0];
		}
		p = b[i];
		while(p != lca[i]){
			mn[p] = max(mn[p], g[i]);
			p = Prev[p][0];
		}
	}
	
	for(int i = 1; i <= m; i++){
		llint x = inf;
		llint p = a[i];
		while(p != lca[i]){
			x = min(x, mn[p]);
			p = Prev[p][0];
		}
		p = b[i];
		while(p != lca[i]){
			x = min(x, mn[p]);
			p = Prev[p][0];
		}
		if(x != g[i]){
			cout << -1 << endl;
			return 0;
		}
	}
	//for(int i = 1; i <= n; i++)  cout << mn[i] << " "; cout << endl;
	
	for(int i = 1; i <= n-1; i++){
		if(Prev[s[i]][0] == t[i]) cout << mn[s[i]] << " ";
		else cout << mn[t[i]] << " ";
	}
	cout << endl;
	
	return 0;
}