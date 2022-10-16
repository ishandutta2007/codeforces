/*input
5
3 7 9 7 8
5 2 5 7 5
*/
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>     // Including tree_order_statistics_node_update

using namespace std;
#define int long long
#define sp ' '
#define endl '\n'
#define fi first
#define se second
#define bit(x,y) ((x>>y)&1)
#define loop(i,l,r) for(int i=(l); i<=(r); i++)
#define rloop(i,l,r) for(int i=(l); i>=(r); i--)
#define debug(x...) {cout << "[" << #x << "] ="; _print(x);}
void _print() {cout << endl;}
template<typename T, typename... Ts> void _print(const T& value, const Ts&... values) {cout << ' ' << value; _print(values...);}
template<typename T, typename... Ts> void print(const T& value, const Ts&... values) {cout << value; _print(values...);}
// change cout to cerr for debug in crash
// for struct, can write print operator to use print() (even with SegTree)
using namespace __gnu_pbds;
typedef tree <
int,
null_type,                          //  change to int and we have map
less<int>,                          //  compare key
rb_tree_tag,                        //  tree structure (rb_tree_tag, splay_tree_tag)
tree_order_statistics_node_update   //  MOST IMPORTANT (remove and we get std::set)
>  order_set;

order_set st;
vector<pair<int, int> > a;
int n;

signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	loop(i, 1, n) {
		int t; cin >> t; a.push_back({0, t});
	}
	loop(i, 0, n - 1) cin >> a[i].fi;
	sort(a.begin(), a.end(), greater<pair<int, int> >());
	int ans = 0;
	for (auto it : a) {
		if (st.find(it.se) == st.end())
			st.insert(it.se);
		else {
			int p = st.order_of_key(it.se);
			int l = it.se, r = 2e9;
			while (l != r) {
				int mid = (l + r) / 2;
				if (st.order_of_key(mid) - p < mid - it.se) r = mid;
				else l = mid + 1;
			}
			l--;
			ans += (l - it.se) * it.fi;
			// print(l, st.order_of_key(l) - p, l - it.se);
			st.insert(l);
		}
		// for (auto it2 : st) cout << it2 << sp;
		// cout << endl;
	}
	cout << ans << endl;
}