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
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
#define inf 1e18

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<char, char> P;

// range-add, range-min query

ll ret[10];
ll A[1<<18][10], D[1<<18][10];

struct LazySegTree{
	int size;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
	}
	
	void ope(ll a[], ll b[], ll c[]){ //operator
		rep(i, 0, 9) c[i] = a[i] + b[i];
	}
	void merge(ll a[], ll b[]){
		
		bool flag = false;
		rep(i, 0, 9) if(a[i] != i || b[i] != i) flag = true;
		rep(i, 0, 9) a[i] = b[a[i]];
	}
	
	void eval(int l, int r, int k) //
	{
		ll tmp[10] = {};
		rep(i, 0, 9) tmp[D[k][i]] += A[k][i];
		rep(i, 0, 9) A[k][i] = tmp[i];
		
		if(l < r){
			merge(D[k*2], D[k]);
			merge(D[k*2+1], D[k]);
		}
		
		rep(i, 0, 9) D[k][i] = i;
	}
	
	void add(int a, int b, int k, int l, int r, P val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			ll tmp[10];
			rep(i, 0, 9) tmp[i] = i;
			tmp[val.first] = val.second;
			merge(D[k], tmp);//
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		ope(A[k*2], A[k*2+1], A[k]);
	}
	void add(int a, int b, P val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	void query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			rep(i, 0, 9) ret[i] += A[k][i];
			return;
		}
		query(a, b, k*2, l, (l+r)/2);
		query(a, b, k*2+1, (l+r)/2+1, r);
	}
	void query(int a, int b)
	{
		rep(i, 0, 9) ret[i] = 0;
		if(a > b) return;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};


ll n, Q;
ll a[100005];
LazySegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 0, (1<<18)-1) rep(j, 0, 9) A[i][j] = 0, D[i][j] = j;
	rep(i, 1, n){
		ll mul = 1;
		for(ll x = a[i]; x; x/=10, mul*=10){
			for(ll v = (1<<17)+i; v >= 1; v/=2) A[v][x%10] += mul;
		}
	}
	
	ll t, l, r, x, y;
	rep(q, 1, Q){
		cin >> t >> l >> r;
		if(t == 1) cin >> x >> y, seg.add(l, r, P(x, y));
		if(t == 2){
			seg.query(l, r);
			ll ans = 0;
			rep(i, 0, 9) ans += ret[i] * i;
			cout << ans << "\n";
		}
	}
	flush(cout);
	
	return 0;
}