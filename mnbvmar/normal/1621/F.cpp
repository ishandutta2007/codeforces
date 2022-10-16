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
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

void Test() {
	ll final_ans = 0;
	auto Offer = [&](ll x) {
		final_ans = max(final_ans, x);
	};

	int n;
	ll a, b, c;
	cin >> n >> a >> b >> c;

	string s;
	cin >> s;

	if (n == 1) {
		cout << "0\n";
		return;
	}
	const int init_cnt_0 = count(ALL(s), '0');
	if (init_cnt_0 == 0) {
		cout << b << "\n";
		return;
	}
	if (init_cnt_0 == n) {
		cout << a << "\n";
		return;
	}

	for (int start_type : {0, 1}) {
		debug() << imie(start_type);
		int cnt_11 = 0;
		int cnt_0 = 0;
		int cnt_inc = 0;
		vector<int> border_0;
		vector<int> between_0;

		for (int i = 0; i < n; ++i) {
			if (i && s[i - 1] == '1' && s[i] == '1') {
				++cnt_11;
			}
			if (s[i] == '0') {
				++cnt_0;
			}
			if (i && s[i - 1] == '1' && s[i] == '0') {
				int j = i + 1;
				while (j < n && s[j] == '0') { ++j; }
				if (j < n) {
					if (j - i == 1) {
						++cnt_inc;
					} else {
						between_0.push_back(j - i);
					}
				}
			}
		}
		{
			int j = 0;
			while (s[j] != '1') { ++j; }
			if (j >= 2) { border_0.push_back(j); }
		}
		{
			int j = n - 1;
			while (s[j] != '1') { --j; }
			if (j < n - 2) { border_0.push_back((n - 1) - j); }
		}

		sort(ALL(between_0), greater<int>());
		sort(ALL(border_0), greater<int>());
		debug() << imie(cnt_11) << imie(cnt_0);
		debug() << imie(border_0) << imie(between_0) << imie(cnt_inc);

		ll cur_score = 0;
		for (int cur_type = start_type;; cur_type ^= 1) {
			if (cur_type == 1) {
				if (cnt_11 == 0) {
					break;
				} else {
					--cnt_11;
					cur_score += b;
				}
			} else {
				if (cnt_0 == 0) { break; }
				if (!between_0.empty() && cnt_11 > 0) {
					cur_score += a;
					--cnt_0;
					--between_0.back();
					if (between_0.back() == 1) {
						between_0.pop_back();
						++cnt_inc;
					}
				} else if (!border_0.empty() && cnt_11 > 0) {
					cur_score += a;
					--cnt_0;
					--border_0.back();
					if (border_0.back() == 1) {
						border_0.pop_back();
					}
				} else {
					if (!border_0.empty() || !between_0.empty()) { Offer(cur_score + a); }
					if (cnt_inc > 0) {
						--cnt_inc;
						cur_score -= c;
						--cnt_0;
						++cnt_11;
					} else {
						cur_score -= c;
						--cnt_0;
					}
				}
			}

			debug() << ":" << imie(cur_score);
			debug() << imie(cnt_11) << imie(cnt_0) << imie(border_0) << imie(between_0) << imie(cnt_inc);
			Offer(cur_score);
		}
	}

	cout << final_ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	int t;
	cin >> t;
	while (t--) {
		Test();
	}
}