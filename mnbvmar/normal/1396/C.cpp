//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

using namespace std;

//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
//~ using namespace __gnu_pbds;
//~ template <typename T>
//~ using ordered_set =
	//~ tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
 
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

#ifdef LOCAL
mt19937 rng(unsigned(69));
#else
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#endif
#define rand rng

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int kMaxN = 1.5e6;
const ll kInfty = 2e18;

ll r1, r2, r3, C;
ll dp[kMaxN][2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n >> r1 >> r2 >> r3 >> C;
	vll vals(n + 1);
	vll best_one(n + 1);
	vll best_two(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> vals[i];
		best_one[i] = vals[i] * r1 + r3;
		best_two[i] = min({best_one[i], (vals[i] + 2) * r1, r1 + r2});
		debug() << imie(i) << imie(best_one[i]) << imie(best_two[i]);
	}

	dp[0][0] = -C;
	dp[0][1] = kInfty;

	for (int i = 1; i <= n; ++i) {
		dp[i][0] = dp[i][1] = kInfty;
		dp[i][0] = min(dp[i-1][0] + best_one[i] + C,
		               dp[i-1][0] + best_two[i] + 3 * C);
		if (i >= 2) {
			dp[i][0] = min(dp[i][0], dp[i-2][0] + best_two[i-1] + best_two[i] + 4 * C);
		}
		if (i < n) {
			dp[i][1] = min(dp[i-1][0] + best_two[i] + C,
						   dp[i-1][1] + best_two[i] + 2 * C);
		} else {
			dp[i][0] = min({dp[i][0], dp[i-1][1] + best_one[i] + 2 * C,
				            dp[i-1][1] + best_two[i] + 4 * C});
		}
		debug() << imie(dp[i][0]) << imie(dp[i][1]) << imie(i);
	}

	cout << min(dp[n][0], dp[n][1]) << "\n";
}