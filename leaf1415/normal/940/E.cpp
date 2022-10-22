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
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, c;
ll a[100005], s[100005];;
SegTree seg(17);
ll dp[100005];

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> c;
	rep(i, 1, n) cin >> a[i], s[i] = s[i-1] + a[i];
	if(c == 1){
		cout << 0 << endl;
		return 0;
	}

	seg.init();
	rep(i, 0, n) seg.update(i, a[i]);

	rep(i, 0, n) dp[i] = inf;
	dp[0] = 0;

	rep(i, 0, n-1){
		chmin(dp[i+1], dp[i]+a[i+1]);
		if(i+c <= n) chmin(dp[i+c], dp[i]+s[i+c]-s[i]-seg.query(i+1, i+c));
	}
	cout << dp[n] << endl;

	return 0;
}