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
#define int ll
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

struct SegTree {
	struct Node {
		int sum;
		int min_suf;
		Node() : sum{0}, min_suf{0} {}
		Node(int s, int ms) : sum{s}, min_suf{ms} {}

		static Node Get(int val) {
			return Node{val, min<int>(val, 0)};
		}

		Node Join(const Node &rhs) const {
			return Node{
				sum + rhs.sum,
				min(rhs.min_suf, min_suf + rhs.sum)};
		}
	};

	vector<Node> data;
	int base;

	SegTree(int n) : base{1} {
		while (base < n + 2) { base *= 2; }
		data.resize(base * 2);
	}

	void AddVal(int loc, int val) {
		debug() << "AddVal" << imie(loc) << imie(val);
		loc += base;
		data[loc] = Node::Get(data[loc].sum + val);
		loc /= 2;
		while (loc) {
			data[loc] = data[loc * 2].Join(data[loc * 2 + 1]);
			loc /= 2;
		}
	}

	int GetMinSuf() const {
		return data[1].min_suf;
	}
};

void Test() {
	int n, m;
	cin >> n >> m;

	vector<int> teachers(n);
	for (int &x : teachers) { cin >> x; }

	set<int> set_different_vals(ALL(teachers));
	vector<int> vec_different_vals(ALL(set_different_vals));
	const int S = SZ(vec_different_vals) + 1;

	function<int(int)> GetAgeLoc = [&](int age) {
		const auto iter = lower_bound(ALL(vec_different_vals), age);
		return iter - vec_different_vals.begin();
	};

	SegTree st(S);
	for (int age : teachers) {
		st.AddVal(GetAgeLoc(age), 1);
	}

	vector<ll> group_sum_ages(m);
	vector<int> group_cnt(m);
	vector<vi> groups(m);

	function<int(int)> GetGroupLoc = [&](int group_idx) {
		const int age = (group_sum_ages[group_idx] + group_cnt[group_idx] - 1) / group_cnt[group_idx];
		return GetAgeLoc(age);
	};
	
	for (int i = 0; i < m; ++i) {
		int sz;
		cin >> sz;
		group_cnt[i] = sz;
		groups[i].resize(sz);
		for (int &x : groups[i]) {
			cin >> x;
			group_sum_ages[i] += x;
		}
		st.AddVal(GetGroupLoc(i), -1);
	}

	string ans;
	for (int i = 0; i < m; ++i) {
		st.AddVal(GetGroupLoc(i), 1);
		for (int x : groups[i]) {
			--group_cnt[i];
			group_sum_ages[i] -= x;

			st.AddVal(GetGroupLoc(i), -1);
			const int min_val = st.GetMinSuf();
			debug() << imie(i) << imie(x) << imie(min_val);
			ans += (min_val >= 0 ? '1' : '0');
			st.AddVal(GetGroupLoc(i), 1);

			++group_cnt[i];
			group_sum_ages[i] += x;
		}
		st.AddVal(GetGroupLoc(i), -1);
	}

	cout << ans << "\n";
}

int32_t main() {
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