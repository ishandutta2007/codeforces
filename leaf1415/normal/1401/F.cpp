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
#define mod 1000000007

using namespace std;
typedef pair<llint, llint> P;
typedef pair<llint, P> E;

llint mask = 0;

struct SegTree{
	int size;
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = 0;
	}
	
	void update(int i, llint val)
	{
		llint l = 0, r = (1<<size)-1;
		for(int d = size; d > 0; d--){
			llint m = (l+r)/2;
			if(!(mask & (1<<d))){
				if(i <= m) r = m;
				else l = m+1;
			}
			else{
				if(i <= m) i = i-l+m+1, l = m+1;
				else i = i-(m+1)+l, r = m;
			}
		}
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = (seg[i*2] + seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r, int d)
	{
		//cout << a << " " << b << " " << l << " " << r << endl;
		if(a > b || a < 0 || b >= (1<<size)) return 0;
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		
		if(!(mask & (1<<d))){
			llint lval = query(a, b, k*2, l, (l+r)/2, d-1);
			llint rval = query(a, b, k*2+1, (l+r)/2+1, r, d-1);
			return (lval + rval);
		}
		else{
			if(a <= (l+r)/2 && b >= (l+r)/2+1){
				llint lval = query(l, b-((l+r)/2+1)+l, k*2, l, (l+r)/2, d-1);
				llint rval = query(a-l+((l+r)/2+1), r, k*2+1, (l+r)/2+1, r, d-1);
				return (lval + rval);
			}
			else if(b <= (l+r)/2){
				return query(a-l+((l+r)/2+1), b-l+((l+r)/2+1), k*2+1, (l+r)/2+1, r, d-1);
			}
			else if(a >= (l+r)/2+1){
				return query(a-((l+r)/2+1)+l, b-((l+r)/2+1)+l, k*2, l, (l+r)/2, d-1);
			}
		}
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1, size);
	}
};

llint n, Q;
llint a[1<<18];
SegTree seg(18);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	
	llint N = 1<<n;
	for(int i = 0; i < N;i++) cin >> a[i];
	
	seg.init();
	for(int i = 0; i < N; i++) seg.update(i, a[i]);
	
	llint t, x, k, l, r;
	for(int q = 0; q < Q; q++){
		cin >> t;
		if(t == 1){
			cin >> x >> k;
			x--;
			seg.update(x, k);
		}
		if(t == 2){
			cin >> k;
			for(int j = 0; j <= k; j++) mask ^= 1<<j;
		}
		if(t == 3){
			cin >> k;
			mask ^= 1<<(k+1);
		}
		if(t == 4){
			cin >> l >> r;
			l--, r--;
			cout << seg.query(l, r) << "\n";
		}
		//cout << "!" << mask << endl;
		//seg.query(0, 0);
		//for(int i = 0; i < N; i++) cout << seg.query(i, i) << " "; cout << endl;
	}
	flush(cout);
	
	return 0;
}