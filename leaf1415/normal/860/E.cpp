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

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> T;


// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> seg, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	llint Ident(){ //identity element
		return 0;
	}
	llint ope(llint a, llint b){ //operator
		return (a + b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = Ident();
			delay[i] = 0; //
		}
	}
	
	void eval(int l, int r, int k) //
	{
		if(delay[k]){
			seg[k] = 0;  //
			if(l < r){
				delay[k*2] = 1;
				delay[k*2+1] = 1;
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, llint val)
	{
		int l = 0, r = (1<<size)-1, k = 1;
		
		eval(l, r, k);
		for(int j = size-1; j >= 0; j--){
			k <<= 1;
			if(i & (1<<j)){
				k++;
				l = (l+r)/2+1;
			}
			else r = (l+r)/2;
			eval(l, r, k);
		}
		
		seg[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] = 1; //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2);
		add(a, b, k*2+1, (l+r)/2+1, r);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
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


ll n, root;
vector<ll> G[500005];
ll ans[500005], add[500005];
vector<ll> vec[500005];
LazySegTree nseg(19), sseg(19);

const int VNUM = 500005, LOG_VNUM = 19;
int Prev[VNUM][LOG_VNUM];
int depth[VNUM];

void predfs(int v, int p, int d)
{
	depth[v] = d;
	vec[d].push_back(v);
	Prev[v][0] = p;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
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

void ansdfs(int v, ll s)
{
	ans[v] = s + add[v];
	for(auto u : G[v]) ansdfs(u, ans[v]);
}

void calc()
{
	nseg.init(), sseg.init();
	rep(i, 0, n){
		nseg.add(0, n), sseg.add(0, n);
		rep(j, 1, (int)vec[i].size()-1){
			ll lca = getLCA(vec[i][j-1], vec[i][j]);
			ll d = i - depth[lca], num = nseg.query(0, d) + 1;
			nseg.add(0, d), nseg.update(d, num);
			sseg.add(0, d), sseg.update(d, num * (i+1-d));
			add[vec[i][j]] += sseg.query(0, n);
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll p;
	rep(i, 1, n){
		cin >> p;
		if(p == 0) root = i;
		else G[p].push_back(i);
	}
	predfs(root, 0, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	
	calc();
	rep(i, 0, n) reverse(all(vec[i]));
	calc();
	rep(i, 1, n) add[i] += depth[i]+1;
	
	ansdfs(root, 0);
	rep(i, 1, n) cout << ans[i] - (depth[i]+1) << " "; cout << endl;
	
	return 0;
}