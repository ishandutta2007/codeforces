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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n;
	cin >> n;
	vll nums(n);
	for (ll &x : nums) { cin >> x; }

	if (n == 1) {
		cout << "1 1\n";
		cout << -nums[0] << "\n";
		for (int i : {0, 1}) {
			(void)i;
			cout << "1 1\n";
			cout << "0\n";
		}
	} else {
		vll A(n), B(n);
		vector<int> rems(n, -1);

		for (int i = 0; i < n; ++i) {
			ll num = ll(i) * (n - 1);
			rems[num % n] = i;
		}
		assert(count(ALL(rems), -1) == 0);
		
		for (int i = 0; i < n; ++i) {
			int rem = nums[i] % n;
			if (rem < 0) { rem += n; }
			rem = (n - rem) % n;
			A[i] = ll(rems[rem]) * (n - 1);
			nums[i] += A[i];
		}

		cout << 1 << " " << n - 1 << "\n";
		for (int i = 0; i < n - 1; ++i) { cout << A[i] << " "; } cout << "\n";
		cout << n << " " << n << "\n";
		cout << A[n-1] << "\n";
		cout << 1 << " " << n << "\n";
		for (int i = 0; i < n; ++i) {
			assert(nums[i] % n == 0);
			cout << -nums[i] << " ";
		}
		cout << "\n";
	}
}