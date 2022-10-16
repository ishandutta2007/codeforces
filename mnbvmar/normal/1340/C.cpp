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

int n, m, green, red;
vi islands;

int dp[11 * 1000][1100];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m;
	for (int i = 0; i < m; ++i) {
		int v;
		cin >> v;
		islands.push_back(v);
	}
	sort(ALL(islands));
	cin >> green >> red;

	memset(dp, 0x3d, sizeof(dp));
	queue<pii> q0, q1;

	const int inf = dp[0][0];
	dp[0][0] = 0;

	q0.push({0, 0});

	while (!q0.empty() || !q1.empty()) {
		if (q0.empty()) {
			swap(q0, q1);
		}

		auto [idx, tm] = q0.front();
		q0.pop();

		if (idx > 0) {
			const int ntm = tm + (islands[idx] - islands[idx - 1]);
			if (ntm <= green && dp[idx - 1][ntm] == inf) {
				dp[idx - 1][ntm] = dp[idx][tm];
				q0.push({idx - 1, ntm});
			}
		}
		if (idx < m - 1) {
			const int ntm = tm + (islands[idx + 1] - islands[idx]);
			if (ntm <= green && dp[idx + 1][ntm] == inf) {
				dp[idx + 1][ntm] = dp[idx][tm];
				q0.push({idx + 1, ntm});
			}
		}
		if (tm == green && dp[idx][0] == inf) {
			dp[idx][0] = dp[idx][tm] + 1;
			q1.push({idx, 0});
		}
	}

	ll ans = 1e18;
	for (int tm = 0; tm <= green; ++tm) {
		if (dp[m - 1][tm] != inf) {
			ans = min<ll>(ans, tm + (ll)dp[m - 1][tm] * (green + red));
		}
	}

	if (ans > 1e17) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
	}
}