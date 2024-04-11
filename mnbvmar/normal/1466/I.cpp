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

int n, b;
int num_iters;

bool Ask(int idx, string s) {
	++num_iters;
	assert(SZ(s) == b);
	cout << idx + 1 << " " << s << endl;
	string ans;
	cin >> ans;
	return (ans == "yes");
}

void Answer(string s) {
	cout << 0 << " " << s << endl;
	cerr << "iters: " << num_iters << "/" << 3*(n+b) << "\n";
}

bool IsGeq(int idx, string s) {
	debug() << imie(idx) << imie(s);
	if (count(ALL(s), '0') == SZ(s)) {
		return true;
	}
	int loc = SZ(s) - 1;
	while (s[loc] == '0') { --loc; }
	s[loc] = '0';
	for (int i = loc + 1; i < SZ(s); ++i) {
		s[i] = '0';
	}
	s.resize(b, '1');
	return Ask(idx, s);
}

int main() {
	cin >> n >> b;
	vector<pair<int, string>> known_stack{{-1, ""}};
	vector<bool> is_active(n, true);
	// string best_known;
	int cur = 0;

	while (SZ(known_stack.back().second) < n + b) {
		if (!is_active[cur]) {
			cur = (cur + 1) % n;
			continue;
		}

		string que = known_stack.back().second;
		if (!IsGeq(cur, que + "1")) {
			known_stack.emplace_back(cur, que + "0");
		} else {
			while (count(ALL(que), '0')) {
				string nque = que;
				int idx = SZ(nque) - 1;
				while (nque[idx] == '1') { --idx; }
				nque.resize(idx + 1);
				nque[idx] = '1';
				if (IsGeq(cur, nque)) {
					que = nque;
					que.pop_back();
					while (SZ(known_stack) > 1 && SZ(known_stack.back().second) >= SZ(nque)) {
						is_active[known_stack.back().first] = false;
						known_stack.pop_back();
					}
				} else {
					break;
				}
				debug() << imie(known_stack) << imie(que);
			}
			known_stack.emplace_back(cur, que + "1");
		}
		debug() << imie(known_stack);

		cur = (cur + 1) % n;
	}

	string ans = known_stack.back().second;
	ans.resize(b);
	Answer(ans);
}