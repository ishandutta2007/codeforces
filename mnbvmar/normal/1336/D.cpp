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
#ifdef DEBLOCAL
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

#ifdef DEBLOCAL
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

int n;
int dbginit[200];
int dbgcur[200];

ll Triples(int x) {
	return (ll)x * (x - 1) * (x - 2) / 6;
}

pll DbgGet() {
	debug() << range(dbgcur + 1, dbgcur + n + 1);
	ll a = 0, b = 0;
	for (int i = 1; i <= n; ++i) {
		a += Triples(dbgcur[i]);
	}
	for (int i = 1; i + 2 <= n; ++i) {
		b += (ll)dbgcur[i] * dbgcur[i + 1] * dbgcur[i + 2];
	}
	return {a, b};
}

pll Add(int v) {
#ifdef LOCAL
	++dbgcur[v];
	auto ans = DbgGet();
	debug() << imie(v) << imie(ans);
	return ans;
#else
	cout << "+ " << v << endl;
	ll a, b;
	cin >> a >> b;
	return {a, b};
#endif
}

void Answer(vi init) {
#ifdef LOCAL
	for (int i = 1; i <= n; ++i) {
		assert(dbginit[i] == init[i]);
	}
	cout << "OK\n";
#else
	cout << "!";
	for (int i = 1; i <= n; ++i) { cout << " " << init[i]; }
	cout << endl;
#endif
}

int main() {
	//~ int n;
	cin >> n;

#ifdef LOCAL
	for (int i = 1; i <= n; ++i) {
		cin >> dbginit[i];
		dbgcur[i] = dbginit[i];
	}
#endif

	vector<pll> answers;
	{
		ll x, y;
#ifdef LOCAL
		tie(x, y) = DbgGet();
#else
		cin >> x >> y;
#endif
		answers.emplace_back(x, y);
	}

	vi order{1};
	for (int i = n - 1; i >= 2; --i) { order.push_back(i); }
	order.push_back(1);

	for (int v : order) {
		answers.push_back(Add(v));
	}

	vi ans(n + 1, -1);
	vector<bool> need(n + 1, false);
	vector<bool> is_small(n + 1, false);

	for (int k = 0;; ++k) {
		int diff = answers[n].st - answers[n-1].st;
		if (Triples(k + 2) - Triples(k + 1) == diff) {
			ans[1] = k;
			need[1] = true;
			break;
		}
	}

	for (int i = 1; i < SZ(order) - 1; ++i) {
		int v = order[i];
		int diff = answers[i+1].st - answers[i].st;
		if (diff == 0) { is_small[v] = true; continue; }
		for (int k = 0;; ++k) {
			if (Triples(k + 1) - Triples(k) == diff) {
				ans[v] = k;
				need[v] = true;
				break;
			}
		}
	}

#define PB push_back
	vector<vector<vi>> checks(n + 1);
	{
		checks[3].emplace_back();
		checks[3].back().PB(2); checks[3].back().PB(0);
		checks[3].back().PB(3); checks[3].back().PB(0);
		checks[3].back().PB(answers[1].nd - answers[0].nd);
	}
	for (int i = 1; i < SZ(order); ++i) {
		int v = order[i];
		vi what;
		if (v >= 3) {
			what.PB(v-2); what.PB(v-2==1 ? 1 : 0); what.PB(v - 1); what.PB(0);
		}
		if (v >= 2) {
			what.PB(v - 1); what.PB(v-1==1 ? 1 : 0); what.PB(v + 1); what.PB(v+1==n?0:1);
		}
		if (v <= n - 2) {
			what.PB(v + 1);  what.PB(1); what.PB(v + 2); what.PB(v+2==n?0:1);
		}
		int where = *max_element(ALL(what));
		what.push_back(answers[i + 1].nd - answers[i].nd);
		debug() << imie(where) << imie(what);
		checks[where].push_back(what);
	}

	debug() << imie(ans) << imie(need) << imie(is_small);

	function<void(int)> Bt = [&](int loc) {
		for (auto &chk : checks[loc - 1]) {
			int cur = 0;
			for (int i = 3; i < SZ(chk); i += 4) {
				int coef = ans[chk[i-3]] + chk[i - 2];
				coef *= ans[chk[i-1]] + chk[i];
				cur += coef;
			}
			if (cur != chk.back()) {
				return;
			}
		}

		if (loc == n + 1) {
			debug() << range(ans.begin() + 1, ans.end());
			Answer(ans);
			exit(0);
		}

		if (need[loc]) {
			return Bt(loc + 1);
		}

		for (int cnt = 0; cnt <= n; ++cnt) {
			if (is_small[loc] && cnt >= 2) { break; }
			ans[loc] = cnt;
			Bt(loc + 1);
		}
	};

	Bt(2);
	assert(false);
}