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

llint n, k;
vector<llint> G[200005];
int depth[200005], num[200005];
vector<llint> vec;

int dfs(int v, int p, int d)
{
	depth[v] = d; num[v] = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		num[v] += dfs(G[v][i], v, d+1);
	}
	return num[v];
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	llint u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1, -1, 0);
	
	//for(int i = 1; i <= n; i++) cout<< depth[i]-num[i] << " "; cout << endl;
	
	for(int i = 1; i <= n; i++) vec.push_back(depth[i]-(num[i]-1));
	sort(vec.rbegin(), vec.rend());
	
	llint ans = 0;
	for(int i = 0; i < k; i++) ans += vec[i];
	cout << ans << endl;
	
	return 0;
}