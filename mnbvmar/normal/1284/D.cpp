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

const string hahaha = "acbaaacbbbbbcbcbacabbabbbbbcccaababcabbcacabaacbbcbbaaabbbbabccabacabaaaaacacccaccaabbbacabaaabbacbcbcccabbcbacaacbabcbaaccaccbccaaaabbabccbabcacbbcaaccccacababcbcabaabababccbabcacbbbcbabaaabbabbcbcbbcbabaaaacbaabbcbcbabaacbaabbbabababaacaaaccabaabcbaacbccbcccbaacbaaacabbbaabcbccacccaacacaaccabcccbcaabbbbabaaabacaaababccccccabbbcabcacaabbbaaaacacbcaaabcbbaccacacbbbaababccbaacaacbcbbabcabaacacccaccccbaacbbcbaacbbcbbbbcaacabcaaacbbbabbcbcacaaacaacccccbbaacacaaaabbcbccacacababbcbbaccbbcbabcacbbaaccbcabbbcccacbcccabbbacbbcccccaaccbcbaaacbbbbbbccabcccbbaacbcbaccacccbabcacbabcbbcbbcbacccbcbacbccccacacbabacbbabbbaabacbcbaacaabcbcbbcbaaaaccbcbbabcababccbbabccacbacacacabbccccaaacbbacbabcbcbacabccacbbcccbccacccbcccbabcaaccbaaccabbacbaaabcbccbcacabbcbaaabbcbcabbaccbbcbaaccacaaacbcacbcbbccabccbbbcaacbaccbcbbacabcaabcaabbabcbcbbacabbabaabcbacabccbacabccaccaacccaacaabcbbccccbbcccaacbbacbcccbbaaccbbcbccaabaccbbcbaaaccbacbabbabbcbbaaababcbcabcbcacabcbaaaccbbbbccccaaabbcacbbaacccacbcabcbcabaacabbcbaccbacacbcbabcccaabcbaaaaccbcacaccacaaaaccabbcacccaccbccccabacaababbcccbaabcbaaabcbccbbbbababbbacccbccabbbbccbabaaabcacacbccbcbaccbbbacbccabcababbbcbcbbccbaccccababaccabacbccbaabacabbcaaaabacaaacbabaccccccacaccabbcabcaabbbbcbbccabcbacbbcbbbcbbbaacaaaaaaccbbbcbabbaabcbcccaabccbaacccbcbbabcbababaccabbacabaabaabaaccbbaaabbcacabbaccaccbbaabcababcbcabcabaaabbaabaacccccbbbaccabaaaabaaacaabacccaabbacbacabcbcacababbbacaacabcccabbacbcaaccacccaaccacacabcccacbaaaaccabbcccaabbcaaccbaabbcbaaaaccaaacbbcabccaacabcacccacaaaacccccbbabbabcabaaccccacabcbcbcccbabbbbaabbaccaacbbbccaabcbbaccbaabcbcbacbcccacbbcacacabbbbccabbccbabaacbbbbbbbacbacbaabcbabcaaabcccaaabbaacbccbcbccbbabacbbcccbcaabbcabbcbaababbbcbababbcbbcbaccbaaacbbccbcaccbabccaabccaacbcbcacacbbbccccccbacbbcbabacbbbaabbcacbabacacbabbcbcacbcaccbaabbacabbabbbbcaaaaacabcacbbcacccaccacbabcabbbcbababcabacbbccbacbbaacacacccbaacbcbabbaccccacccacaaaaccbbcbcccaabbacabccabacaacbaacccaccbcbccbccabacccabbcaabccaaccccbabbbbbcbcbccccaaaacacbbacabacbccaaaaabaabbaacbbbacabcacbccbccbbcacabaaaabbabbaabbcbcbbccbaccaccbbcccabcbcabbacbaaccaccabaaccaaccbbbbbcabbcbaccabacabccbbaaacccacccababbbcbccbabacbaccaacccacbaaccbbbbccccababbcbcacacccaabacabbcaaccaaccbcbaccacbabaabaabaacbbcaacabbababbbcaabccbbbcbccccbbbaacccbcacbbaccabcbbcbbcabccaacaacbcccccbccaacaabbbbbcbcbbaaaacbccabcabccaccacccaacacaacacaccabbcbbbabcccaccaacbabbaaaacbcaababacaacbcabababcabbbbababbbbaacacbcabcacacabcbababbaaaaaacbabbbbbcacccacbacacccaaaccabcaabcaabaaabaccbaccccabcabccbbccbcbbaccbaacbcbbabbbbcbcabcaacaacaabcababccaaabbccbaccbcccacbacccbcabaabbacbaaaaccacaacbcbabbccccaccbcbabbcbacbcccaaccbabaacbcacbccabbcaabbbcbaaaaabacbccababacaaacabccacabcacbcacabacaacbaabcbbccabbaacccbbbaaabbbcabcccabbccaacabaacaaccbbbccabaccccaaaaccbbabcbbcaaabbbbcabcacbcbbcaabacbccbcbcbbbbcaacbcacacbbabcaaabaacabbacabbcbbaabccabbcaacccbabcaaaabcccaacbaacccbaacbcaacbcaaacbacaaaabbbabbcaccbacabacacaabcbcacaaabcbbaabccbbabbcbabbacabcccbbaaaabcbcaccaccacccabbbabbccababccccccbcacbababbacaabacbccccccaacaababacbbbbcaa";
const size_t seed = std::hash<string>()(hahaha);
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;
using ull = unsigned long long;

const int kMaxN = 200 * 1000;

ull hashes[kMaxN];

ull GetHash() {
	ull ans = 0;
	for (int i = 0; i < 5; ++i) {
		ans ^= rand();
		ans <<= 13;
	}
	return ans;
}

int n;

bool CmpFirst(const pair<int, ull>& lhs, const pair<int, ull>& rhs) {
	return lhs.st < rhs.st;
}

vector<ull> Solve(vector<pii> intvs) {
	vector<ull> ans(n);
	vector<pair<int, ull>> ends, starts;

	ends.emplace_back(-1, 0);
	
	for (int i = 0; i < n; ++i) {
		const int L = intvs[i].st;
		const int R = intvs[i].nd;
		ends.emplace_back(R, hashes[i]);
		starts.emplace_back(L, hashes[i]);
	}

	sort(ALL(ends));
	sort(ALL(starts));
	starts.emplace_back(2e9, 0);
	debug() << imie(starts);

	for (int i = 1; i <= n; ++i) {
		ends[i].nd ^= ends[i - 1].nd;
	}
	for (int i = n - 1; i >= 0; --i) {
		starts[i].nd ^= starts[i + 1].nd;
	}
	assert(is_sorted(ALL(starts), CmpFirst));

	for (int i = 0; i < n; ++i) {
		const int L = intvs[i].st;
		const int R = intvs[i].nd;
		auto lft = prev(lower_bound(ALL(ends), pair<int,ull>(L,0), CmpFirst));
		const ull hash_lft = lft->nd;
		auto rgt = lower_bound(ALL(starts), pair<int,ull>(R+1,0), CmpFirst);
		const ull hash_rgt = rgt->nd;
		ans[i] = hash_lft ^ hash_rgt;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);
	srand(seed);

	cin >> n;

	vector<pii> intvs_a(n), intvs_b(n);
	for (int i = 0; i < n; ++i) {
		cin >> intvs_a[i].st >> intvs_a[i].nd;
		cin >> intvs_b[i].st >> intvs_b[i].nd;
	}

	for (int i = 0; i < n; ++i) {
		hashes[i] = GetHash();
	}

	auto A = Solve(intvs_a);
	auto B = Solve(intvs_b);
	cout << (A == B ? "YES\n" : "NO\n");
}