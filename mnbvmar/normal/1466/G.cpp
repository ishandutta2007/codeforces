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

const int mod = 1e9 + 7;
inline void add_mod(int &a, int b) {
	a += b;
	if (a >= mod) { a -= mod; }
}
inline void sub_mod(int &a, int b) {
	a -= b;
	if (a < 0) { a += mod; }
}
inline int mul_mod(int a, int b) {
	return (int)((ll)a * b % mod);
}
inline int pow_mod(int a, int n) {
	int r = 1;
	while (n) {
		if (n & 1) { r = mul_mod(r, a); }
		n >>= 1;
		a = mul_mod(a, a);
	}
	return r;
}
inline int inv_mod(int a) {
	return pow_mod(a, mod - 2);
}
inline int div_mod(int a, int b) {
	return mul_mod(a, inv_mod(b));
}

// start hashing

struct Hash {
private:
	static constexpr int kNumHashes = 2;
	static int a[kNumHashes], ia[kNumHashes];
	static vector<int> ps[kNumHashes], ips[kNumHashes];
	vector<int> ph[kNumHashes];

	void Initialize(int len) {
		if (ps[0].empty()) {
			mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
			uniform_int_distribution<int> distr(0, mod - 1);
			for (int b = 0; b < kNumHashes; ++b) {
				a[b] =  distr(rng);
				ia[b] = inv_mod(a[b]);
				ps[b] = ips[b] = {1};
			}
		}
		while ((int)ps[0].size() <= len) {
			for (int b = 0; b < kNumHashes; ++b) {
				ps[b].push_back(mul_mod(ps[b].back(), a[b]));
				ips[b].push_back(mul_mod(ips[b].back(), ia[b]));
			}
		}
	}

public:
	Hash() {}

	void Append(char ch) {
		const int sz = ph[0].size() - 1;
		for (int b = 0; b < kNumHashes; ++b) {
			int x = ph[b].back();
			add_mod(x, mul_mod(ps[b][sz], ch));
			ph[b].push_back(x);
		}
	}

	Hash(string s) {
		Initialize(s.size());
		for (int b = 0; b < kNumHashes; ++b) {
			ph[b].push_back(0);
		}
		for (char ch : s) {
			Append(ch);
		}
	}

	array<int, kNumHashes> Get(int L, int R) {
		array<int, kNumHashes> ans;
		for (int b = 0; b < kNumHashes; ++b) {
			int x = ph[b][R + 1];
			sub_mod(x, ph[b][L]);
			x = mul_mod(x, ips[b][L]);
			ans[b] = x;
		}
		return ans;
	}
};

int Hash::a[Hash::kNumHashes], Hash::ia[Hash::kNumHashes];
vector<int> Hash::ps[Hash::kNumHashes], Hash::ips[Hash::kNumHashes];

// end hashing

const int kMaxN = 2e5;

int n, q;
string s0, t;
Hash hlr, hrl;
int sufs[kMaxN][26];

void MakeHashes() {
	string lr, rl;
	string s0_rev = s0;
	reverse(s0_rev.begin(), s0_rev.end());
	int idx = 0;
	while (SZ(lr) < 1e6 + 10) {
		++idx;
		lr += s0;
		lr += t[__builtin_ctz(idx)];
		rl += s0_rev;
		rl += t[__builtin_ctz(idx)];
	}
	debug() << imie(lr.substr(0, 100));
	debug() << imie(rl.substr(0, 100));
	hlr = Hash(lr);
	hrl = Hash(rl);
}

void SolveQuery() {
	string w;
	int k;
	cin >> k >> w;
	const int sz = SZ(w);

	// Is in s0?
	int cnt_s0 = 0;
	for (int i = 0; i + sz <= SZ(s0); ++i) {
		bool is_in = true;
		for (int j = 0; j < sz; ++j) {
			if (s0[i + j] != w[j]) {
				is_in = false;
				break;
			}
		}
		cnt_s0 += is_in;
	}
	debug() << imie(cnt_s0);

	int ans = mul_mod(cnt_s0, pow_mod(2, k));
	if (k == 0) {
		cout << ans << "\n";
		return;
	}
	string w_rev = w;
	reverse(ALL(w_rev));

	Hash hw(w);
	Hash hwrev(w_rev);
	int coef = pow_mod(2, k - 1);

	// Not fully in s0?
	for (int center = 0; center < sz; ++center) {
		debug() << "a";
		auto h11 = hwrev.Get(sz - center, sz - 1);
		auto h12 = hrl.Get(0, center - 1);
		debug() << imie(center) << imie(h11) << imie(h12);
		if (h11 != h12) {
			continue;
		}
		if (hw.Get(center + 1, sz - 1) != hlr.Get(0, sz - center - 2)) {
			continue;
		}
		debug() << imie(center);

		const char ch = w[center];
		const int span = max(center, sz - center - 1);
		const int span_ts = span / (SZ(s0) + 1);
		int min_loc = 0;
		while (span_ts >= (1 << min_loc)) { ++min_loc; }
		debug() << imie(span) << imie(span_ts) << imie(min_loc);
		
		// Get sum of 2^(k-i-1) for i-th letter of t, min_loc <= i < k
		if (min_loc < k) {
			int x = sufs[k][ch - 'a'];
			sub_mod(x, sufs[min_loc][ch - 'a']);
			add_mod(ans, mul_mod(x, coef));
		}
	}

	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(14);
	cerr << fixed << setprecision(6);

	cin >> n >> q >> s0 >> t;

	while (n < 21) {
		t += '%';
		++n;
	}
	MakeHashes();

	for (int i = 0; i < SZ(t); ++i) {
		for (int j = 0; j < 26; ++j) {
			sufs[i + 1][j] = sufs[i][j];
		}
		if (t[i] != '%') {
			add_mod(sufs[i + 1][t[i] - 'a'], pow_mod(inv_mod(2), i));
		}
	}

	while (q--) {
		SolveQuery();
	}
}