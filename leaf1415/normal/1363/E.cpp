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

llint n;
llint a[200005], b[200005], c[200005];
P pp[200005];
vector<llint> G[200005];

llint dfs(int v, int p)
{
	llint psum = 0, nsum = 0;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		llint res = dfs(G[v][i], v);
		if(res > 0) psum += res;
		else nsum -= res;
	}
	llint d = c[v]-b[v];
	if(d > 0) psum += d;
	else nsum -= d;
	pp[v] = P(psum, nsum);
	
	//cout << v << " " << psum-nsum << endl;
	return psum - nsum;
}

llint ans;
void dfs2(int v, int p, llint mn)
{
	mn = min(mn, a[v]);
	ans += min(pp[v].first, pp[v].second) * mn;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v, mn);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i] >> b[i] >> c[i];
	llint u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(dfs(1, -1)){
		cout << -1 << endl;
		return 0;
	}
	
	dfs2(1, -1, inf);
	cout << ans*2 << endl;
	
	return 0;
}