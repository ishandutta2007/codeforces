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

int cur_ans;

struct FU {
	vi pnt;
	vector<bool> flip;
	vi cnt0, cnt1;

	FU(int n) : pnt(n), flip(n), cnt0(n), cnt1(n) {
		iota(ALL(pnt), 0);
		fill(ALL(cnt1), 1);
	}

	pair<int, bool> Find(int v) {
		if (v == pnt[v]) { return {v, false}; }
		auto [r, f] = Find(pnt[v]);
		pnt[v] = r;
		flip[v] = f ^ flip[v];
		return {r, flip[v]};
	}

	void Union(int ka, int kb, bool bit) {
		auto [a, fa] = Find(ka);
		auto [b, fb] = Find(kb);
		debug() << imie(a)<<imie(fa)<<imie(b)<<imie(fb);
		if (a == b) { return; }
		//~ if (a < b) { swap(a, b); }

		cur_ans -= min(cnt0[a], cnt1[a]);
		cur_ans -= min(cnt0[b], cnt1[b]);

		pnt[a] = b;
		flip[a] = (fa ^ fb ^ bit);
		debug() << imie(a) << imie(pnt[a]) << imie(flip[a]);
		if (flip[a]) { swap(cnt0[a], cnt1[a]); }
		cnt0[b] += cnt0[a];
		cnt1[b] += cnt1[a];
		debug() << imie(cnt0[b]) << imie(cnt1[b]);

		cur_ans += min(cnt0[b], cnt1[b]);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, k;
	cin >> n >> k;

	FU fu(k + 5);
	fu.cnt1[0] = 1e8;

	string init_state;
	cin >> init_state;

	vector<vi> xi(n);
	for (int i = 1; i <= k; ++i) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int x;
			cin >> x;
			--x;
			xi[x].push_back(i);
		}
	}

	for (int lamp = 0; lamp < n; ++lamp) {
		int need_parity = init_state[lamp] ^ '1';
		debug() << imie(lamp) << imie(xi[lamp]) << imie(need_parity);
		if (SZ(xi[lamp]) == 1) {
			fu.Union(0, xi[lamp][0], need_parity);
		} else if (SZ(xi[lamp]) == 2) {
			int a = xi[lamp][0];
			int b = xi[lamp][1];
			fu.Union(a, b, need_parity);
		} else if (SZ(xi[lamp]) > 2) {
			assert(false);
		}

		cout << cur_ans << "\n";
	}
	
}