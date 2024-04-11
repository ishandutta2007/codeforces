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
#define llint long long
#define inf 1e18
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))

using namespace std;
typedef pair<llint, llint> P;
typedef pair<P, P> M;

M I = M(P(0, -inf), P(-inf, 0));

inline M merge(M &a, M &b)
{
	llint x = max(a.first.first + b.first.first, a.first.second + b.second.first);
	llint y = max(a.first.first + b.first.second, a.first.second + b.second.second);
	llint z = max(a.second.first + b.first.first, a.second.second + b.second.first);
	llint w = max(a.second.first + b.first.second, a.second.second + b.second.second);
	return M(P(x, y), P(z, w));
}

struct SegTree{
	int size;
	vector<M> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = I;
	}
	
	void update(int i, const M &val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = merge(seg[i*2+1], seg[i*2]);
		}
	}

	M query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return I;
		if(a <= l && r <= b) return seg[k];
		M lval = query(a, b, k*2, l, (l+r)/2);
		M rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return merge(rval, lval);
	}
	M query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint T;
llint n, Q;
llint a[300005];
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> T;
	for(int t = 1; t <= T; t++){
		cin >> n >> Q;
		for(int i = 1; i <= n; i++) cin >> a[i];
		
		for(int i = 1; i <= n; i++){
			seg.update(i, M(P(0, -a[i]), P(a[i], 0)));
		}
		
		M res = seg.query(1, n);
		cout << max(res.first.first, res.second.first) << "\n";
		
		llint l, r;
		for(int q = 1; q <= Q; q++){
			cin >> l >> r;
			
			seg.update(l, M(P(0, -a[r]), P(a[r], 0)));
			seg.update(r, M(P(0, -a[l]), P(a[l], 0)));
			
			swap(a[l], a[r]);
			
			res = seg.query(1, n);
			cout << max(res.first.first, res.second.first) << "\n";
		}
		for(int i = 1; i <= n; i++) seg.update(i,  I);
	}
	
	flush(cout);
	
	return 0;
}