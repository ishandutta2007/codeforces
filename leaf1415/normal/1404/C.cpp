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

using namespace std;
typedef pair<llint, llint> P;

// range-add, range-min query
 
struct LazySegTree{
	int size;
	vector<llint> seg;
	vector<llint> delay;
	
	LazySegTree(){}
	LazySegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
		delay.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++){
			seg[i] = inf;
			delay[i] = 0;
		}
	}
	
	void eval(int l, int r, int k)
	{
		if(delay[k]){
			seg[k] += delay[k];  //
			if(l < r){
				delay[k*2] += delay[k];
				delay[k*2+1] += delay[k];
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
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}
	
	void add(int a, int b, int k, int l, int r, llint val)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return;
		if(a <= l && r <= b){
			delay[k] += val;
			eval(l, r, k);
			return;
		}
		add(a, b, k*2, l, (l+r)/2, val);
		add(a, b, k*2+1, (l+r)/2+1, r, val);
		seg[k] = min(seg[k*2], seg[k*2+1]);
	}
	void add(int a, int b, llint val){
		if(a > b) return;
		add(a, b, 1, 0, (1<<size)-1, val);
	}
 
	llint query(int a, int b, int k, int l, int r)
	{
		eval(l, r, k);
		
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	llint query(int a, int b)
	{
		if(a > b) return inf;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

struct BIT{
	int size;
	vector<llint> bit;
	BIT(){size = 0;}
	BIT(int s){
		size = s;
		bit.resize(size+1);
		init();
	}
	void init(){
		for(int i = 1; i <= size; i++) bit[i] = 0;
	}
	llint query(int i){
		llint ret = 0;
		while(i > 0){
			ret += bit[i];
			i -= i&(-i);
		}
		return ret;
	}
	void add(int i, llint x){
		while(i <= size){
			bit[i] += x;
			i += i&(-i);
		}
	}
};


llint n, Q;
llint a[300005];
vector<P> qvec[300005];
llint ans[300005];
LazySegTree seg(19);
BIT bit(300005);
bool used[300005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> Q;
	for(int i = 1; i <= n; i++) cin >> a[i];
	llint x, y;
	for(int i = 1; i <= Q; i++){
		cin >> x >> y;
		qvec[x].push_back(P(y, i));
	}
	
	seg.init();
	for(int i = 1; i <= n; i++){
		if(a[i] <= i) seg.update(i, a[i]);
		else seg.update(i, 0);
	}
	
	//for(int i = 1; i <= n; i++) cout << seg.query(i, i).first << " "; cout << endl;
	
	for(int i = 0; i < n; i++){
		
		if(i > 0 && !used[i]){
			bit.add(i, 1);
			seg.add(i, i, inf);
			seg.add(i+1, n, -1);
			used[i] = true;
		}
		
		llint p = 1;
		while(p <= n){
			if(seg.query(p, n) > 0) break;
			
			llint ub = n, lb = p-1, mid;
			while(ub-lb>1){
				mid = (ub+lb)/2;
				if(seg.query(p, mid) <= 0) ub = mid;
				else lb = mid;
			}
			p = ub;
			bit.add(p, 1);
			seg.add(p, p, inf);
			seg.add(p+1, n, -1);
			used[p] = true;
			p++;
		}
		
		for(int j = 0; j < qvec[i].size(); j++){
			ans[qvec[i][j].second] = (n-qvec[i][j].first) - bit.query(n-qvec[i][j].first);
		}
		
		//for(int j = 1; j <= n; j++) cout << bit.query(j) - bit.query(j-1) << " "; cout << endl;
	}
	
	for(int i = 1; i <= Q; i++) cout << ans[i] << "\n";
	flush(cout);
	
	return 0;
}