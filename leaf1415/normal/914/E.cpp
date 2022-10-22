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
#include <complex>
#define rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define inf 1e18
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

struct ConstantArray
{
	vector<int> vec;
	vector<int> history;
	ConstantArray(){
		vec.resize(1<<20);
	}
	void add(int i){
		vec[i]++;
		history.push_back(i);
	}
	int get(int i){
		return vec[i];
	}
	void clear(){
		for(auto x : history) vec[x]--;
		history.clear();
	}
};

int n;
vector<int> G[200005];
int Size[200005];
bool used[200005];
string s;
ll ans[200005], sum[200005];

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

void add(int u, int v, ll x)
{
	//if(x)cout << u << " " << v << " " << x << endl;
	if(x == 0) return;
	if(u == v){
		sum[u] += x;
		return;
	}
	ll lca = getLCA(u, v);
	ans[u] += x, ans[v] += x, ans[lca] -= x;
	ans[Prev[lca][0]] -= x;
}

void calcdfs(int v, int p)
{
	for(auto u : G[v])
	{
		if(u == p) continue;
		calcdfs(u, v);
		ans[v] += ans[u];
	}
}

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

ConstantArray local, global;
void dfs(int v, int p, int b)
{
	b ^= (1<<(s[v]-'a'));
	global.add(b);
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]) continue;
		dfs(u, v, b);
	}
}
void dfs2(int v, int p, int b)
{
	b ^= (1<<(s[v]-'a'));
	local.add(b);
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]) continue;
		dfs2(u, v, b);
	}
}
void dfs3(int v, int p, int b, int r, int c)
{
	b ^= (1<<(s[v]-'a'));
	rep(j, 0, 20){
		ll x = (1<<j);
		if(j == 20) x = 0;
		ll y = x^b^(1<<(s[r]-'a'));
		add(c, v, 2*(global.get(y) - local.get(y)));
		if((x^b^(1<<(s[r]-'a'))) == 0) add(r, v, 2);
		add(r, r, (global.get(y) - local.get(y)));
	}
	for(auto u : G[v]){
		if(u == p) continue;
		if(used[u]) continue;
		dfs3(u, v, b, r, c);
	}
}

void solve(int v)
{
	sizedfs(v, -1);
	v = centdfs(v, -1, Size[v]);
	
	global.clear();
	for(auto u : G[v]){
		if(used[u]) continue;
		dfs(u, v, 0);
	}
	//global.add(0);
	
	//cout << v << endl;
	//rep(i, 0, 7) cout << global.get(i) << " "; cout << endl;
	
	for(auto u : G[v]){
		if(used[u]) continue;
		local.clear();
		dfs2(u, v, 0);
		dfs3(u, v, 0, v, u);
	}
	add(v, v, 2);
	
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
	cin >> s;
	s = "#" + s;
	
	predfs(1, 0, 0);
	for(int i = 1; i < 18; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	solve(1);
	//rep(i, 1, n) cout << ans[i] << " "; cout << endl;
	
	calcdfs(1, -1);
	rep(i, 1, n) ans[i] += sum[i];
	rep(i, 1, n) cout << ans[i]/2 << " "; cout << endl;
	
	return 0;
}