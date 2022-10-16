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
		int max_val;
		int push;
		Node() : max_val(0), push(0) {}
	};
	
	vector<Node> nodes;
	int base;
	
	SegTree(int n) : base(1) {
		while (base < n + 5) { base *= 2; }
		nodes.resize(base * 2);
	}
	
	void Touch(int v) {
		if (v >= base) { return; }
		for (int s : {v * 2, v * 2 + 1}) {
			nodes[s].max_val += nodes[v].push;
			nodes[s].push += nodes[v].push;
		}
		nodes[v].push = 0;
	}
	
	void AddIntvRec(int lv, int rv, int val, int lbase, int rbase, int v) {
		if (lbase >= rv || rbase <= lv) { return; }
		if (lv <= lbase && rbase <= rv) {
			nodes[v].max_val += val;
			nodes[v].push += val;
			return;
		}
		Touch(v);
		
		const int mid = (lbase + rbase) / 2;
		AddIntvRec(lv, rv, val, lbase, mid, v * 2);
		AddIntvRec(lv, rv, val, mid, rbase, v * 2 + 1);
		nodes[v].max_val = max(nodes[v*2].max_val, nodes[v*2+1].max_val);
	}
	
	void AddIntv(int lv, int rv, int val) {
		AddIntvRec(lv, rv, val, 0, base, 1);
	}
	
	int GetMax() const {
		return nodes[1].max_val;
	}
};

const int kMaxN = 5e5;

int n;
int perm[kMaxN];
vi children[kMaxN];
int pre[kMaxN], post[kMaxN], curtm;

void Dfs(int v) {
	debug() << imie(v) << imie(children[v]);
	pre[v] = curtm++;
	for (int s : children[v]) {
		Dfs(s);
	}
	post[v] = curtm;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	cin >> n;
	vi order(n);
	for (int i = 0; i < n; ++i) {
		cin >> perm[i];
		order[perm[i] - 1] = i;
		perm[i] *= 2;
		perm[i + n] = perm[i] + 1;
	}
	
	set<int> added{-1, 2 * n + 10};
	
	for (int lbase : order) {
		for (int loc : {lbase, lbase + n}) {
			auto piter = added.lower_bound(loc);
			auto iter = prev(piter);
			
			debug() << imie(*iter) << imie(*piter);
			
			if (*piter < 0 && *iter > 2 * n) {
				
			} else if (*iter < 0) {
				children[*piter].push_back(loc);
			} else if (*piter > 2 * n) {
				children[*iter].push_back(loc);
			} else if (perm[*iter] > perm[*piter]) {
				children[*iter].push_back(loc);
			} else {
				children[*piter].push_back(loc);
			}
			
			added.insert(loc);
		}
	}
	
	Dfs(order[0]);
	
	SegTree tree(2 * n + 5);
	for (int i = 0; i < n; ++i) {
		tree.AddIntv(pre[i], post[i], 1);
	}
	
	pii best = {tree.GetMax(), 0};
	
	for (int shift = 1; shift < n; ++shift) {
		tree.AddIntv(pre[shift-1], post[shift-1], -1);
		tree.AddIntv(pre[shift+n-1], post[shift+n-1], 1);
		best = min(best, pii{tree.GetMax(), shift});
	}
	
	cout << best.st << " " << best.nd << "\n";
}