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

const int kMaxN = 5e5;

struct Tree {
	struct Node {
		int max_suf;
		int sum;

		Node() : max_suf(0), sum(0) {}
	};
	vector<Node> data;
	int base;

	Tree(int n) : base(1) {
		while (base < n + 5) { base *= 2; }
		data.resize(base * 2);
	}

	Node Join(Node a, Node b) {
		Node ans;
		ans.sum = a.sum + b.sum;
		ans.max_suf = max(a.max_suf + b.sum, b.max_suf);
		return ans;
	}

	void Add(int v, int x) {
		debug() << imie(v) << imie(x);
		v += base;
		data[v].sum += x;
		data[v].max_suf += x;
		v /= 2;
		while (v) {
			data[v] = Join(data[v*2], data[v*2+1]);
			v /= 2;
		}
	}

	int GetMax() {
		return data[1].max_suf;
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;
	vi seq(n), add_order(n), rseq(n);
	for (int &x : seq) { cin >> x; --x; }
	for (int i = 0; i < n; ++i) {
		rseq[seq[i]] = i;
	}
	for (int &x : add_order) { cin >> x; --x; }

	//~ FU fu(n);
	vi ans(n);
	Tree tree(n + 2);

	int cur_val = n;
	for (int i = 0; i < n; ++i) {
		while (tree.GetMax() <= 0) {
			--cur_val;
			tree.Add(rseq[cur_val], 1);
		}
		ans[i] = cur_val + 1;

		int rem = add_order[i];
		tree.Add(rem, -1);
	}

	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}