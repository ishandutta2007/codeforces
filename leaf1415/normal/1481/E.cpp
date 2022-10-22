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
#define reps(x, s) for(llint (x) = 0; (x) < (llint)(s).size()-1; (x)++)
#define chmin(x, y) (x) = min((x), (y))
#define chmax(x, y) (x) = max((x), (y))
#define all(x) (x).begin(),(x).end()
#define outl(x) cout << x << endl
#define SP << " " << 
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
	
	llint Ident(){  //identity element
		return -inf;
	}
	llint ope(llint a, llint b){ //operator
		return max(a, b);
	}
	
	void init()
	{
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = Ident();
	}
	
	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = ope(seg[i*2], seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return ope(lval, rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n;
ll a[500005];
ll l[500005], r[500005], cnt[500005];
SegTree seg(19);
multiset<ll> S;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> a[i];
	
	rep(i, 1, n) l[i] = inf, r[i] = -inf;
	rep(i, 1, n) chmin(l[a[i]], i), chmax(r[a[i]], i), cnt[a[i]]++;
	
	seg.init();
	seg.update(0, 0);
	rep(i, 1, n){
		if(r[a[i]] != i) continue;
		seg.update(i, seg.query(0, l[a[i]]-1) + cnt[a[i]]);
	}
	
	ll ans = 0;
	rep(i, 1, n) cnt[i] = 0, S.insert(0);
	for(int i = n; i >= 1; i--){
		chmax(ans, seg.query(i, i) + *S.rbegin());
		S.erase(S.lower_bound(cnt[a[i]]));
		cnt[a[i]]++;
		S.insert(cnt[a[i]]);
	}
	cout << n - ans << endl;
	
	return 0;
}