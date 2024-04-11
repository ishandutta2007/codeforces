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
		for(int i = 0; i < (1<<(size+1)); i++) seg[i] = 0;
	}

	void update(int i, llint val)
	{
		i += (1 << size);
		seg[i] = val;
		while(i > 1){
			i /= 2;
			seg[i] = (seg[i*2] + seg[i*2+1]);
		}
	}

	llint query(int a, int b, int k, int l, int r)
	{
		if(b < l || r < a) return 0;
		if(a <= l && r <= b) return seg[k];
		llint lval = query(a, b, k*2, l, (l+r)/2);
		llint rval = query(a, b, k*2+1, (l+r)/2+1, r);
		return (lval + rval);
	}
	llint query(int a, int b)
	{
		return query(a, b, 1, 0, (1<<size)-1);
	}
};

ll n, Q;
SegTree seg(18);
ll p[35];
ll fact[20];
ll len, id;

void make()
{
	ll rem = id;
	set<int> S;
	rep(i, 1, len) S.insert(i);

	rep(i, 1, len){
		for(auto x : S){
			if(rem >= fact[len-i]){
				rem -= fact[len-i];
			}
			else{
				p[i] = x;
				S.erase(x);
				break;
			}
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> Q;

	len = min(17LL, n);
	fact[0] = 1;
	rep(i, 1, 17) fact[i] = fact[i-1] * i;

	seg.init();
	rep(i, 1, n) seg.update(i, i);

	ll t, l, r, x;
	rep(q, 1, Q){
		cin >> t;
		if(t == 1){
			cin >> l >> r;
			cout << seg.query(l, r) << "\n";
		}
		else{
			cin >> x;
			id += x;
			make();
			rep(i, 1, len) seg.update(n-len+i, p[i]+n-len);
		}
	}
	flush(cout);

	return 0;
}