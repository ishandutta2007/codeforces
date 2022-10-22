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
typedef pair<llint, P> E;


// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<int> seg, delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	int Ident(){ //identity element
		return 0;
	}
	int ope(int a, int b){ //operator
		return a | b;
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
				delay[k*2] = delay[k];
				delay[k*2+1] = delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, int val)
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
			k >>= 1, l &= ~(1<<j), r |= 1<<j;
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
 
	int query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		return (query(a, b, k*2, l, (l+r)/2) || query(a, b, k*2+1, (l+r)/2+1, r));
	}
	int query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};


ll n, s1, s2;
ll x[100005], p[100005];
vector<P> vec;
LazySegTree seg(17);

bool check(ll d)
{
	if(d < abs(s1-s2)) return false;
	
	seg.add(0, n-1);
	seg.update(p[1], 1);
	
	rep(i, 3, n){
		ll l = lower_bound(all(vec), P(x[i]-d, -inf)) - vec.begin();
		ll r = upper_bound(all(vec), P(x[i]+d, inf)) - vec.begin() - 1;
		if(abs(x[i] - x[i-1]) <= d) seg.update(p[i-1], seg.query(0, n-1));
		seg.add(0, l-1), seg.add(r+1, n-1);
	}
	return seg.query(0, n-1);
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> n >> s1 >> s2;
	x[1] = s1, x[2] = s2;
	rep(i, 1, n) cin >> x[i+2];
	n += 2;
	rep(i, 1, n) vec.push_back(P(x[i], i));
	sort(all(vec));
	rep(i, 0, n-1) p[vec[i].second] = i;
	
	ll ub = 2e9, lb = -1, mid;
	while(ub-lb>1){
		mid = (ub+lb)/2;
		if(check(mid)) ub = mid;
		else lb = mid;
	}
	cout << ub << endl;
	
	return 0;
}