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

llint T;
llint n, m;
vector<llint> G[200005];
llint t[200005], u[200005], v[200005];
vector<int> topo;
bool used[200005];
llint pos[200005];

void tpsort(int v)
{
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(!used[G[v][i]]) tpsort(G[v][i]);
	}
	topo.push_back(v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) G[i].clear();
		for(int i = 1; i <= m; i++){
			cin >> t[i] >> u[i] >> v[i];
			if(t[i] == 1) G[u[i]].push_back(v[i]);
		}
		
		topo.clear();
		for(int i = 1; i <= n; i++) used[i] = false;
		for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
		reverse(topo.begin(), topo.end());
		for(int i = 0; i < topo.size(); i++) pos[topo[i]] = i;
		
		vector<P> ans;
		for(int i = 1; i <= m; i++){
			if(t[i] == 1){
				if(pos[u[i]] > pos[v[i]]){
					cout << "NO" << endl;
					goto end;
				}
				ans.push_back(P(u[i], v[i]));
			}
			else{
				if(pos[u[i]] > pos[v[i]]) swap(u[i], v[i]);
				ans.push_back(P(u[i], v[i]));
			}
		}
		cout << "YES" << endl;
		for(int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
		end:;
	}
	
	return 0;
}