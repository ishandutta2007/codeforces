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
llint a[100005], h[100005];
vector<llint> G[100005];
llint sum[100005], pos[100005];

void dfs(int v, int p)
{
	sum[v] = a[v];
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
		sum[v] += sum[G[v][i]];
	}
}

bool dfs2(int v, int p)
{
	llint psum = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(!dfs2(G[v][i], v)) return false;
		psum += pos[G[v][i]];
	}
	llint x = (h[v]+sum[v])/2, y = (sum[v]-h[v])/2;
	if((h[v]+sum[v])%2 || (sum[v]-h[v]) < 0) return false;
	pos[v] = x;
	if(pos[v] < psum) return false;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n >> m;
		for(int i = 1; i <= n; i++) cin >> a[i];
		for(int i = 1; i <= n; i++) cin >> h[i];
		
		for(int i = 1; i <= n; i++) G[i].clear();
		
		llint u, v;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		dfs(1, -1);
		
		if(dfs2(1, -1)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}