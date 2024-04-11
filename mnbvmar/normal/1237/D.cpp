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

const int MAXN = 4e5;

int n;
int tracks[MAXN];
int pbad[MAXN];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tracks[i];
		tracks[i+n] = tracks[i+2*n] = tracks[i];
	}
	
	bool anybad = false;
	map<int, int> occurs;
	for (int i = 0; i < 3 * n; ++i) {
		pbad[i] = -1;
		auto iter = occurs.upper_bound(tracks[i] * 2);
		if (iter != occurs.end()) {
			pbad[i] = iter->nd;
		}
		anybad |= (pbad[i] >= 0);
		debug() << imie(i) << imie(pbad[i]);
		occurs[tracks[i]] = i;
		auto X = occurs.find(tracks[i]);
		occurs.erase(occurs.begin(), X);
	}
	
	if (!anybad) {
		for (int i = 0; i < n; ++i) {
			cout << "-1 ";
		}
		cout << "\n";
		return 0;
	}
	
	vi ans(n);
	int rptr = 0;
	for (int lptr = 0; lptr < n; ++lptr) {
		rptr = max(rptr, lptr);
		while (pbad[rptr+1] < lptr) { ++rptr; }
		ans[lptr] = rptr - lptr + 1;
	}
	
	for (int x : ans) { cout << x << " "; }
	cout << "\n";
}