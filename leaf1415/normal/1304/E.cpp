#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define llint long long

using namespace std;

llint n, Q;
vector<llint> G[100005];

int Prev[100005][17];
int depth[100005];

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
	
	for(int i = 16; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 16; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

llint getDist(llint u, llint v)
{
	llint lca = getLCA(u, v);
	return depth[u]+depth[v]-2*depth[lca];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	predfs(1, 0, 0);
	for(int i = 1; i < 17; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	cin >> Q;
	llint x, y, a, b, k;
	for(int q = 0; q < Q; q++){
		cin >> x >> y >> a >> b >> k;
		llint d = getDist(a, b);
		if(d <= k && d % 2 == k % 2){
			cout << "YES" << "\n";
			continue;
		}
		d = getDist(x, a) + getDist(y, b) + 1;
		if(d <= k && d % 2 == k % 2){
			cout << "YES" << "\n";
			continue;
		}
		d = getDist(x, b) + getDist(y, a) + 1;
		if(d <= k && d % 2 == k % 2){
			cout << "YES" << "\n";
			continue;
		}
		cout << "NO" << "\n";
	}
	flush(cout);
	
	return 0;
}