//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
//~ #include <ext/pb_ds/assoc_container.hpp>
//~ #include <ext/pb_ds/tree_policy.hpp>
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((int)(x).size())
#define st first
#define nd second

//~ using namespace __gnu_pbds;
using namespace std;
 
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
 
#define shandom_ruffle random_shuffle
 
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

const string hehe = "abccbaccaabcbcabcbccbbacabaabcbcbaacbcabaabbabcaacacabaabbcabbcaaccbacaaacccccbccaacccbbcaacabbbaacbbbbcbbaababbbbacbbaccabacbbababbcaaaabbacccacaaabbabaacbababbbbbbabcabbbaaabaacbaabcaaabcabaaabaccbbbcbabcbcbcbabaacbcabbaabcbcccacbcbaccaabbcccabcccbbcbccbaccabcabbaaaaaccabaaacbcbccaaabcbaacbbccbabbcbbccaaacbacaccbcabcaccbccbbacbbaccabccccbbbaacbabcbcbbaaacbaaacccbacbacacaabbbbcabbaaaccacacabbcacacaaacbcccaabbaccbcaabaabaaacbaaccacbbabacbabccbbaabbbabacbabaacabccaabbbbabcabcacbbbacbaccabccbabcbabaabbcbbbabcaacaacbaccacabcacababcaabbccacbabcbcacacbacaaabaccaaabbbbbcaaabbcbcbababccbcbbabacabacbcbacabcabbbcccaabccacccabccccbccaaccbaacccbcbacbacccaabaabcacabcbaccbcbaaabbcacaacbacbcbbccccbacaacbbcbbcbacaabaaaabacbbabccbacaaccbbcacabbbacacaabacccacaccccbcccaaaacbacabcccccbbcccccbccbcbacacbcbcbbaababbbcaccabccababcbacbbbacbcbbbabcaacbbbbabccbacbcbaabccabaccabcabbccaabbbcbaacaabbbbcbaabaccbcacaaacbcccabcbacacbcaacbbcabaaacabbabacbcbbabcbbcbacbcbabcaccbbbcccacbacaaccbbccbccaccabcaccaacbcabacbabbacabaaacacbcabbabacbababcbababcbcbbaaabacbaaccbbcbcbabccaabaaaaaccbcacbababacbaccababccbcabbaaacbcbbaaccbbaaacbbbabcbaabcbabcbaabbbccbbcbccbaaacbabbaccbcbacababbaabbbbacabbccbcbacbabcbcbbbbaaaabcaccbcbbaaccbbabcbbccaabbbcacbaaaaacbccbbccbbcbaacabbbaaaaabaaaabbbaaacbbaabbabbbccbcbbbbccaabbaaacccbacabbabcaccbbbbabacbacbcccbbcbbcabcaacbbabaaabbcccbcbbbcaababcbcacbaaccabbbcaaccbbabcacbacaabbbbaacccbbbbbaabcccaaacaababbcaabcbbabcbcacccbbcabbbabacabcabcaabccacccaccaaacbcccbccbababccaabaccbaaccacbaacbcbaacacaaaccabbbbcbbccbbcbabcacccabaabcaaaacaabcbcbcaaacbbbabacabbacaabbbcbaabaaaabacabbabcccaccacbababbaabbacaabacababacccababbabbbbbabccbcbcaaaccbbbcacabbaaaccccbaccacacaabcacccbbcaabaaaacccbacaabbcabaaacbcbcabcbaabbababbbbcabacccccaabaaccccbbaacaabbabbccacacbcabaabbcabcccaabaacbcacccaaccbcccbbbcacccbabbccabbacaacbcbbcbcbcbccaabccaaaaaccccbacbbabcbcacacaacbaabcbaacbacccbaaaccababbaccacbbcccacacaccacbaacbbaabcaabccbabcaccccaaccccbbaaabbbaacccbcabcaabaccaccbbbccbacbbcbcababbbbcccabacacabbabcabcabcbbccbcbbbcccbcbbcbbacbbbcbbabbcaaacbacccbabbabaccaaccbaaaccbaabcccbbaaaccaabbacbbbcccaaabaabbccababbabbaaaaabbaabccbcccaabccbccacacbbbabaabcaabcbabbcaaababcaccbaacaccbcaaabccaacaacacbbcccabaacbaacbcbcccbcbacaacabcbcacccbabababcabbcbabbbcaacbaaacbaaacabcaccbaaaacabaccbcacacaaabababaaccabcbbbacacbbcacccacaccabcacbaacbabcaaabbcbbbbacaccbbacbbcbcaccaabbcccbbacbbbcbbbbccabaacabcbaaccbaacabccbaccabcacaaaabcbcbbbacaacabaacacaaabcaabcbbbacbccbcbacbbbbbaaacabcacbccaacabcbbbbbcbccabcaaabaacabbaaabbabbba";

const int mod = 1000 * 1000 * 1000 + 7;
const int base = std::hash<string>()(hehe) % mod;

struct Node {
	int szero, pzero, hzero, parone;
	Node() : szero(0), pzero(1), hzero(0), parone(0) {}
	Node(int a, int b, int c, int d) : szero(a), pzero(b), hzero(c), parone(d) {}

	bool operator==(const Node &rhs) const {
		return pzero == rhs.pzero && hzero == rhs.hzero;
	}
};

Node Join(Node L, Node R) {
	Node Ans;

	if (L.parone) {
		R.hzero = R.szero - R.hzero;
		if (R.hzero < 0) { R.hzero += mod; }
	}

	Ans.szero = (L.szero + (ll)L.pzero * R.szero) % mod;
	Ans.pzero = (ll)L.pzero * R.pzero % mod;
	Ans.hzero = (L.hzero + (ll)L.pzero * R.hzero) % mod;
	Ans.parone = L.parone ^ R.parone;
	return Ans;
}

const int kBase = 1 << 18;

Node tree[2 * kBase];
int n, q;

Node Get(int L, int R) {
	int orig_l = L, orig_r = R;
	assert(L <= R);
	L += kBase; R += kBase;
	if (L == R) { return tree[L]; }

	Node ans_l = tree[L];
	Node ans_r = tree[R];
	while (L / 2 != R / 2) {
		if (L % 2 == 0) { ans_l = Join(ans_l, tree[L + 1]); }
		if (R % 2 == 1) { ans_r = Join(tree[R - 1], ans_r); }
		L /= 2; R /= 2;
	}

	ans_l = Join(ans_l, ans_r);
	debug() << imie(orig_l) << imie(orig_r) << ans_l.szero << " " << ans_l.pzero << " " <<
		ans_l.hzero << " " << ans_l.parone;
	return ans_l;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	cin >> n;
	string s;
	cin >> s >> q;

	for (int i = 0; i < n; ++i) {
		if (s[i] == '0') {
			tree[i + kBase] = Node{1, base, 0, 0};
		} else {
			tree[i + kBase] = Node{0, 1, 0, 1};
		}
	}

	int L = kBase, R = kBase + n - 1;
	L /= 2; R /= 2;
	while (L) {
		for (int i = L; i <= R; ++i) {
			tree[i] = Join(tree[i*2], tree[i*2+1]);
		}
		L /= 2; R /= 2;
	}

	for (int i = 0; i < q; ++i) {
		int a, b, len;
		cin >> a >> b >> len;
		--a; --b;

		bool ans = (Get(a, a + len - 1) == Get(b, b + len - 1));
		cout << (ans ? "Yes\n" : "No\n");
	}
}