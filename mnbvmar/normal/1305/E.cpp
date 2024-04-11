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

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(11);
	cerr << fixed << setprecision(6);

	int n, m;
	cin >> n >> m;

	int best = 0;
	for (int i = 1; i <= n; ++i) {
		best += min(i - 1, n - i);
	}

	if (m > best) {
		cout << "-1\n";
		return 0;
	}

	vi found_at(n + 1);

	for (int start = 1; start <= n; ++start) {
		//~ int num_good = 0;
		int found = 0;
		for (int L = start; L <= start + n; ++L) {
			const int min_sum = 2 * L + 1;
			const int max_sum = start + n;
			found += max(0, max_sum - min_sum + 1);
		}
		found_at[start] = found;

		//~ cout << start << " " << found << "\n";
	}

	int start = n;
	while (found_at[start] < m) { --start; }

	while (true) {
		vi seq(n + 1);
		iota(ALL(seq), start);

		vi contain(n + 1);
		for (int i = 0; i <= n; ++i) {
			for (int j = i + 1; j <= n; ++j) {
				const int v = seq[i] + seq[j];
				if (v <= start + n) {
					++contain[i];
					++contain[j];
					++contain[v - start];
				}
			}
		}

		for (int i = 0; i <= n; ++i) {
			if (found_at[start] - contain[i] == m) {
				const int omit = start + i;
				for (int j = start; j <= start + n; ++j) {
					if (j == omit) { continue; }
					cout << j << " ";
				}
				cout << "\n";
				return 0;
			}
		}

		--start;
	}
	assert(false);

	//~ vector<bool> fnd(best + 1);

	//~ for (int start = 1; start <= n; ++start) {
		//~ for (int omit = start; omit <= start + n; ++omit) {
			//~ vi nums;
			//~ for (int i = start; i <= start + n; ++i) {
				//~ if (i != omit) { nums.push_back(i); }
			//~ }

			//~ vector<bool> has(start + n + 1);
			//~ for (int x : nums) { has[x] = true; }

			//~ int cnt = 0;
			//~ for (int i = 0; i < n; ++i) {
				//~ for (int j = i + 1; j < n; ++j) {
					//~ int v = nums[i] + nums[j];
					//~ if (v < SZ(has) && has[v]) {
						//~ ++cnt;
					//~ }
				//~ }
			//~ }
			//~ cout << start << " " << omit << " -> " << cnt << "\n";
			//~ assert(cnt <= best);
			//~ if (!fnd[cnt]) {
				//~ fnd[cnt] = true;
			//~ }
		//~ }
	//~ }
	//~ cout << count(ALL(fnd), false) << "\n";
	//~ vector<bool> has(n + 1);
	//~ fill(has.begin(), has.begin() + n, true);
	//~ sort(ALL(has));
	//~ vi nums;

	//~ vector<bool> observed(n * n);

	//~ do {
		//~ nums.clear();
		//~ for (int i = 0; i < 2 * n; ++i) {
			//~ if (has[i]) {
				//~ nums.push_back(i + 1);
			//~ }
		//~ }

		//~ int cnt = 0;
		//~ for (int i = 0; i < n; ++i) {
			//~ for (int j = i + 1; j < n; ++j) {
				//~ int v = nums[i] + nums[j];
				//~ if (v <= 3 * n && has[v - 1]) {
					//~ ++cnt;
				//~ }
			//~ }
		//~ }

		//~ if (!observed[cnt]) {
			//~ observed[cnt] = true;
			//~ cout << cnt << endl;
			//~ for (int v : nums) { cout << v << " "; } cout << "\n";
		//~ }
	//~ } while (next_permutation(ALL(has)));
}