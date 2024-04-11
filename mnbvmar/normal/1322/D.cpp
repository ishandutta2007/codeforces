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

struct Mask {
	int base;
	int val;

	int ShiftUp(int delta) const {
		return (delta > 20) ? 0 : (val >> delta);
	}

	bool operator<(const Mask &rhs) const {
		return pii(base, val) < pii(rhs.base, rhs.val);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, m;
	cin >> n >> m;
	vi aggr(n);
	vi costs(n);
	vi cnts(m + 1);
	for (int &x : aggr) {
		cin >> x;
		++cnts[x];
	}
	for (int &x : costs) { cin >> x; }

	vi profit(n + m + 1);
	for (int i = 1; i <= n + m; ++i) {
		cin >> profit[i];
	}

	vector<Mask> avail_masks;

	avail_masks.push_back(Mask{0, 0});

	int max_val = 0;
	for (int base = 1; base <= m; ++base) {
		max_val /= 2;
		max_val += cnts[base];
		for (int i = 1; i <= max_val; ++i) {
			avail_masks.push_back(Mask{base, max_val});
		}
	}

	map<Mask, int> dp;
	dp[Mask{0, 0}] = 0;
	int ans = 0;

	for (int loc = n - 1; loc >= 0; --loc) {
		map<Mask, int> new_dp;
		int ag = aggr[loc];
		debug() << imie(loc);
		for (auto &&[old_mask, old_res] : dp) {
			if (old_mask.base > ag) { continue; }

			
			int new_val = old_mask.ShiftUp(ag - old_mask.base);
			int new_res = old_res - costs[loc] + profit[ag];
			if (new_val & 1) {
				for (int i = 0;; ++i) {
					if (i) {
						new_res += profit[ag + i];
					}
					if (new_val & (1 << i)) {
						new_val ^= (1 << i);
					} else {
						new_val ^= (1 << i);
						break;
					}
				}
			} else {
				new_val += 1;
			}

			debug() << imie(old_mask.base) << old_mask.val << imie(old_res) << imie(ag) << imie(new_val) <<
				imie(new_res);

			Mask new_mask{ag, new_val};
			if (new_dp.count(new_mask)) {
				new_dp[new_mask] = max(new_dp[new_mask], new_res);
			} else {
				new_dp[new_mask] = new_res;
			}
		}

		for (auto &info : new_dp) {
			debug() << imie(info.st.base) << imie(info.st.val) << imie(info.nd);
			ans = max(ans, info.nd);
			if (dp.count(info.st)) {
				dp[info.st] = max(dp[info.st], info.nd);
			} else {
				dp[info.st] = info.nd;
			}
		}
	}

	cout << ans << "\n";
}