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

struct SegTree {
	struct Node {
		ll push;
		ll max;

		Node() : push(0), max(0) {}
	};

	vector<Node> data;
	int base;

	SegTree(int n) : base(1) {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
	}

	void Push(int v) {
		if (v < base) {
			for (int s : {v*2, v*2+1}) {
				data[s].push += data[v].push;
				data[s].max += data[v].push;
			}
		}
		data[v].push = 0;
	}

	void AddValRec(int lv, int rv, int lbase, int rbase, ll what, int v) {
		if (lv >= rbase || rv <= lbase) { return; }
		if (lv <= lbase && rbase <= rv) {
			data[v].push += what;
			data[v].max += what;
			return;
		}
		Push(v);

		const int mid = (lbase + rbase) / 2;
		AddValRec(lv, rv, lbase, mid, what, v * 2);
		AddValRec(lv, rv, mid, rbase, what, v * 2 + 1);

		data[v].max = max(data[v*2].max, data[v*2+1].max);
	}

	void AddVal(int L, int R, ll what) {
		AddValRec(L, R, 0, base, what, 1);
	}

	ll GetMax() {
		return data[1].max;
	}
};

int n, m, p;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n >> m >> p;

	const int B = 1000 * 1000 + 1000;

	SegTree tree(B);

	map<int, int> weapons, shields;
	for (int i = 0; i < n; ++i) {
		int a, cost;
		cin >> a >> cost;
		if (weapons.count(a)) {
			weapons[a] = min(weapons[a], cost);
		} else {
			weapons[a] = cost;
		}
	}

	for (int i = 0; i < m; ++i) {
		int a, cost;
		cin >> a >> cost;
		if (shields.count(a)) {
			shields[a] = min(shields[a], cost);
		} else {
			shields[a] = cost;
		}
	}

	vector<vector<pii>> monsters(B);
	for (int i = 0; i < p; ++i) {
		int def, atk, cost;
		cin >> def >> atk >> cost;
		monsters[def].emplace_back(atk, cost);
	}

	const ll M = 1e12;

	tree.AddVal(0, tree.base, -M);
	//~ debug() << imie(tree.GetMax());

	for (auto [a, cost] : shields) {
		debug() << imie(a) << imie(-cost);
		tree.AddVal(a, a + 1, M - cost);
		//~ debug() << imie(tree.GetMax());
	}

	ll ans = -1e18;

	for (int i = 1; i < B; ++i) {
		bool any = false;
		for (auto [atk, cost] : monsters[i - 1]) {
			debug() << imie(atk) << imie(B) << imie(cost);
			tree.AddVal(atk + 1, B, cost);
			any = true;
		}
		if (weapons.count(i)) {
			const ll cand = tree.GetMax() - weapons[i];
			debug() << imie(i) << imie(cand);
			ans = max(ans, cand);
		}
	}

	cout << ans << "\n";
}