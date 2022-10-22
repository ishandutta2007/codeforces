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
		if(a > b) return inf;
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, a, b, c, d, s, len;
ll t[300005], q[300005];
ll h[300005], h2[300005];
SegTree seg(19), seg2(19);

void make(ll a, ll b, ll h[])
{
	rep(i, 1, n){
		h[i] = h[i-1];
		if(q[i] == 1) h[i] += a;
		else h[i] -= b;
	}
}

bool check(ll x)
{
	ll l = lower_bound(t+1, t+n+1, x) - t;
	ll r = lower_bound(t+1, t+n+1, x+len) - t - 1;

	//cout << x << " " << l << " " << r << endl;

	ll H = s;
	if(seg.query(0, l-1) + H < 0) return false;
	H += h[l-1];
	if(seg2.query(l, r) - h2[l-1] + H < 0) return false;
	//H += h2[r] - h2[l-1];
	//if(seg.query(r+1, n) - h[r] + H < 0) return false;
	return true;
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> a >> b >> c >> d >> s >> len;
	rep(i, 1, n) cin >> t[i] >> q[i];

	make(a, b, h);
	make(c, d, h2);

	seg.init(), seg2.init();
	rep(i, 0, n) seg.update(i, h[i]), seg2.update(i, h2[i]);

	set<ll> S;
	S.insert(0);
	rep(i, 1, n) S.insert(max(0LL, t[i]-len+1));
	rep(i, 1, n) S.insert(max(0LL, t[i]+1));

	for(auto x : S){
		if(check(x)){
			cout << x << endl;
			return 0;
		}
	}
	cout << -1 << endl;

	return 0;
}