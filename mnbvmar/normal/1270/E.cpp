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
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;

	const int M = 1e7;

	vector<pii> pts(n);
	for (auto &x : pts) {
		cin >> x.st >> x.nd;
		x.st += M; x.nd += M;
	}

	vector<int> rems[2];
	

	while (true) {
		rems[0].clear(); rems[1].clear();
		for (int i = 0; i < n; ++i) {
			int a = (pts[i].st + pts[i].nd) % 2;
			rems[a].push_back(i);
		}

		if (!rems[0].empty() && !rems[1].empty()) {
			cout << SZ(rems[0]) << "\n";
			for (int x : rems[0]) { cout << x+1 << " "; }
			cout << "\n";
			return 0;
		}
		
		rems[0].clear(); rems[1].clear();
		for (int i = 0; i < n; ++i) {
			rems[pts[i].st % 2].push_back(i);
		}
		if (!rems[0].empty() && !rems[1].empty()) {
			cout << SZ(rems[0]) << "\n";
			for (int x : rems[0]) { cout << x+1 << " "; }
			cout << "\n";
			return 0;
		}
		for (int i = 0; i < n; ++i) {
			pts[i].st /= 2;
			pts[i].nd /= 2;
		}
	}
}