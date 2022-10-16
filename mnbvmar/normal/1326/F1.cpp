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

const int MAXN = 18;
ll dp[1 << MAXN][MAXN];
ll conv[1 << MAXN];

//~ vi outs[1 << MAXN];
vi at_size[MAXN + 1];
vi eout[1<<MAXN][MAXN];
vi noeout[1<<MAXN][MAXN];
int n;

bool is_edge[MAXN][MAXN];

void Brute(int idx, int flip_msk) {
	debug() << imie(idx) << imie(flip_msk);
	//~ for (int i = 0; i < (1 << n); ++i) {
		//~ for (int j = 0; j < n; ++j) {
			//~ cout << dp[i][j] << " ";
		//~ }
		//~ cout << "\n";
	//~ }
	
	if (idx == n - 1) {
		for (int i = 0; i < n; ++i) {
			conv[flip_msk] += dp[(1 << n) - 1][i];
		}
		return;
	}
	
	for (int msk : at_size[idx+1]) {
		for (int i = 0; i < n; ++i) {
			if (!dp[msk][i]) { continue; }

			for (int j : eout[msk][i]) {
				dp[msk | (1 << j)][j] += dp[msk][i];
			}
			for (int j : noeout[msk][i]) {
				dp[msk | (1 << j)][j] += dp[msk][i];
			}
		}
	}

	Brute(idx + 1, flip_msk);

	for (int msk : at_size[idx+1]) {
		for (int i = 0; i < n; ++i) {
			if (!dp[msk][i]) { continue; }

			for (int j : noeout[msk][i]) {
				dp[msk | (1 << j)][j] -= dp[msk][i];
			}
		}
	}

	Brute(idx + 1, flip_msk | (1 << idx));

	for (int msk : at_size[idx+1]) {
		for (int i = 0; i < n; ++i) {
			if (!dp[msk][i]) { continue; }

			for (int j : eout[msk][i]) {
				dp[msk | (1 << j)][j] -= dp[msk][i];
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;

	vector<string> s(n);
	for (string &x : s) { cin >> x; }

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			is_edge[i][j] = (s[i][j] == '1');
		}
	}

	for (int mask = 0; mask < (1 << n); ++mask) {
		at_size[__builtin_popcount(mask)].push_back(mask);
		for (int i = 0; i < n; ++i) {
			if (!((mask >> i) & 1)) { continue; }
			for (int j = 0; j < n; ++j) {
				if ((mask >> j) & 1) { continue; }
				if (is_edge[i][j]) {
					eout[mask][i].push_back(j);
				} else {
					noeout[mask][i].push_back(j);
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		dp[1 << i][i] = 1;
	}
	Brute(0, 0);

	//~ for (int i = 0; i < (1 << (n - 1)); ++i) {
		//~ cout << conv[i] << " ";
	//~ }
	//~ cout << "\n";

	for (int bit = 1; bit < (1 << (n - 1)); bit <<= 1) {
		for (int i = 0; i < (1 << (n - 1)); ++i) {
			if (i & bit) {
				conv[i ^ bit] -= conv[i];
			}
		}
	}

	for (int i = 0; i < (1 << (n - 1)); ++i) {
		cout << conv[i] << " ";
	}
	cout << "\n";
}