#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <vector>
#define llint long long
#define inf 1e18

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
llint a[150005];
vector<int> G[200005];
int size[200005];
bool used[200005];

llint depth[200005];
llint len[200005];
llint down[200005], up[200005];
vector<llint> lvec;
LiChaoTree lct;

llint ans;

int sizedfs(int v, int pre)
{
	int ret = 1;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		ret += sizedfs(G[v][i], v);
	}
	return size[v] = ret;
}

int centdfs(int v, int pre, int sz)
{
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == pre) continue;
		if(used[G[v][i]]) continue;
		if(size[G[v][i]] > sz/2) return centdfs(G[v][i], v, sz);
	}
	return v;
}

void predfs(llint v, llint p, llint d, llint l, llint s)
{
	l += a[v];
	depth[v] = d, len[v] = l;
	s += depth[v]*a[v];
	down[v] = s;
	up[v] = (depth[v]+1) * len[v] - down[v];
	
	ans = max(ans, up[v]);
	ans = max(ans, down[v] + len[v]);
	
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		predfs(G[v][i], v, d+1, l, s);
	}
}
void predfs2(llint v, llint p, llint r)
{
	len[v] -= a[r];
	depth[v]++;
	lvec.push_back(len[v]);
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		predfs2(G[v][i], v, r);
	}
}

void adddfs(llint v, llint p)
{
	lct.addLine(-depth[v], -up[v]);
	//cout << depth[v] << " " << up[v] << endl;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		adddfs(G[v][i], v);
	}
}
void querydfs(llint v, llint p)
{
	llint pos = lower_bound(lvec.begin(), lvec.end(), len[v]) - lvec.begin();
	ans = max(ans, -lct.query(pos) + down[v]);
	//cout << len[v] << " " << -lct.query(pos) << " " << down[v] << endl;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		if(used[G[v][i]]) continue;
		querydfs(G[v][i], v);
	}
}

void solve(int v, int sz)
{
	sizedfs(v, -1);
	llint c = size[v];
	v = centdfs(v, -1, sz);
	
	/*   */
	lvec.clear();
	predfs(v, -1, 0, 0, 0);
	predfs2(v, -1, v);
	
	llint logc = 0;
	for(;c;c/=2) logc++;
	lct = LiChaoTree(logc);
	
	//cout << v << " " << logc << endl;
	
	sort(lvec.begin(), lvec.end());
	lvec.erase(unique(lvec.begin(), lvec.end()), lvec.end());
	while(lvec.size() < (1<<logc)) lvec.push_back(lvec.back()+1);
	
	//for(int i = 0; i < lvec.size(); i++) cout << lvec[i] << " "; cout << endl;
	
	lct.init();
	for(int i = 0; i < lct.x.size(); i++) lct.x[i] = lvec[i];
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		querydfs(G[v][i], v);
		adddfs(G[v][i], v);
	}
	
	lct.init();
	for(int i = 0; i < lct.x.size(); i++) lct.x[i] = lvec[i];
	for(int i = (int)G[v].size()-1; i >= 0; i--){
		if(used[G[v][i]]) continue;
		querydfs(G[v][i], v);
		adddfs(G[v][i], v);
	}
	
	used[v] = true;
	for(int i = 0; i < G[v].size(); i++){
		if(used[G[v][i]]) continue;
		solve(G[v][i], size[G[v][i]]);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	int u, v;
	for(int i = 0; i < n-1; i++){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	solve(1, n);
	
	cout << ans << endl;
	
	return 0;
}