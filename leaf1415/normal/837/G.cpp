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
typedef pair<llint, P> T;

struct SegTree{
	int size;
	vector<vector<T> > lseg, rseg;
	vector<vector<P> > lsseg, rsseg;
	
	SegTree(){}
	SegTree(int size){
		this->size = size;
		lseg.resize(1<<(size+1));
		rseg.resize(1<<(size+1));
		lsseg.resize(1<<(size+1));
		rsseg.resize(1<<(size+1));
	}
	
	P Ident(){  //identity element
		return P(0, 0);
	}
	P ope(P a, P b){ //operator
		return P(a.first + b.first, a.second + b.second);
	}
	
	void init()
	{
		for(int i = 1; i < (1<<(size+1)); i++){
			lseg[i].push_back(T(-inf, P(0, 0)));
			rseg[i].push_back(T(-inf, P(0, 0)));
			sort(all(lseg[i])), sort(all(rseg[i]));
			
			
			lsseg[i].push_back(P(0, 0));
			for(auto p : lseg[i]){
				ll A = lsseg[i].back().first + p.second.first, B = lsseg[i].back().second + p.second.second;
				lsseg[i].push_back(P(A, B));
			}
			rsseg[i].push_back(P(0, 0));
			for(auto p : rseg[i]){
				ll A = rsseg[i].back().first + p.second.first, B = rsseg[i].back().second + p.second.second;
				rsseg[i].push_back(P(A, B));
			}
			lsseg[i].erase(lsseg[i].begin());
			rsseg[i].erase(rsseg[i].begin());
		}
	}
	
	void update(int i, T l, T r)
	{
		i += (1 << size);
		lseg[i].push_back(l), rseg[i].push_back(r);
		while(i > 1){
			i /= 2;
			lseg[i].push_back(l), rseg[i].push_back(r);
		}
	}

	P query(int a, int b, int k, int l, int r, int x)
	{
		if(b < l || r < a) return Ident();
		if(a <= l && r <= b){
			P ret = P(0, 0);
			ll p = upper_bound(all(rseg[k]), T(x, P(inf, inf))) - rseg[k].begin() - 1;
			ret.first += rsseg[k][p].first, ret.second += rsseg[k][p].second;
				
			p = lower_bound(all(lseg[k]), T(x, P(-inf, -inf))) - lseg[k].begin();
			ret.first += lsseg[k].back().first, ret.second += lsseg[k].back().second;
			ret.first -= lsseg[k][p-1].first, ret.second -= lsseg[k][p-1].second;
			return ret;
		}
		P lval = query(a, b, k*2, l, (l+r)/2, x);
		P rval = query(a, b, k*2+1, (l+r)/2+1, r, x);
		return ope(lval, rval);
	}
	P query(int a, int b, int x)
	{
		return query(a, b, 1, 0, (1<<size)-1, x);
	}
};

ll n, Q, B;
ll x1[75005], x2[75005], y1[75005], y2[75005], a[75005], b[75005];
ll asum[75005], bsum[75005];
vector<T> lseg[1005], rseg[1005];
vector<P> lsseg[1005], rsseg[1005];
SegTree seg(17);

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	rep(i, 1, n) cin >> x1[i] >> x2[i] >> y1[i] >> a[i] >> b[i] >> y2[i], x2[i]++;
	
	rep(i, 1, n) asum[i] = asum[i-1] + a[i], bsum[i] = bsum[i-1] + b[i];
	rep(i, 1, n) seg.update(i, T(x1[i], P(-a[i], y1[i]-b[i])), T(x2[i], P(-a[i], y2[i]-b[i])));
	seg.init();
	
	ll ans = 0, l, r, x;
	cin >> Q;
	rep(q, 1, Q){
		cin >> l >> r >> x;
		x = (x+ans) % 1000000000;
		ll ansa = asum[r] - asum[l-1], ansb = bsum[r] - bsum[l-1];
		P res = seg.query(l, r, x);
		ansa += res.first, ansb += res.second;
		ans = ansa * x + ansb;
		cout << ans << "\n";
	}
	flush(cout);
	
	return 0;
}