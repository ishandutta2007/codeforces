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

struct SegTree{
	int size;
	vector<vector<int> > seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	llint Ident(){  //identity element
		return 0;
	}
	llint ope(llint a, llint b){ //operator
		return (a + b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) sort(all(seg[i]));
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i].push_back(val);
		while(i > 1){
			i /= 2;
			seg[i].push_back(val);
		}
	}

	llint query(int a, int b, int k, int l, int r, int x)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b){
			int pos = lower_bound(all(seg[k]), x) - seg[k].begin();
			return (int)seg[k].size() - pos;
		}
		llint lval = query(a, b, k*2, l, (l+r)/2, x);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r, x);
		return ope(lval, rval);
	}
	llint query(int a, int b, int x)
	{
		return query(a, b, 1, 0, (1<<size)-1, x);
	}
};

ll n, k, Q;
ll a[100005], p[100005];
vector<ll> vec[100005];
SegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> k;
	rep(i, 1, n) cin >> a[i], vec[a[i]].push_back(i);
	rep(i, 1, n){
		ll pos = lower_bound(all(vec[a[i]]), i) - vec[a[i]].begin();
		if(pos < k) p[i] = -1;
		else p[i] = vec[a[i]][pos-k];
		seg.update(i, p[i]);
	}
	seg.init();
	
	cin >> Q;
	ll last = 0, l, r;
	rep(i, 1, Q){
		cin >> l >> r;
		l = (l+last)%n+1, r = (r+last)%n+1;
		if(l > r) swap(l, r);
		
		last = r-l+1 - seg.query(l, r, l);
		cout << last << "\n";
	}
	flush(cout);
	
	return 0;
}