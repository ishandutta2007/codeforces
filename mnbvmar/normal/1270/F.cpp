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

	string s;
	cin >> s;
	int n = SZ(s);

	const int B = 150; //(int)sqrt(n + 0.5);
	ll ans = 0;

	for (int ratio = 1; ratio < B; ++ratio) {
		vll bals{0};
		for (char ch : s) {
			ll nextbal = bals.back() - 1;
			nextbal += (ch == '1') * ratio;
			bals.push_back(nextbal);
		}
		sort(ALL(bals));

		ll last = -1e9;
		int cnt = 0;
		for (ll x : bals) {
			if (x != last) {
				last = x;
				ans += (ll)cnt * (cnt - 1) / 2;
				cnt = 1;
			} else {
				++cnt;
			}
		}
		ans += (ll)cnt * (cnt - 1) / 2;
	}

	vector<int> next1(n + 1);
	next1[n] = n;
	for (int i = n-1; i >= 0; --i) {
		if (s[i] == '1') {
			next1[i] = i;
		} else {
			next1[i] = next1[i + 1];
		}
	}

	for (int start = 0; start < n; ++start) {
		int one = next1[start], x = 1;
		while (one < n) {
			const int min_len = max(one - start + 1, B * x);
			if (start + min_len > n) { break; }
			const int next_one = next1[one + 1];
			const int max_len = next_one - start;
			if (min_len <= max_len) {
				const int fst_good = (min_len + x - 1) / x;
				const int lst_good = max_len / x;
				ans += lst_good - fst_good + 1;
			}

			one = next_one;
			++x;
		}
	}

	cout << ans << "\n";
}