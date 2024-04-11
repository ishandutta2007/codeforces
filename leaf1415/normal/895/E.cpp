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
#define mod 1000000007

using namespace std;

typedef long long llint;
typedef long long ll;
typedef pair<llint, llint> P;

// range-add, range-min query

struct LazySegTree{
	int size;
	vector<double> seg;
	vector<double> delay, delay2;

	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
		delay2.resize(1<<(size+1));
	}

	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = 0;
			delay[i] = delay2[i] = -inf;
		}
	}

	void merge(ll t, double a, double b)
	{
		double a2 = delay[t], b2 = delay2[t];
		if(a2 < -inf/2) a2 = 1, b2 = 0;
		delay[t] = a*a2, delay2[t] = a*b2 + b;
	}
	void merge(ll t, ll s){
		double a = delay[s], b = delay2[s];
		merge(t, a, b);
	}

	void eval(int l, int r, int k)
	{
		if(delay[k] > -inf/2){
			seg[k] = seg[k] * delay[k] + delay2[k] * (r-l+1);
			if(l < r){
				merge(k*2, k);
				merge(k*2+1, k);
			}
			delay[k] = delay2[k] = -inf;
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
			seg[i] = (seg[i*2] + seg[i*2+1]);
		}
	}

	void add(int a, int b, int k, int l, int r, double val, double val2)
	{
		eval(l, r, k);

		if(b < l || r < a) return;
		if(a <= l && r <= b){
			merge(k, val, val2);
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val, val2);
		add(a, b, k*2+1, (l+r)/2+1, r, val, val2);
		seg[k] = (seg[k*2] + seg[k*2+1]);
	}
	void add(int a, int b, double val, double val2){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val, val2);
	}

	double query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);

		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		double lval = query(a, b, k*2, l, (l+r)/2);
		double rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return (lval + rval);
	}
	double query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, Q;
ll a[100005];
LazySegTree seg(17);

int main(void)
{
	//ios::sync_with_stdio(0);
	//cin.tie(0);

	cin >> n >> Q;
	rep(i, 1, n) cin >> a[i];

	seg.init();
	rep(i, 1, n) seg.update(i, a[i]);

	ll t, l, r, L, R;
	rep(q, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> l >> r >> L >> R;
			double s = seg.query(l, r), s2 = seg.query(L, R);
			double len = r-l+1, len2 = R-L+1;
			seg.add(l, r, (len-1)/len, s2 / (len*len2));
			seg.add(L, R, (len2-1)/len2, s / (len*len2));
		}
		else{
			cin >> l >> r;
			printf("%.11f\n", seg.query(l, r));
		}
	}
	return 0;
}