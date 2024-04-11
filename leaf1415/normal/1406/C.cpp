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
vector<llint> G[100005];
int Size[200005];
bool used[200005];

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		ret += sizedfs(G[v][i], v);
	}
	return Size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		if(Size[G[v][i]] > sz/2) return centdfs(G[v][i], v, sz);
	}
	return v;
}

P dfs(int v, int p)
{
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		return dfs(G[v][i], v);
	}
	return P(p, v);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> T;
	for(int t = 0; t < T; t++){
		cin >> n;
		for(int i = 1; i <= n; i++) G[i].clear();
		llint u, v;
		for(int i = 1; i <= n-1; i++){
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		
		sizedfs(1, -1);
		v = centdfs(1, -1, Size[1]);
		sizedfs(v, -1);
		
		if(n%2){
			cout << v << " " << G[v][0] << endl;
			cout << v << " " << G[v][0] << endl;
			continue;
		}
		
		u = -1;
		for(int i = 0; i < G[v].size(); i++){
			if(Size[G[v][i]] == n/2){
				u = G[v][i];
				break;
			}
		}
		if(u == -1){
			cout << v << " " << G[v][0] << endl;
			cout << v << " " << G[v][0] << endl;
			continue;
		}
		
		P res = dfs(v, u);
		cout << res.first << " " << res.second << endl;
		cout << u << " " << res.second << endl;
	}
	
	
	
	return 0;
}