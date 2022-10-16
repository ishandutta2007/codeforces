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
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const int mod = 1e9 + 7;

struct SegTree {
	vll data;
	int base;

	SegTree(int n) : base{1} {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
	}

	void AddVal(int loc, ll val) {
		loc += base;
		while (loc) {
			data[loc] += val;
			loc /= 2;
		}
	}

	ll GetSum(int L, int R) const {
		if (L > R) {return 0; }
		L += base;
		R += base;
		if (L == R) { return data[L]; }
		ll ans = data[L] + data[R];
		while (L / 2 != R / 2) {
			if (L % 2 == 0) { ans += data[L + 1]; }
			if (R % 2 == 1) { ans += data[R - 1]; }
			L /= 2; R /= 2;
		}
		return ans;
	}
};

void Renumber(vi &elems) {
	vll A;
	const int n = SZ(elems);
	for (int i = 0; i < n; ++i) {
		A.push_back((ll)elems[i] * n - i);
	}
	sort(ALL(A));
	A.resize(unique(ALL(A)) - A.begin());
	for (int i = 0; i < n; ++i) {
		const ll val = (ll)elems[i] * n - i;
		elems[i] = lower_bound(ALL(A), val) - A.begin();
	}
}

vi CountIncreasing(const vi &elems) {
	const int n = SZ(elems);
	SegTree st(n);
	vi ans(n);

	for (int i = 0; i < n; ++i) {
		const int cur = (1 + st.GetSum(0, elems[i] - 1)) % mod;
		ans[i] = cur;
		st.AddVal(elems[i], cur);
	}
	return ans;
}

vi CountSpecialIncreasing(SegTree &st, const vi &elems) {
	const int n = SZ(elems);
	vi ans(n);
	ans.back() = 1;
	st.AddVal(elems.back(), 1);
	
	for (int i = n - 2; i >= 0; --i) {
		const int cur = st.GetSum(elems[i] + 1, st.base - 1) % mod;
		ans[i] = cur;
		st.AddVal(elems[i], cur);
	}
	return ans;
}

void Test() {
	int n;
	cin >> n;
	vector<int> elems(n);
	for (int &x : elems) { cin >> x; }
	Renumber(elems);
	debug() << imie(elems);

	vi inc_count = CountIncreasing(elems);
	vi dec_count;
	vi bad_dec_count(n);
	{
		vi elems_flip = elems;
		reverse(ALL(elems_flip));
		for (int &x : elems_flip) {
			x = (n - 1) - x;
		}
		dec_count = CountIncreasing(elems_flip);
		reverse(ALL(dec_count));
	}
	debug() << imie(inc_count);
	debug() << imie(dec_count);

	vi suf_maxs;
	vector<bool> is_suf_max(n);
	{
		int cur_suf = -1;
		for (int i = n - 1; i >= 0; --i) {
			if (elems[i] > cur_suf) {
				cur_suf = elems[i];
				suf_maxs.push_back(elems[i]);
				is_suf_max[i] = true;
			}
		}
	}
	debug() << imie(suf_maxs);
	const int S = SZ(suf_maxs);
	vector<vi> subseq_ids(S);
	vector<vi> subseq_vals(S);

	for (int i = 0; i < n; ++i) {
		int which = lower_bound(ALL(suf_maxs), elems[i]) - suf_maxs.begin();
		// which -= is_suf_max[i];
		assert(0 <= which && which < S);
		subseq_ids[which].push_back(i);
		subseq_vals[which].push_back(elems[i]);
	}

	SegTree st(n);
	for (int gid = 0; gid < S; ++gid) {
		debug() << imie(subseq_ids[gid]) << imie(subseq_vals[gid]);
		auto cnts = CountSpecialIncreasing(st, subseq_vals[gid]);
		for (int i = 0; i < SZ(cnts); ++i) {
			bad_dec_count[subseq_ids[gid][i]] = cnts[i];
		}
	}

	ll ans = 0;
	for (int i = 0; i < n; ++i) {
		debug() << imie(i) << imie(inc_count[i]) << imie(dec_count[i]) << imie(bad_dec_count[i]);
		const int good_dec = (dec_count[i] - bad_dec_count[i] + mod) % mod;
		ans = (ans + (ll)inc_count[i] * good_dec) % mod;
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	
	int t;
	cin >> t;
	while (t--) { Test(); }
}