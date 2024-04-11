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
llint n;
llint l[3005], r[3005];
vector<llint> G[3005];
bool sup[3005][3005];
vector<llint> comp;
vector<llint> vec[7005];
llint ans[3005], dp[6005];

vector<int> topo;
bool used[3005];

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
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) cin >> l[i] >> r[i];
		l[n+1] = -1, r[n+1] = 1000000000;
		n++;
		
		comp.clear();
		for(int i = 1; i <= n; i++){
			comp.push_back(l[i]);
			comp.push_back(r[i]);
		}
		sort(comp.begin(), comp.end());
		comp.erase(unique(comp.begin(), comp.end()), comp.end());
		for(int i = 1; i <= n; i++) l[i] = lower_bound(comp.begin(), comp.end(), l[i]) - comp.begin();
		for(int i = 1; i <= n; i++) r[i] = lower_bound(comp.begin(), comp.end(), r[i]) - comp.begin();
		
		llint m = comp.size();
		for(int i = 0; i < m; i++) vec[i].clear();
		for(int i = 1; i <= n; i++) vec[l[i]].push_back(i);
		
		for(int i = 1; i <= n; i++){
			G[i].clear();
			for(int j = 1; j <= n; j++){
				if(i == j) sup[i][j] = false;
				else{
					if(l[i] <= l[j] && r[j] <= r[i]){
						sup[i][j] = true;
						G[i].push_back(j);
					}
					else sup[i][j] = false;
				}
			}
		}
		
		topo.clear();
		for(int i = 1; i <= n; i++) used[i] = false;
		for(int i = 1; i <= n; i++) if(!used[i]) tpsort(i);
		
		for(int i = 0; i < topo.size(); i++){
			llint id = topo[i];
			for(int j = 0; j <= m; j++) dp[j] = -inf;
			dp[0] = 0;
			for(int j = 0; j < m; j++){
				chmax(dp[j+1], dp[j]);
				for(int k = 0; k < vec[j].size(); k++){
					llint nid = vec[j][k];
					if(!sup[id][nid]) continue;
					chmax(dp[r[nid]+1], dp[j] + ans[nid]);
				}
			}
			ans[id] = dp[m] + 1;
		}
		
		cout << ans[n]-1 << endl;
	}
	
	flush(cout);
	
	return 0;
}