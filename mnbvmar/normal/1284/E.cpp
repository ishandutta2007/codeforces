//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace __gnu_pbds;
using namespace std;
 
template <typename T>
using ordered_set =
	tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
#define sim template < class c
#define ris return * this
#define dor > debug & operator <<
#define eni(x) sim > typename \
  enable_if<sizeof dud<c>(0) x 1, debug&>::type operator<<(c i) {
sim > struct rge { c b, e; };
sim > rge<c> range(c i, c j) { return rge<c>{i, j}; }
sim > auto dud(c* x) -> decltype(cerr << *x, 0);
sim > char dud(...);
struct debug {
#ifdef LOCAL
~debug() { cerr << endl; }
eni(!=) cerr << boolalpha << i; ris; }
eni(==) ris << range(begin(i), end(i)); }
sim, class b dor(pair < b, c > d) {
  ris << "(" << d.first << ", " << d.second << ")";
}
sim dor(rge<c> d) {
  *this << "[";
  for (auto it = d.b; it != d.e; ++it)
	*this << ", " + 2 * (it == d.b) << *it;
  ris << "]";
}
#else
sim dor(const c&) { ris; }
#endif
};
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "
 
#define shandom_ruffle random_shuffle

#define int ll 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;


struct Point {
	int x, y;

	Point operator-(const Point &p) const { return {x-p.x, y-p.y}; }
	Point operator+(const Point &p) const { return {x+p.x, y+p.y}; }
	ll CrossProd(const Point &p) const {
		return (ll)x*p.y - (ll)y * p.x;
	}
	bool operator<(const Point &p) const {
		return pii(x, y) < pii(p.x, p.y);
	}
};

ll CrossProd(const Point &O, const Point &A, const Point &B) {
	return (A - O).CrossProd(B - O);
}

const Point origin{0, 0};

bool AngleComp(const Point &A, const Point &B) {
	bool aorig = (A < origin);
	bool borig = (B < origin);
	if (aorig != borig) { return aorig > borig; }

	return A.CrossProd(B) > 0;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;
	vector<Point> pts(n);

	for (int i = 0; i < n; ++i) {
		cin >> pts[i].x >> pts[i].y;
	}

	ll ans = 0;

	vector<Point> other_pts;
	for (int mid = 0; mid < n; ++mid) {
		other_pts.clear();
		for (int i = 0; i < n; ++i) {
			if (i != mid) { other_pts.push_back(pts[i]); }
		}

		for (auto &pt : other_pts) {
			pt = pt - pts[mid];
		}
		sort(ALL(other_pts), AngleComp);

		const int sz = n - 1;
		for (int i = 0; i < sz; ++i) {
			other_pts.push_back(other_pts[i]);
		}

		ll numbad = 0;

		int rptr = 0;
		for (int i = 0; i < sz; ++i) {
			rptr = max(rptr, i);
			while (rptr < SZ(other_pts)-1 &&
					other_pts[i].CrossProd(other_pts[rptr+1]) > 0) {
				++rptr;
			}

			ll szbad = rptr - i;
			numbad += szbad * (szbad - 1) / 2;
		}

		debug() << imie(mid) << imie(numbad);

		ll total = (ll)sz * (sz - 1) * (sz - 2) / 6;
		debug() << imie(total - numbad);
		ans += total - numbad;
	}

	ans *= (n - 4);
	assert(ans % 2 == 0);
	cout << ans / 2 << "\n";
}