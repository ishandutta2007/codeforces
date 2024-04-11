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
//typedef pair<llint, llint> P;
typedef vector<int> P;

// range-add, range-min query

llint m;
P I, A[2];

inline P merge(P &a, P &b)
{
	P ret(m+1);
	rep(i, 0, m) ret[i] = a[b[i]];
	return ret;
}

struct LazySegTree{
	int size;
	vector<P> seg, seg2;
	vector<int> delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		seg2.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = I, seg2[i] = I;
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			swap(seg[k], seg2[k]);
			if(l < r){
				delay[k*2] ^= delay[k];
				delay[k*2+1] ^= delay[k];
			}
			delay[k] = 0;
		}
	}
	
	void update(int i, P val, P val2)
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
		seg[i] = val, seg2[i] = val2;
		while(i > 1){
			i /= 2;
			seg[i] = merge(seg[i*2], seg[i*2+1]);
			seg2[i] = merge(seg2[i*2], seg2[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] ^= val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = merge(seg[k*2], seg[k*2+1]);
		seg2[k] = merge(seg2[k*2], seg2[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	P query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return I;
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return merge(lval, rval);
	}
	P query(int a, int b)
	{
		if(a > b) return I;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, Q;
llint a[200005];
LazySegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m >> Q;
	rep(i, 1, n) cin >> a[i], a[i] %= 2;
	
	rep(i, 0, m) I.push_back(i);
	A[0].resize(m+1), A[1].resize(m+2);
	rep(i, 0, m){
		A[0][i] = max(0LL, i-1);
		A[1][i] = max(0LL, i-1);
	}
	A[1][0] = m;
	
	seg.init();
	rep(i, 1, n) seg.update(i, A[a[i]], A[a[i]^1]);
	
	llint t, l, r, x;
	rep(i, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> l >> r >> x;
			seg.add(l, r, x%2);
		}
		else{
			cin >> l >> r;
			P res = seg.query(l, r);
			if(res[0] == m) cout << 2 << "\n";
			else cout << 1 << "\n";
		}
	}
	flush(cout);
	
	return 0;
}