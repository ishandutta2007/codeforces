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

struct Tree {
	struct Node {
		int min_val{0};
		int add_push{0};
		ll total{0};
	};

	vector<Node> nodes;
	int base;

	Tree(int n) : base(1) {
		while (base <= n + 3) { base *= 2; }
		nodes.resize(base * 2);
	}

	int lq, rq, vq;

	void Touch(int v, int len) {
		if (v < base) {
			for (int s : {v * 2, v * 2 + 1}) {
				//~ #warning
				//~ assert(!(s == 41 && len == 32));
				nodes[s].min_val += nodes[v].add_push;
				nodes[s].add_push += nodes[v].add_push;
				nodes[s].total += nodes[v].add_push * ll(len) / 2;
				debug() << imie(s) << imie(nodes[s].total) << imie(nodes[v].add_push) << imie(len);
			}
			nodes[v].add_push = 0;
		}
	}

	void AddRec(int lb, int rb, int v) {
		if (lb >= rq || rb <= lq) { return; }
		if (lq <= lb && rb <= rq) {
			nodes[v].min_val += vq;
			nodes[v].add_push += vq;
			nodes[v].total += ll(vq) * (rb - lb);
			debug() << imie(v) << imie(nodes[v].total);
			return;
		}
		Touch(v, rb - lb);
		const int mid = (lb + rb) / 2;
		AddRec(lb, mid, v * 2);
		AddRec(mid, rb, v * 2 + 1);
		nodes[v].min_val = nodes[v * 2 + 1].min_val;
		nodes[v].total = nodes[v * 2].total + nodes[v * 2 + 1].total;
		debug() << imie(v) << imie(nodes[v].total);
	}

	void Add(int L, int R, int val) {
		lq = L; rq = R; vq = val;
		AddRec(0, base, 1);
	}

	int GetFirstEnough(int val) {
		int v = 1;
		int len = base;
		while (v < base) {
			Touch(v, len);
			if (nodes[v * 2].min_val <= val) {
				v *= 2;
			} else {
				v = v * 2 + 1;
			}
			len /= 2;
		}
		return v - base;
	}

	pii Reach(int where, int val) {
		{
			vi a;
			int vx = where + base;
			while (vx >= 1) { a.push_back(vx); vx /= 2; }
			int len = base;
			while (!a.empty()) {
				Touch(a.back(), len);
				a.pop_back();
				len /= 2;
			}
		}
		
		int len = 1;
		int v = where + base;
		debug() << imie(v) << imie(nodes[v].total);
		ll rem = val - nodes[v].total;
		while (true) {
			debug() << imie(v) << imie(rem);
			if (v == 1) { return {2e9, 2e9}; }
			if (v % 2 == 0) {
				if (rem < nodes[v + 1].total) {
					break;
				}
				rem -= nodes[v + 1].total;
			}
			v /= 2;
			len *= 2;
		}
		v += 1;
		while (v < base) {
			Touch(v, len);
			if (rem < nodes[v * 2].total) {
				v *= 2;
			} else {
				rem -= nodes[v * 2].total;
				v = v * 2 + 1;
			}
			len /= 2;
		}
		return {v - base, int(rem)};
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, q;
	cin >> n >> q;
	Tree tree(n + 1);
	for (int i = 0; i < n; ++i) {
		int a;
		cin >> a;
		tree.Add(i, i + 1, a);
	}

	while (q--) {
		int type, x, y;
		cin >> type >> x >> y;
		debug() << imie(type) << imie(x) << imie(y);
		if (type == 1) {
			int cur = tree.GetFirstEnough(y - 1), last = y;
			while (cur < x) {
				last = tree.nodes[tree.base + cur].min_val;
				int nxt = min(x, tree.GetFirstEnough(last - 1));
				debug() << imie(cur) << imie(nxt) << imie(last);
				tree.Add(cur, nxt, y - last);
				cur = nxt;
			}
		} else {
			--x;
			int cur = max(x, tree.GetFirstEnough(y));
			int ans = 0;
			while (cur < n) {
				debug() << imie(cur);
				auto [first_no, rem] = tree.Reach(cur, y);
				debug() << imie(first_no) << imie(rem);
				y = rem;
				ans += min(n, first_no) - cur;
				if (first_no >= n) { break; }
				cur = tree.GetFirstEnough(y);
			}
			cout << ans << "\n";
		}
	}
}