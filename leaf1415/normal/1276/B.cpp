#include <iostream>
#include <string>
#include <vector>
#include <utility>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m, a, b;
vector<llint> G[200005];
bool used[200005], used2[200005];

void dfs(llint v, llint p, llint t, bool used[])
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p || G[v][i] == t) continue;
		if(used[G[v][i]]) continue;
		dfs(G[v][i], v, t, used);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m >> a >> b;
		for(int i = 1; i <= n; i++) G[i].clear();
		llint u, v;
		for(int i = 1; i <= m; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		for(int i = 1; i <= n; i++) used[i] = used2[i] = false;
		dfs(a, -1, b, used);
		dfs(b, -1, a, used2);
		
		llint cnt = 0, cnt2 = 0;
		for(int i = 1; i <= n; i++){
			if(!used[i]) cnt++;
			if(!used2[i]) cnt2++;
		}
		//cout << cnt << " " << cnt2 << endl;
		cnt--, cnt2--;
		cout << cnt * cnt2 << endl;
	}
	
	return 0;
}