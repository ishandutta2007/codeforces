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

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return 0;
	}
	llint ope(llint a, llint b){ //operator
		return (a + b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n;
ll a[200005];
vector<ll> G[200005];
vector<ll> vec[200005];
ll add[200005], ans[200005];
ll l[200005], r[200005];
SegTree seg(18);
map<ll, ll> mp;

const int VNUM = 200005, LOG_VNUM = 18;
int Prev[VNUM][LOG_VNUM];
int depth[VNUM];

ll pos = 0;
void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	l[v] = ++pos;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
	r[v] = pos;
}

int getLCA(int u, int v){
	int x = u, y = v;
	if(depth[y] > depth[x]) swap(x, y);
	
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(depth[x] - (1<<i) >= depth[y]) x = Prev[x][i];
	}
	if(x == y) return x;
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(Prev[x][i] != Prev[y][i]){
			x = Prev[x][i];
			y = Prev[y][i];
		}
	}
	x = Prev[x][0];
	return x;
}

void dfs(int v, int p, ll s)
{
	s += add[v];
	ans[v] += s;
	for(auto u : G[v]){
		if(u == p) continue;
		dfs(u, v, s);
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	ll u, v;
	rep(i, 1, n-1){
		cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	rep(i, 1, n) mp[a[i]];
	ll id = 0;
	for(auto &p : mp) p.second = id++;
	rep(i, 1, n) a[i] = mp[a[i]];
	
	
	predfs(1, 0, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	seg.init();
	rep(i, 1, n) vec[a[i]].push_back(i);
	
	ll all = 0;
	rep(i, 0, n){
		if(vec[i].size() <= 1) continue;
		
		for(auto v : vec[i]) seg.update(l[v], 1);
		
		for(auto v : vec[i]){
			ll p = Prev[v][0];
			for(auto u : G[v]){
				if(u == p) continue;
				if(seg.query(l[u], r[u])) add[u]--, all++;
			}
			if(p > 0 && seg.query(l[v], r[v]) < (int)vec[i].size()) add[v]++;
		}
		
		for(auto v : vec[i]) seg.update(l[v], 0);
	}
	
	dfs(1, 0, 0);
	
	ll acnt = 0;
	rep(i, 1, n) if(ans[i]+all == 0) acnt++;
	cout << acnt << endl;
	
	return 0;
}