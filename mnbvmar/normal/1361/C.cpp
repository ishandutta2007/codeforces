//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
#include "bits/stdc++.h"
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")

#define PB push_back
#define MP make_pair
#define LL long long
//~ #define int LL
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define R(i,n) REP(i,n)
#define VI vector<int>
#define PII pair<int,int>
#define LD long double
#define FI first
#define SE second
#define st FI
#define nd SE
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())

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

struct Euler {
  struct Edge { int nei, nr; };
  vector<vector<Edge>> slo;
  VI ans, ansid, used, deg, beg;
  int e_num, n;
  Euler() : e_num(0), n(-1) {}
  void AddEdge(int a, int b) {
    e_num++;
    if (a > n || b > n) {
      n = max(a, b);
      slo.resize(n + 2);
      deg.resize(n + 2);
      beg.resize(n + 2);
    }
    used.PB(0);
    slo[a].PB({b, e_num});
    slo[b].PB({a, e_num});
    deg[a]++; deg[b]++;
  }
  VI FindEuler() { // if used many times, please clear ans, beg, used
    used.PB(0);
    assert(SZ(used) > e_num);
    RE (i, n) { if (deg[i] % 2 == 1) { return VI(); } }
    int which = 0;
    while (slo[which].empty()) { ++which; }
    Go(which);
    return ans;
  }
private:
  void Go(int v) {
    //~ debug(v);
    while (beg[v] < SZ(slo[v])) {
      Edge& e = slo[v][beg[v]];
      beg[v]++;
      int nei = e.nei;
      if (used[e.nr]) { continue; }
      used[e.nr] = 1;
      Go(nei);
      ans.PB(nei);
      ansid.PB(e.nr);
    }
  }
};

int n;
vector<pii> vals;
vi recover;

bool CanHave(int k) {
	Euler euler;
	for (int i = 0; i < n; ++i) {
		int a = vals[i].st % (1 << k);
		int b = vals[i].nd % (1 << k);
		euler.AddEdge(a, b);
	}

	vi ans = euler.FindEuler();
	if (SZ(ans) != n) { return false; }
	vi ansid = euler.ansid;
	ans.push_back(ans[0]);

	debug() << imie(ans) << imie(ansid) << imie(k);

	recover.clear();
	for (int i = 0; i < n; ++i) {
		int from = ans[i], to = ans[i + 1], eid = ansid[i] - 1;

		if (vals[eid].st % (1 << k) == from && vals[eid].nd % (1 << k) == to) {
			recover.push_back(eid * 2 + 1);
			recover.push_back(eid * 2 + 2);
		} else if (vals[eid].st % (1 << k) == to && vals[eid].nd % (1 << k) == from) {
			recover.push_back(eid * 2 + 2);
			recover.push_back(eid * 2 + 1);
		} else {
			assert(false);
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	//~ Euler e;
	//~ e.AddEdge(2, 3);
	//~ e.AddEdge(3, 2);
	//~ debug() << imie(e.FindEuler());
	//~ return 0;

	cin >> n;
	vals.resize(n);
	for (auto &x : vals) { cin >> x.st >> x.nd; }

	recover.resize(2 * n);
	iota(ALL(recover), 1);

	int L = 0, R = 21;
	while (R - L > 1) {
		const int mid = (L + R) / 2;
		if (CanHave(mid)) {
			L = mid;
		} else {
			R = mid;
		}
	}

	cout << L << "\n";
	for (int v : recover) {
		cout << v << " ";
	}
	cout << "\n";
}