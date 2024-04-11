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
llint n, k;
vector<llint> G[200005], vec[200005];
llint deg[200005];
bool used[200005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int z = 0; z < T; z++){
		cin >> n >> k;
		for(int i = 1; i <= n; i++){
			used[i] = false;
			deg[i] = 0;
			G[i].clear();
			vec[i].clear();
		}
		llint u, v;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
			deg[u]++, deg[v]++;
		}
		
		for(int i = 1; i <= n; i++){
			if(G[i].size() == 1) vec[G[i][0]].push_back(i);
		}
		
		priority_queue<P> Q;
		for(int i = 1; i <= n; i++){
			Q.push(P(vec[i].size(), i));
		}
		
		llint ans = 0;
		while(Q.size() > 0){
			llint l = Q.top().first, v = Q.top().second;
			//cout << v << " " << l << endl;
			if(l < k) break;
			Q.pop();
			if(used[v] || l != vec[v].size()) continue;
			for(int i = 0; i < k; i++){
				llint u = vec[v].back();
				used[u] = true;
				deg[v]--;
				vec[v].pop_back();
			}
			ans++;
			
			if(deg[v] == 0) used[v] = true;
			if(deg[v] == 1){
				for(int i = 0; i < G[v].size(); i++){
					llint u = G[v][i];
					if(used[u]) continue;
					vec[u].push_back(v);
					Q.push(P(vec[u].size(), u));
				}
			}
			Q.push(P(vec[v].size(), v));
		}
		cout << ans << endl;
		
	}
	
	return 0;
}