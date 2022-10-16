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

#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

// uw lib
// @s[0..n-1]  - napis dugoci @n.
// @r[0..2n-2] - tablica promieni palindromw.
// s: a   b   a   a   b   a   a   c   a   a   b   b   b   b   a   a   c   a   c
// r: 0 0 1 0 0 3 0 0 2 0 0 1 0 0 3 0 0 1 0 0 0 1 1 6 1 1 0 0 0 1 0 0 1 0 1 0 0
void Manacher(const char* s, int n, int* r) {
  for (int i = 0, m = 0, k = 0, p = 0; i < 2 * n - 1; m = i++ - 1) {
    while (p < k and i / 2 + r[m] != k)
      r[i++] = min(r[m--], (k + 1 - p++) / 2);
    while (k + 1 < n and p > 0 and s[k + 1] == s[p - 1])
      k++, p--;
    r[i] = (k + 1 - p++) / 2;
  }
}
//~ bool is_pal(int p, int k) { //Przedzia [p, k] obustronnie domknity
	//~ return r[p + k] >= (k - p + 1) / 2;
//~ }


void Test() {
	string s;
	cin >> s;

	int n = SZ(s);

	int ans = 0;
	int lans = -1, rans = -1;
	int trans = -1;

	for (int tr = 0; tr < 1; ++tr) {
		int *rad = new int[2 * n];
		Manacher(s.c_str(), n, rad);

		int max_len = 0;
		
		for (int i = 0; i < n; ++i) {
			if (s[i] != s[n-i-1]) { break; }
			if ((i+1) * 2 >= n) { continue; }
			max_len = i + 1;
		}

		int rgood = n - max_len;
		int lgood = max_len - 1;

		if (ans < 2 * max_len) {
			ans = max(ans, 2 * max_len);
			trans = tr;
			lans = lgood;
			rans = rgood;
		}

		auto Consider = [&](int L, int R) {
			if (L >= rgood || R <= lgood) { return; /* ? */ }
			int shrink = 0;
			if (R >= rgood) {
				shrink = max(shrink, R - rgood + 1);
			}
			if (L <= lgood) {
				shrink = max(shrink, lgood - L + 1);
			}

			L += shrink;
			R -= shrink;
			if (L <= R && (L == lgood + 1 || R == rgood - 1)) {
				int cand = 2 * max_len + (R - L + 1);
				if (cand < ans) { return; }
				debug() << imie(cand) << imie(L) << imie(R);
				ans = cand;
				if (L == lgood + 1) {
					lans = R;
					rans = rgood;
				} else {
					lans = lgood;
					rans = L;
				}
			}
		};

		for (int i = 0; i < n; ++i) {
			int r = rad[2 * i];
			int L = i - r;
			int R = i + r;
			//~ debug() << imie("!") << imie(L) << imie(R);
			Consider(L, R);
		}

		for (int i = 0; i < n - 1; ++i) {
			int r = rad[2 * i + 1];
			if (r) {
				int L = i - r + 1;
				int R = i + r;
				debug() << imie("!") << imie(L) << imie(R);
				Consider(L, R);
			}
		}

		delete[] rad;
		//~ reverse(ALL(s));
	}

	//~ if (trans) { reverse(ALL(s)); }
	debug() << imie(ans);
	debug() << imie(lans) << imie(rans) << imie(s);
	cout << s.substr(0, lans+1);
	cout << s.substr(rans, n - rans) << "\n";;
	//~ cout << ans << "\n";
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