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
#define int ll
// LONG LONG EVERYWHERE

vector<string> answer;

int Add(int a, int b, bool write = true) {
	if (write) answer.push_back(to_string(a) + " + " + to_string(b));
	return a + b;
};
int Xor(int a, int b, bool write = true) {
	if (write) answer.push_back(to_string(a) + " ^ " + to_string(b));
	return a ^ b;
};

int polymod(int a, int b, bool write = false) {
	debug() << imie(a) << imie(b);
	if (a < b) { return a; }
	int xb = b;
	while (xb < a) { xb = Add(xb, xb, write); }
	while (xb >= b) {
		if ((a ^ xb) < a) { a = Xor(a, xb, write); }
		xb >>= 1;
	}
	debug() << imie(a);
	return a;
}

int polygcd(int a, int b, bool write = false) {
	while (b) {
		a = polymod(a, b, write);
		swap(a, b);
	}
	return a;
}

int32_t main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;

	int cur = 3;
	while (polygcd(cur * n, n) != 1) { cur += 2; }
	debug() << imie(cur);


	function<int(int, int)> Mul = [&](int a, int b) {
		if (b == 1) { return a; }
		int c = Mul(a, b / 2);
		c = Add(c, c);
		if (b % 2 == 1) { c = Add(c, a); }
		return c;
	};

	int num = Mul(n, cur);
	int x = polygcd(n, num, true);
	assert(x == 1);

	cout << SZ(answer) << "\n";
	for (auto &elem : answer) { cout << elem << "\n"; }
}