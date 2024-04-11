#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <algorithm>
#include <vector>
#include <list>
#define llint long long
#define inf 1e18

using namespace std;
typedef pair<llint, llint> P;

llint n;
vector<llint> G[500005];
llint l[500005], r[500005];
list<P> ls;

void dfs(int v, int p, list<P>::iterator it)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		auto it2 = it;
		it2 = ls.insert(it2, P(G[v][i], 0));
		it2++; it2++;
		it2 = ls.insert(it2, P(G[v][i], 1));
		it2--; it2--;
		dfs(G[v][i], v, it2);
	}
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
	ls.push_back(P(1, 0));
	ls.push_back(P(1, 1));
	auto it = ls.begin();
	dfs(1, -1, it);
	
	llint cnt = 1;
	for(auto it = ls.begin(); it != ls.end(); it++){
		if(it->second == 0) l[it->first] = cnt;
		else r[it->first] = cnt;
		cnt++;
	}
	for(int i = 1; i <= n; i++) cout << l[i] << " " << r[i] << "\n";
	flush(cout);
	
	return 0;
}