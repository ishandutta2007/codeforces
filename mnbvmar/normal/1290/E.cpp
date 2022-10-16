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

struct TreeBeats {
	struct Node {
		pii max_val[2] = {pii(-1e9, 0), pii(-1e9, 0)};
		int push_min = 1e9, push_add = 0;  // x := min(x, push_min) + push_add
		ll sum = 0;
		int size = 0;
		bool active = false;
	};

	vector<Node> nodes;
	int base;

	TreeBeats(int n) : base(1) {
		while (base < n + 2) { base *= 2; }
		nodes.resize(base * 2);
	}

	void Push(int v) {
		if (v < base) {
			int pmin = nodes[v].push_min;
			int padd = nodes[v].push_add;
			for (int s : {v * 2, v * 2 + 1}) {
				auto &N = nodes[s];
				assert(N.max_val[1].st < pmin);
				if (N.max_val[0].st > pmin) {
					N.sum -= (ll)(N.max_val[0].st - pmin) * N.max_val[0].nd;
					N.max_val[0].st = pmin;
				}
				N.sum += (ll)N.size * padd;
				N.max_val[0].st += padd;
				N.max_val[1].st += padd;

				N.push_min = min(N.push_min, pmin - N.push_add);
				N.push_add += padd;
			}
			nodes[v].push_min = 1e9;
			nodes[v].push_add = 0;
		}
	}

	ll GetSum() const {
		return nodes[1].sum;
	}

	void Update(int v) {
		auto &N = nodes[v];
		auto &L = nodes[v * 2];
		auto &R = nodes[v * 2 + 1];
		N.sum = L.sum + R.sum;
		N.size = L.size + R.size;

		int lptr = 0, rptr = 0;
		for (int i = 0; i < 2; ++i) {
			const int val = max(L.max_val[lptr].st, R.max_val[rptr].st);
			N.max_val[i].st = val;
			N.max_val[i].nd = 0;
			if (L.max_val[lptr].st == val) {
				N.max_val[i].nd += L.max_val[lptr++].nd;
			}
			if (R.max_val[rptr].st == val) {
				N.max_val[i].nd += R.max_val[rptr++].nd;
			}
		}
		N.active = L.active || R.active;
	}

	void ActivateRec(int pos, int value, int lbase, int rbase, int v) {
		if (v >= base) {
			nodes[v].active = true;
			nodes[v].size = 1;
			nodes[v].max_val[0] = pll(value, 1);
			nodes[v].sum = value;
			return;
		}
		Push(v);

		const int mid = (lbase + rbase) / 2;
		if (pos < mid) {
			ActivateRec(pos, value, lbase, mid, v * 2);
		} else {
			ActivateRec(pos, value, mid, rbase, v * 2 + 1);
		}
		Update(v);
	}

	void Activate(int pos, int value) {
		ActivateRec(pos, value, 0, base, 1);
	}

	void MinValueRec(int L, int R, int value, int lbase, int rbase, int v) {
		auto &N = nodes[v];
		if (R <= lbase || L >= rbase || N.max_val[0].st <= value) { return; }
		Push(v);
		
		if (L <= lbase && rbase <= R && N.max_val[1].st < value) {
			N.sum -= (ll)(N.max_val[0].st - value) * N.max_val[0].nd;
			N.max_val[0].st = value;
			N.push_min = min<ll>(N.push_min, value);
			return;
		}

		const int mid = (lbase + rbase) / 2;
		MinValueRec(L, R, value, lbase, mid, v * 2);
		MinValueRec(L, R, value, mid, rbase, v * 2 + 1);
		Update(v);
	}

	void MinValue(int L, int R, int value) {
		MinValueRec(L, R, value, 0, base, 1);
	}

	void AddOneRec(int L, int R, int lbase, int rbase, int v) {
		auto &N = nodes[v];
		if (R <= lbase || L >= rbase) { return; }
		Push(v);

		if (L <= lbase && rbase <= R) {
			N.sum += N.size;
			N.max_val[0].st += 1;
			N.max_val[1].st += 1;
			N.push_add += 1;
			return;
		}

		const int mid = (lbase + rbase) / 2;
		AddOneRec(L, R, lbase, mid, v * 2);
		AddOneRec(L, R, mid, rbase, v * 2 + 1);
		Update(v);
	}

	void AddOne(int L, int R) {
		AddOneRec(L, R, 0, base, 1);
	}
};

const int MAXN = 2e5;

int perm[MAXN];
int n;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> perm[i];
		--perm[i];
	}

	vll answ(n);

	for (int iter = 0; iter < 2; ++iter) {
		TreeBeats tb(n + 5);

		vi order(n);
		for (int i = 0; i < n; ++i) {
			order[perm[i]] = i;
		}

		ordered_set<int> os;

		for (int i = 0; i < n; ++i) {
			const int pos = order[i];
			os.insert(pos);
			const int idx = os.order_of_key(pos);
			
			tb.Activate(pos, i + 1);
			tb.AddOne(pos + 1, tb.base);
			tb.MinValue(0, pos, idx);
			answ[i] += tb.GetSum() - (ll)(i + 1) * (i + 2) / 2;
		}

		reverse(perm, perm + n);
	}

	int ah = 0;
	for (ll x : answ) { cout << x + (++ah) << "\n"; }
}