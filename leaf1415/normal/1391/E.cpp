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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;

llint T;
llint n, m;
vector<llint> G[500005];
vector<llint> vec[500005];
bool used[500005];
llint parent[500005];

llint dep, dep_v;
void dfs(int v, int p, int d)
{
	used[v] = true;
	vec[d].push_back(v);
	parent[v] = p;
	if(dep < d) dep = d, dep_v = v;
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		dfs(G[v][i], v, d+1);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) G[i].clear(), used[i] = false;
		for(int i = 0; i <= n; i++) vec[i].clear();
		
		llint u, v;
		for(int i = 1; i <= m; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		dep = -1;
		dfs(1, 0, 0);
		
		if(dep >= (n+1)/2-1){
			cout << "PATH" << endl;
			cout << dep+1 << endl;
			llint v = dep_v;
			while(v){
				cout << v << " ";
				v = parent[v];
			}
			cout << endl;
		}
		else{
			cout << "PAIRING" << endl;
			vector<P> ans;
			for(int i = 0; i <= dep; i++){
				for(int j = 1; j < vec[i].size(); j+=2){
					ans.push_back(P(vec[i][j], vec[i][j-1]));
				}
			}
			cout << ans.size() << endl;
			for(int i = 0; i < ans.size(); i++){
				cout << ans[i].first << " " << ans[i].second << endl;
			}
		}
	}
	
	return 0;
}