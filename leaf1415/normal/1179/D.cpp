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

struct LiChaoTree{
	int size;
	vector<P> seg;
	vector<llint> x;
	
	LiChaoTree(){}
	LiChaoTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		x.resize(1<<size);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = make_pair(0, inf);
		for(int i = 0; i < (1<<size); i++) x[i] = i;  //
	}
	llint calc(P f, llint x)
	{
		return f.first * x + f.second;
	}
	llint query(int i) //x[i]
	{
		llint X = x[i], ret = inf;
		i += (1 << size);
		while(i >= 1){
			ret = min(ret, calc(seg[i], X));
			i /= 2;
		}
		return ret;
	}
	void add(int k, int l, int r, P f)
	{
		int m = (l+r)/2;
		if(calc(f, x[m]) < calc(seg[k], x[m])) swap(seg[k], f);
		bool L = (calc(f, x[l]) < calc(seg[k], x[l])), R = (calc(f, x[r]) < calc(seg[k], x[r]));
		if(L == R) return;
		if(L) add(k*2, l, m, f);
		if(R) add(k*2+1, m+1, r, f);
	}
	void addSegment(int a, int b, int k, int l, int r, P f)
	{
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			add(k, l, r, f);
			return;
		}
		addSegment(a, b, k*2, l, (l+r)/2, f);
		addSegment(a, b, k*2+1, (l+r)/2+1, r, f);
	}
	void addSegment(int a, int b, llint p, llint q) //[x[a], x[b]]px+q
	{
		addSegment(a, b, 1, 0, (1<<size)-1, make_pair(p, q));
	}
	void addLine(llint p, llint q) //px+q
	{
		return addSegment(0, (1<<size)-1, p, q);
	}
};

llint n;
vector<int> G[500005];
int size[500005];

int parent[500005];
llint dp[500005], dp2[500005];
LiChaoTree lct;

int getsize(int u, int v)
{
	if(parent[u] == v) return n-size[u];
	else return size[v];
}

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		ret += sizedfs(G[v][i], v);
	}
	return size[v] = ret;
}

llint get(int u, int v)
{
	if(parent[u] == v) return dp2[u];
	else return dp[v];
}

void dfs(int v, int p)
{
	parent[v] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs(G[v][i], v);
	}
	
	llint size = getsize(p, v);
	llint sum = size*(size-1)/2;
	for(int i = 0; i < G[v].size(); i++){
		int u = G[v][i];
		if(u == p) continue;
		llint usize = size - getsize(v, u);
		chmin(sum, get(v, u)+usize*(usize-1)/2);
	}
	dp[v] = sum;
}

void dfs2(int v, int p)
{
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i];
		if(u == p) continue;
		llint usize = n - getsize(v, u);
		dp2[u] = usize*(usize-1)/2;
	}
	
	llint dlog = 0;
	for(llint t = (int)G[v].size(); t; t/=2) dlog++;
	lct = LiChaoTree(dlog);
	
	vector<llint> vec;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], usize = getsize(v, u);
		vec.push_back(n-usize);
	}
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());
	
	
	lct.init();
	for(int i = 0; i < (1<<lct.size); i++){
		if(i < vec.size()) lct.x[i] = vec[i];
		else lct.x[i] = 1e9;
	}
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i], usize = getsize(v, u), x = n-usize;
		if(u != p){
			llint pos = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
			chmin(dp2[u], (lct.query(pos) + x*x-x)/2);
		}
		lct.addLine(-2*usize, usize*(usize+1)+2*get(v, u));
	
	}
	
	lct.init();
	for(int i = 0; i < (1<<lct.size); i++){
		if(i < vec.size()) lct.x[i] = vec[i];
		else lct.x[i] = 1e9;
	}
	for(int i = (int)G[v].size()-1; i >= 0; i--){
		llint u = G[v][i], usize = getsize(v, u), x = n-usize;
		if(u != p){
			llint pos = lower_bound(vec.begin(), vec.end(), x) - vec.begin();
			chmin(dp2[u], (lct.query(pos) + x*x-x)/2);
		}
		lct.addLine(-2*usize, usize*(usize+1)+2*get(v, u));
	}
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		dfs2(G[v][i], v);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	sizedfs(1, -1);
	dfs(1, -1);
	dfs2(1, -1);
	
	llint ans = inf;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < G[i].size(); j++){
			llint u = G[i][j];
			llint size = n - getsize(i, u);
			ans = min(ans, get(i, u) + size*(size-1)/2);
		}
	}
	
	ans = n*(n-1) - ans;
	cout << ans << endl;
	
	return 0;
}