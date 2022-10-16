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
	vll data;
	int base;

	SegTree(int n) : base(1) {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
	}

	void AddVal(int v, int x) {
		v += base;
		while (v) {
			data[v] += x;
			v /= 2;
		}
	}

	ll GetSum(int L, int R) {
		if (L > R) { return 0; }
		L += base; R += base;
		if (L == R) { return data[L]; }
		ll ans = data[L] + data[R];

		while (L / 2 != R / 2) {
			if (L % 2 == 0) { ans += data[L+1]; }
			if (R % 2 == 1) { ans += data[R-1]; }
			L /= 2; R /= 2;
		}
		return ans;
	}
};

struct WoahSegTree {
	struct Node {
		ll sum;
		ll push;
		int cnt;

		Node() : sum(0), push(0), cnt(0) {}
	};

	vector<Node> data;
	int base;

	WoahSegTree(int n) : base(1) {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
		for (int i = 0; i < base; ++i) {
			data[base+i].cnt = 1;
		}
		for (int i = base-1; i > 0; --i) {
			data[i].cnt = data[i*2].cnt * 2;
		}
	}

	void Touch(int v) {
		if (v < base) {
			for (int s : {v*2, v*2+1}) {
				data[s].sum += data[v].push * data[s].cnt;
				data[s].push += data[v].push;
			}
		}
		data[v].push = 0;
	}

	void AddVal(int lbase, int rbase, int lv, int rv, int v, ll val) {
		if (lv >= rbase || rv <= lbase) { return; }
		Touch(v);
		if (lv <= lbase && rbase <= rv) {
			data[v].sum += val * data[v].cnt;
			data[v].push += val;
			return;
		}

		const int mid = (lbase + rbase) / 2;
		AddVal(lbase, mid, lv, rv, v*2, val);
		AddVal(mid, rbase, lv, rv, v*2+1, val);
		data[v].sum = data[v*2].sum + data[v*2+1].sum;
	}

	void Disable(int x) {
		int lbase = 0, rbase = base, v = 1;
		while (v < base) {
			Touch(v);
			const int mid = (lbase + rbase) / 2;
			if (x < mid) {
				rbase = mid; v *= 2;
			} else {
				lbase = mid; v = v * 2 + 1;
			}
		}
		Touch(v);
		data[v].cnt = 0;
		data[v].sum = 0;
		v /= 2;
		while (v) {
			data[v].sum = data[v*2].sum + data[v*2+1].sum;
			data[v].cnt = data[v*2].cnt + data[v*2+1].cnt;
			v /= 2;
		}
	}

	ll GetSum(int lbase, int rbase, int lv, int rv, int v) {
		if (lv >= rbase || rv <= lbase) { return 0; }
		Touch(v);
		if (lv <= lbase && rbase <= rv) { return data[v].sum; }
		const int mid = (lbase + rbase) / 2;
		return GetSum(lbase, mid, lv, rv, v*2) +
			GetSum(mid, rbase, lv, rv, v*2+1);
	}
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;

	vi perm(n);
	for (int &x : perm) { cin >> x; --x; }
	vi ploc(n);
	for (int i = 0; i < n; ++i) {
		ploc[perm[i]] = i;
	}

	WoahSegTree pref_cnt(n + 5);
	WoahSegTree suf_cnt(n + 5);
	SegTree inv_cnt(n + 5);

	vi inv_add(n);

	for (int loc = n - 1; loc >= 0; --loc) {
		inv_add[perm[loc]] = inv_cnt.GetSum(0, perm[loc]);
		inv_cnt.AddVal(perm[loc], 1);
	}

	priority_queue<int> addpref;
	priority_queue<int, vector<int>, greater<int>> addsuf;
	int median = 0;

	auto Add = [&](int v) {
		if (v <= median) {
			addpref.push(v);
		} else {
			addsuf.push(v);
		}
		
		while (SZ(addpref) > SZ(addsuf) + 1) {
			int x = addpref.top(); addpref.pop();
			addsuf.push(x);
		}
		while (SZ(addsuf) > SZ(addpref) + 1) {
			int x = addsuf.top(); addsuf.pop();
			addpref.push(x);
		}

		if (SZ(addsuf) > SZ(addpref)) {
			median = addsuf.top();
		} else {
			median = addpref.top();
		}
	};

	vll ans(n);
	ll cur_inv_cnt = 0;
	for (int val = 0; val < n; ++val) {
		cur_inv_cnt += inv_add[val];
		const int loc = ploc[val];
		pref_cnt.Disable(loc);
		suf_cnt.Disable(loc);

		suf_cnt.AddVal(0, suf_cnt.base, 0, loc, 1, 1);
		pref_cnt.AddVal(0, pref_cnt.base, loc + 1, pref_cnt.base, 1, 1);
		Add(loc);

		ll pref_inc = pref_cnt.GetSum(0, pref_cnt.base, 0, median, 1);
		ll suf_inc = suf_cnt.GetSum(0, suf_cnt.base, median, n, 1);

		debug() << imie(median) << imie(pref_inc) << imie(suf_inc) <<
			imie(cur_inv_cnt);
		
		ans[val] = cur_inv_cnt + pref_inc + suf_inc;
	}

	for (ll x : ans) {
		cout << x << " ";
	}
	cout << "\n";
}