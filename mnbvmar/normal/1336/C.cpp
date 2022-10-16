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

const int kMaxS = 3333;
const int mod = 998244353;

string s, t;
int n, m;

void Add(int &x, int y) {
	x += y;
	if (x >= mod) { x -= mod; }
}

int dp[kMaxS][kMaxS];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> s >> t;
	n = SZ(s);
	m = SZ(t);

	for (int i = 0; i <= n; ++i) {
		dp[0][i] = 1;
	}

	for (int i = 0; i < n; ++i) {
		for (int L = 0; L + i <= n; ++L) {
			int R = L + i;
			debug() << imie(i) << imie(L) << imie(R) << imie(dp[i][L]);
			if (L && (L - 1 >= m || s[i] == t[L - 1])) {
				Add(dp[i + 1][L - 1], dp[i][L]);
				//~ debug() << "a" << imie(dp[i+1][L-1]);
			}
			if (R >= m || s[i] == t[R]) {
				Add(dp[i + 1][L], dp[i][L]);
				//~ debug() << "b" << imie(dp[i+1][L]);
			}
		}
	}

	int ans = 0;
	for (int i = m; i <= n; ++i) {
		Add(ans, dp[i][0]);
	}
	cout << ans << "\n";
}