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
#define inf 1e9
#define rep(x, s, t) for(llint (x) = (s); (x) < (t); (x)++)
#define Rep(x, s, t) for(llint (x) = (s); (x) <= (t); (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define mod 998244353

using namespace std;
typedef pair<int, int> P;

struct SegTree{
	int size;
	vector<P> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = P(-inf, 0);
	}
	
	void update(int i, P val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = max(seg[i*2], seg[i*2+1]);
		}
	}

	P query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return P(-inf, 0);
		if(a <= l && r <= b) return seg[k];
		P lval = query(a, b, k*2, l, (l+r)/2);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return max(lval, rval);
	}
	P query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

llint n, k;
llint a[200005][5];
SegTree seg[32];
llint Q;

inline int calc(int id, int mask)
{
	int ret = 0;
	for(int i = 0; i < k; i++){
		if(mask & (1<<i)) ret += a[id][i];
		else ret -= a[id][i];
	}
	return ret;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < k; j++){
			cin >> a[i][j];
		}
	}
	
	llint K = 1<<k;
	for(int i = 0; i < K; i++) seg[i] = SegTree(18), seg[i].init();
	
	for(int i = 1; i <= n; i++){
		for(int j = 0; j < K; j++){
			seg[j].update(i, P(calc(i, j), i));
		}
	}
	
	cin >> Q;
	int t, id, l, r;
	for(int q = 0; q < Q; q++){
		cin >> t;
		if(t == 1){
			cin >> id;
			for(int i = 0; i < k; i++) cin >> a[id][i];
			for(int j = 0; j < K; j++){
				seg[j].update(id, P(calc(id, j), id));
			}
		}
		else{
			cin >> l >> r;
			int ans = 0;
			for(int i = 0; i < K; i++){
				int lid = seg[K-1-i].query(l, r).second, rid = seg[i].query(l, r).second;
				int tmp = 0;
				for(int j = 0; j < k; j++) tmp += abs(a[lid][j]-a[rid][j]);
				ans = max(ans, tmp);
			}
			cout << ans << "\n";
		}
	}
	flush(cout);
	
	return 0;
}