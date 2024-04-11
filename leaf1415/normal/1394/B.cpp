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
typedef pair<int, int> P;

int n, m, k;
vector<P> G[200005], revG[200005];
bool ng[150][150], used[150];
int p[15];

int dfs(llint x)
{
	if(x == k+1){
		for(int i = 1; i <= k; i++){
			int u = i*10 + p[i];
			if(used[u]) return 0;
			for(int j = i; j <= k; j++){
				int v = j*10 + p[j];
				if(ng[u][v]) return 0;
			}
		}
		return 1;
	}
	int ret = 0;
	for(int i = 1; i <= x; i++){
		p[x] = i;
		ret += dfs(x+1);
	}
	return ret;
}

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);
	
	//cin >> n >> m >> k;
	scanf("%d %d %d", &n, &m, &k);
	int u, v, w;
	for(int i = 1; i <= m; i++){
		//cin >> u >> v >> w;
		scanf("%d %d %d", &u, &v, &w);
		G[u].push_back(P(w, v));
	}
	for(int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			revG[G[i][j].second].push_back(P(G[i].size(), j+1));
		}
	}
	for(int i = 1; i <= n; i++){
		sort(revG[i].begin(), revG[i].end());
		for(int j = 1; j < revG[i].size(); j++){
			if(revG[i][j-1] == revG[i][j]) used[revG[i][j].first*10+revG[i][j].second] = true;
		}
		revG[i].erase(unique(revG[i].begin(), revG[i].end()), revG[i].end());
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < revG[i].size(); j++){
			int u = revG[i][j].first*10 + revG[i][j].second;
			for(int k = 0; k < revG[i].size(); k++){
				if(j == k) continue;
				int v = revG[i][k].first*10 + revG[i][k].second;
				ng[u][v] = true;
			}
		}
	}
	
	cout << dfs(1) << endl;
	
	return 0;
}