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
typedef pair<llint, llint> P;



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
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
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
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val; //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
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


ll n, Q;
ll x[300005];
vector<ll> G[300005];
LazySegTree seg(19);

const int VNUM = 300005, LOG_VNUM = 19;
int Prev[VNUM][LOG_VNUM];
int depth[VNUM];
int l[300005], r[300005];

ll id = 0;
void predfs(int v, int p, int d)
{
	depth[v] = d;
	Prev[v][0] = p;
	l[v] = ++id;
	for(int i = 0; i < G[v].size(); i++){
		if(G[v][i] == p) continue;
		predfs(G[v][i], v, d+1);
	}
	r[v] = id;
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

int getdist(int u, int v)
{
	int lca = getLCA(u, v);
	return depth[u] + depth[v] - 2*depth[lca];
}

int getnext(int c, int v)
{
	ll lca = getLCA(c, v);
	if(lca != c) return Prev[c][0];
	
	ll dif = depth[v] - depth[c] - 1;
	for(int i = LOG_VNUM-1; i >= 0; i--){
		if(dif & (1<<i)) v = Prev[v][i];
	}
	return v;
}

void setzero(int u, int v)
{
	if(Prev[v][0] == u) seg.add(l[v], r[v], 1);
	else{
		seg.add(0, l[u]-1, 1);
		seg.add(r[u]+1, n, 1);
	}
}



int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> Q;
	n = Q+1;
	rep(i, 1, Q){
		cin >> x[i];
		G[i+1].push_back(x[i]);
		G[x[i]].push_back(i+1);
	}
	predfs(1, 0, 0);
	for(int i = 1; i < LOG_VNUM; i++){
		for(int j = 1; j <= n; j++){
			Prev[j][i] = Prev[Prev[j][i-1]][i-1];
		}
	}
	seg.update(1, 1);
	
	ll len = 0, cu = 1, cv = 1;
	rep(i, 1, Q){
		ll v = i+1;
		ll d = min(getdist(cu, v), getdist(cv, v));
		
		if(i != 1) seg.add(l[x[i]], l[x[i]], 1);
		if(d == len) seg.update(l[v], 1);
		else if(d > len){
			
			ll c, cc;
			if(getdist(cu, v) == d) c = cu, cc = cv;
			else c = cv, cc = cu;
			
			if(cu == cv){
				ll w = getnext(c, v);
				setzero(c, w);
				cu = w;
			}
			else{
				setzero(cc, c);
				cu = cv = c;
			}
			
			seg.update(l[v], 1);
			len = min(getdist(cu, v), getdist(cv, v));
		}
		cout << seg.query(1, n) << "\n";
	}
	flush(cout);
	
	return 0;
}