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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
vector<llint> G[200005], revG[200005];
vector<int> topo;
bool used[200005], used2[200005];
bool univ[200005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

void dfs(vector<llint> G[], int v, bool used[])
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) dfs(G, G[v][i], used);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m;
	llint u, v;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		G[u].push_back(v);
		revG[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
	reverse(topo.begin(), topo.end());
	
	for(int i = 1; i <= n; i++) used[i] = false;
	for(int i = 0; i < topo.size(); i++){
		int v = topo[i];
		used[v] = true;
		for(int j = 0; j < G[v].size(); j++){
			if(used[G[v][j]]){
				cout << -1 << endl;
				return 0;
			}
		}
	}
	
	llint ans = 0;
	for(int i = 1; i <= n; i++) used[i] = used2[i] = false;
	for(int i = 1; i <= n; i++){
		if(!used[i] && !used2[i]) ans++, univ[i] = true;
		dfs(G, i, used);
		dfs(revG, i, used2);
	}
	
	cout << ans << endl;
	for(int i = 1; i <= n; i++){
		if(univ[i]) cout << "A";
		else cout << "E";
	}
	cout << endl;
	
	return 0;
}