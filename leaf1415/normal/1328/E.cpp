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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)

using namespace std;
typedef pair<llint, llint> P;

llint n, m;
vector<llint> G[200005];
int Prev[200005][18];
int depth[200005];

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
	
	for(int i = 17; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = 17; i >= 0; i--){
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
	
	cin >> n >> m;
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	predfs(1, 0, 0);
	for(int i = 1; i < 18; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	vector<P> vec; llint p, k;
	for(int i = 1; i <= m; i++){
		cin >> k;
		vec.clear();
		for(int j = 0; j < k; j++){
			cin >> v;
			if(v == 1) p = 1;
			else p = Prev[v][0];
			vec.push_back(P(depth[p], p));
		}
		sort(vec.rbegin(), vec.rend());
		
		//for(int i = 0; i < vec.size(); i++) cout << vec[i].first << " " << vec[i].second << endl;
		//cout << endl;
		
		bool ans = true;
		for(int i = 1; i < vec.size(); i++){
			int v = vec[i-1].second, nv = vec[i].second, d = vec[i-1].first-vec[i].first;
			for(int i = 0; i < 18; i++){
				if(d & (1<<i)) v = Prev[v][i];
			}
			if(v != nv){
				ans = false;
				break;
			}
		}
		if(ans) cout << "YES" << "\n";
		else cout << "NO" << "\n";
	}
	
	return 0;
}