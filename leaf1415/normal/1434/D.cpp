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

struct edge{
	llint to, id;
	edge(){}
	edge(llint a, llint b){
		to = a, id = b;
	}
};

// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> mseg, Mseg, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		mseg.resize(1<<(size+1));
		Mseg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			mseg[i] = inf;
			Mseg[i] = -inf;
			delay[i] = 1;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k] == -1){
			llint m = mseg[k], M = Mseg[k];
			mseg[k] = -M, Mseg[k] = -m;
			if(l < r){
				delay[k*2] *= delay[k];
				delay[k*2+1] *= delay[k];
			}
			delay[k] = 1;
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
				r = (l+r)/2;
			}
			else l = (l+r)/2+1;
			eval(l, r, k);
		}
		
		i += (1 << size);
		mseg[i] = Mseg[i] = val;
		while(i > 1){
			i /= 2;
			mseg[i] = min(mseg[i*2], mseg[i*2+1]);
			Mseg[i] = max(Mseg[i*2], Mseg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] *= val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		mseg[k] = min(mseg[k*2], mseg[k*2+1]);
		Mseg[k] = max(Mseg[k*2], Mseg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return -inf;
		if(a <= l && r <= b) return Mseg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, Q;
vector<edge> G[500005];

struct Tree{
	LazySegTree seg;
	int l[500005], r[500005], x[500005];
	Tree(){
		seg = LazySegTree(20);
		seg.init();
	}
	int id;
	void dfs(int v, int p, int d)
	{
		l[v] = id++;
		seg.update(l[v], d);
		for(int i = 0; i < G[v].size(); i++){
			if(G[v][i].to == p) continue;
			x[G[v][i].id] = G[v][i].to;
			dfs(G[v][i].to, v, d+1);
		}
		r[v] = id++;
	}
	void init(int r){
		id = 1;
		dfs(r, -1, 0);
	}
	void change(int e)
	{
		seg.add(l[x[e]], r[x[e]], -1);
	}
	llint query()
	{
		return seg.query(0, (1<<20)-1);
	}
};

llint dtmp[500005];
llint distdfs(vector<edge> G[], int v, int p, llint d)
{
	dtmp[v] = d;
	for(int i = 0; i < G[v].size(); i++){
		llint u = G[v][i].to, c = 1; //
		if(u == p) continue;
		distdfs(G, u, v, d+c);
	}
}

llint getDiameter(vector<edge> G[], llint n, llint &u, llint &v)
{
	distdfs(G, 1, -1, 0);
	llint max_val = -1, max_v;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	u = max_v;
	
	distdfs(G, u, -1, 0);
	max_val = -1;
	for(int i = 1; i <= n; i++){
		if(max_val < dtmp[i]){
			max_val = dtmp[i];
			max_v = i;
		}
	}
	v = max_v;
	
	return max_val;
}

vector<llint> vec;
Tree utree, vtree;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	llint u, v, t;
	for(int i = 1; i <= n-1; i++){
		cin >> u >> v >> t;
		G[u].push_back(edge(v, i));
		G[v].push_back(edge(u, i));
		if(t) vec.push_back(i);
	}
	
	getDiameter(G, n, u, v);
	utree.init(u), vtree.init(v);
	
	for(int i = 0; i < vec.size(); i++){
		utree.change(vec[i]);
		vtree.change(vec[i]);
	}
	
	cin >> Q;
	llint e;
	for(int q = 0; q < Q; q++){
		cin >> e;
		utree.change(e), vtree.change(e);
		cout << max(utree.query(), vtree.query()) << "\n";
	}
	flush(cout);
	
	return 0;
}