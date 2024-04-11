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
	vector<llint> seg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		seg.resize(1<<(size+1));
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = inf;
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = min(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return inf;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return min(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll T;
ll n;
ll a[300005];
ll ans[300005];
SegTree seg(19);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	seg.init();
	
	cin >> T;
	while(T--){
		cin >> n;
		rep(i, 1, n) cin >> a[i], ans[i] = 0;
		
		set<ll> S;
		rep(i, 1, n) S.insert(a[i]);
		if(S.size() == n) ans[1] = 1;
		
		rep(i, 1, n) seg.update(i, a[i]);
		
		ll l = 0, r = n+1;
		rep(i, 1, n-1){
			if(seg.query(l+1, r-1) == i) ans[n-i+1] = 1;
			if(a[l+1] == i) l++;
			else if(a[r-1] == i) r--;
			else break;
		}
		rep(i, 1, n) cout << ans[i]; cout << "\n";
	}
	flush(cout);
	
	return 0;
}