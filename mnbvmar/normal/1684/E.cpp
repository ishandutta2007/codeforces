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

void Test() {
	int n, k;
	cin >> n >> k;

	vi nums(n);
	for (int &x : nums) { cin >> x; }
	sort(ALL(nums));

	vector<pii> nums_grouped;
	int group_start = 0;
	vector<bool> has_val(n);
	for (int i = 1; i < n; ++i) {
		if (nums[i] != nums[i - 1]) {
			nums_grouped.emplace_back(nums[i - 1], i - group_start);
			group_start = i;
		}
	}
	for (int i = 0; i < n; ++i) {
		if (nums[i] < n) {
			has_val[nums[i]] = true;
		}
	}
	nums_grouped.emplace_back(nums.back(), n - group_start);

	int num_missing = 0;
	for (int i = 0; i < n; ++i) {
		num_missing += !has_val[i];
	}

	int ptra = SZ(nums_grouped) - 1, ptrb = SZ(nums_grouped) - 1;;
	int num_groups = 0;
	int total_groups = 0;
	multiset<int> list_fitting;
	int sum_fitting = 0;
	int num_fitting = 0;
	int ans = 1e9;

	for (int fin_mex = n; fin_mex >= 0; --fin_mex) {
		if (fin_mex < n) {
			num_missing -= !has_val[fin_mex];
		}
		while (ptra >= 0 && nums_grouped[ptra].st >= fin_mex - 1) {
			debug() << imie(nums_grouped[ptra]);
			total_groups += nums_grouped[ptra].nd;
			--ptra;
		}

		while (ptrb >= 0 && nums_grouped[ptrb].st >= fin_mex) {
			const int sz = nums_grouped[ptrb].nd;
			++num_groups;

			if (sum_fitting + sz <= k) {
				list_fitting.insert(sz);
				sum_fitting += sz;
				++num_fitting;
			} else if (!list_fitting.empty() && sz < *list_fitting.rbegin()) {
				sum_fitting -= *list_fitting.rbegin();
				list_fitting.erase(prev(list_fitting.end()));
				list_fitting.insert(sz);
				sum_fitting += sz;
			}
			--ptrb;
		}
		const int move_sz = min(k, total_groups);
		debug() << imie(move_sz) << imie(fin_mex) << imie(num_missing);
		if (num_missing > move_sz) { continue; }
		const int num_left_groups = num_groups - num_fitting;
		debug() << imie(num_left_groups);
		ans = min(ans, num_left_groups);

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
	while (t--) {
		Test();
	}
}