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
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18

using namespace std;

typedef long long llint;
typedef pair<llint, llint> P;

int n;
vector<int> G[200005];
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

llint calc(llint on, llint os, llint en, llint es)
{
	llint ret = 0;
	ret += os*(on-1)/2;
	ret += es*(en-1)/2;
	ret += (os*en + es*on + on*en) / 2;
	return ret;
}

llint on, os, en, es;
void dfs(int v, int p, int d)
{
	if(d % 2) on++, os += d;
	else en++, es += d;
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]) continue;
		dfs(u, v, d+1);
	}
}

llint ans = 0;
void solve(int v)
{
	sizedfs(v, -1);
	v = centdfs(v, -1, Size[v]);
	
	/*   */
	llint oddn = 0, odds = 0, evenn = 0, evens = 0;
	for(auto u : G[v]){
		if(used[u]) continue;
		on = os = en = es = 0;
		dfs(u, v, 1);
		ans -= calc(on, os, en, es);
		oddn += on, odds += os, evenn += en, evens += es;
		//cout << u << " " << ans << endl;
	}
	ans += calc(oddn, odds, evenn, evens);
	ans += evens/2, ans += (odds + oddn) / 2;
	//cout << ans << endl;
	
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		solve(G[v][i]);
	}
}

int main(void)
{
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	solve(1);
	cout << ans << endl;
	
	return 0;
}