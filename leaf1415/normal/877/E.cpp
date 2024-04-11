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
			seg[k] = (r-l+1) - seg[k];  //
			if(l < r){
				delay[k*2] ^= delay[k];
				delay[k*2+1] ^= delay[k];
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
				r = (l+r)/2;
			}
			else l = (l+r)/2+1;
			eval(l, r, k);
		}
		
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] ^= val; //
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
vector<ll> G[200005];
ll t[200005];
ll l[200005], r[200005];
LazySegTree seg(18);

ll id = 0;
void dfs(int v)
{
	l[v] = ++id;
	for(auto u : G[v]) dfs(u);
	r[v] = id;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	ll p;
	rep(i, 2, n){
		cin >> p;
		G[p].push_back(i);
	}
	rep(i, 1, n) cin >> t[i];
	
	dfs(1);
	
	seg.init();
	rep(i, 1, n) seg.update(l[i], t[i]);
	
	cin >> Q;
	string s; ll v;
	while(Q--){
		cin >> s >> v;
		if(s == "pow") seg.add(l[v], r[v], 1);
		else cout << seg.query(l[v], r[v]) << "\n";
	}
	flush(cout);
	
	return 0;
}