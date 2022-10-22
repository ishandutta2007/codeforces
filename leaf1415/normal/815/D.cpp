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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define mark cout << "*" << endl
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;


// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> seg, seg2, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		seg2.resize(1<<(size+1));
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
			seg[i] = Ident(), seg2[i] = -inf;
			delay[i] = 0; //
		}
	}
	
	void eval(int l, int r, int k) //
	{
		if(delay[k]){
			seg[k] = delay[k] * (r-l+1);  //
			seg2[k] = delay[k];
			if(l < r){
				chmax(delay[k*2], delay[k]);
				chmax(delay[k*2+1], delay[k]);
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
		seg2[i+(1<<size)] = val;
		
		l = i, r = i, k = i+(1<<size);
		for(int j = 0; j < size; j++){
			k /= 2, l &= ~(1<<j), r |= 1<<j;
			eval(l, (l+r)/2, k*2), eval((l+r)/2+1, r, k*2+1);
			seg[k] = ope(seg[k*2], seg[k*2+1]);
			seg2[k] = max(seg2[k*2], seg2[k*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			chmax(delay[k], val); //
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = ope(seg[k*2], seg[k*2+1]);
		seg2[k] = max(seg2[k*2], seg2[k*2+1]);
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
		if(a > b) return 0;
		return query(a, b, 1, 0, (1<<size)-1);
	}
	
	ll get(int L, int R, int c)
	{
		int k = 1, l = 0, r = (1<<19)-1;
		while(k < (1<<19)){
			ll m = (l+r)/2;
			eval(l, r, k), eval(l, m, k*2), eval(m+1, r, k*2+1);
			
			if(R < m+1) k = k*2, r = m;
			else if(m < L) k = k*2+1, l = m+1;
			else{
				if(seg2[k*2+1] >= c) k = k*2+1, l = m+1;
				else k = k*2, r = m;
			}
		}
		return k -= (1<<19);
	}
};


int n, p, q, r;
ll a[500005], b[500005], c[500005];
vector<int> vec[500005];
ll maxb[500005], maxc[500005];
LazySegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> p >> q >> r;
	rep(i, 1, n){
		cin >> a[i] >> b[i] >> c[i];
		vec[a[i]].push_back(i);
	}
	
	for(int i = p; i >= 1; i--){
		maxb[i] = maxb[i+1], maxc[i] = maxc[i+1];
		for(auto id : vec[i]) chmax(maxb[i], b[id]), chmax(maxc[i], c[id]);
	}
	
	seg.init();
	seg.update(0, inf);
	
	ll ans = 0;
	rep(i, 1, p){
		ll lb = seg.get(maxb[i], q, maxc[i]);
		//outl(lb);
		ans += (q-maxb[i]) * r;
		ans -= seg.query(maxb[i]+1, lb);
		ans -= maxc[i] * (q - lb);
		
		//rep(j, 0, q) cout << seg.query(j, j) << " "; cout << endl;
		
		for(auto id : vec[i]){
			ll lb = seg.get(0, b[id], c[id]);
			//outl(0 SP b[id] SP c[id] SP lb);
			seg.add(lb+1, b[id], c[id]);
		}
	}
	cout << ans << endl;
	
	return 0;
}