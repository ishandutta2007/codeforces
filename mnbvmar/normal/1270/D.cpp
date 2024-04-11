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

pii Ask(set<int> ids) {
	cout << "? ";
	for (int x : ids) { cout << x << " "; }
	cout << endl;
	int a, b;
	cin >> a >> b;
	return {b, a};
}

int main() {
	int n, k;

	cin >> n >> k;

	set<int> fst;
	for (int i = 1; i <= k; ++i) { fst.insert(i); }

	vector<pii> answers;
	answers.push_back(Ask(fst));
	auto [x, x_loc] = answers[0];

	for (int i = 1; i <= k; ++i) {
		set<int> other = fst;
		other.erase(i);
		other.insert(k + 1);
		answers.push_back(Ask(other));
	}

	int y = answers[x_loc].st;
	int ans = 1;
	if (x < y) {
		for (int i = 1; i <= k; ++i) {
			ans += (i != x_loc && answers[i].st > x);
		}
	} else {
		for (int i = 1; i <= k; ++i) {
			ans += (i != x_loc && answers[i].st >= x);
		}
	}

	cout << "! " << ans << endl;
}