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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size(); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define ceildiv(x, y) (((x)+(y)-1) / (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e9
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;
bool exceed(ll x, ll y, ll m){return x >= m / y + 1;} 


struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return inf;
	}
	llint ope(llint a, llint b){ //operator
		return min(a, b);
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

ll n, k, Q;
SegTree aseg(17);

int get(ll l, ll r)
{
	chmin(r, n*k-1);
	if(l > r) return inf;
	if(r-l+1 >= n) return aseg.query(0, n-1);
	
	l %= n, r %= n;
	if(l <= r) return aseg.query(l, r);
	return min(aseg.query(l, n-1), aseg.query(0, r));
}

// sum-query

struct DynamicSegTree{
	struct SegNode{
		int val, delay;
		int left, right, parent;
		SegNode(int p, int x = 0){  //initial value
			left = right = -1;
			parent = p;
			val = x, delay = 0;
		}
	};
	
	int size;
	vector<SegNode> seg;
	
	DynamicSegTree(int size){
		this->size = size;
		init();
	}
	
	void init()
	{
		seg.clear();
		seg.push_back(SegNode(-1));
		seg.back().val = get(0, n-1);
	}
	
	void check(int l, int r, int p){
		if(seg[p].left == -1){
			seg.push_back(SegNode(p));
			seg[p].left = (int)seg.size()-1;
			seg.back().val = get(l, (l+r)/2);
		}
		if(seg[p].right == -1){
			seg.push_back(SegNode(p));
			seg[p].right = (int)seg.size()-1;
			seg.back().val = get((l+r)/2+1, r);
		}
	}
	
	void eval(int l, int r, int p)
	{
		if(seg[p].delay){
			seg[p].val = seg[p].delay;
			if(l < r){
				check(l, r, p);
				seg[seg[p].left].delay = seg[p].delay;
				seg[seg[p].right].delay = seg[p].delay;
			}
			seg[p].delay = 0;
		}
	}
	
	void add(int a, int b, int p, int l, int r, int val)
	{
		eval(l, r, p);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			seg[p].delay = val;
			eval(l, r, p);
			return;
		}
		
		check(l, r, p);
		add(a, b, seg[p].left, l, (l+r)/2, val);
		add(a, b, seg[p].right, (l+r)/2+1, r, val);
		seg[p].val = min(seg[seg[p].left].val, seg[seg[p].right].val);
	}
	void add(int a, int b, int val)
	{
		return add(a, b, 0, 0, (1<<size)-1, val);
	}
	
	int query(int a, int b, int p, int l, int r)
	{
		eval(l, r, p);
		
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[p].val;
		
		check(l, r, p);
		int lval = query(a, b, seg[p].left, l, (l+r)/2);
		int rval = query(a, b, seg[p].right, (l+r)/2+1, r);
		return min(lval, rval);
	}
	int query(int a, int b)
	{
		return query(a, b, 0, 0, (1<<size)-1);
	}
};

ll a[100005];
DynamicSegTree seg(30);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 0, n-1) cin >> a[i];
	aseg.init();
	rep(i, 0, n-1) aseg.update(i, a[i]);
	
	seg.init();
	
	cin >> Q;
	ll t, l, r, x;
	rep(q, 1, Q){
		cin >> t >> l >> r;
		l--, r--;
		if(t == 1) cin >> x, seg.add(l, r, x);
		else cout << seg.query(l, r) << "\n";
	}
	flush(cout);
	
	return 0;
}