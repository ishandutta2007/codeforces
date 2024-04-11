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

bool dp[2048][2048];
int can_have[2048][10];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, k;
	cin >> n >> k;

	vector<string> digits = {
		"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"
	};

	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;

		for (int d = 0; d < 10; ++d) {
			int ans = 0;
			for (int j = 0; j < 7; ++j) {
				if (digits[d][j] < s[j]) {
					ans = -1;
					break;
				}
				ans += digits[d][j] - s[j];
			}

			can_have[i][d] = ans;
			debug() << imie(i) << imie(d) << imie(ans);
		}
	}

	dp[n][0] = true;

	for (int loc = n - 1; loc >= 0; --loc) {
		for (int i = 0; i <= k; ++i) {
			for (int d = 0; d < 10; ++d) {
				int x = can_have[loc][d];
				if (x == -1 || x > i) { continue; }
				dp[loc][i] |= dp[loc + 1][i - x];
			}
		}
	}

	if (!dp[0][k]) {
		cout << "-1\n";
		return 0;
	}

	string ans;
	int curk = k;
	for (int loc = 0; loc < n; ++loc) {
		assert(dp[loc][curk]);
		for (int d = 9; d >= 0; --d) {
			int x = can_have[loc][d];
			if (x == -1 || x > curk) { continue; }
			debug() << imie(d) << imie(x) << imie(curk);
			if (!dp[loc+1][curk-x]) { continue; }
			ans += to_string(d);
			curk -= x;
			break;
		}
	}

	cout << ans << "\n";
}