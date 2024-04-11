#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define at find_by_order

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	ll sum = 0, ans = 0;
	ordered_set<int> all;
	array<set<int>, 2> open;

	int q;
	cin >> q;
	while (q--) {
		int tp, d;
		cin >> tp >> d;
		sum += d;
		if (d < 0) {
			d *= -1;
			open[tp].erase(d);
			if (tp) ans -= *all.at(open[tp].size());
			if (all.order_of_key(d) < open[1].size()) {
				ans -= d;
				if (open[1].size() < all.size()) ans += *all.at(open[1].size());
			}
			all.erase(d);
		} else {
			open[tp].insert(d);
			all.insert(d);
			if (all.order_of_key(d) < open[1].size() - tp) {
				ans += d;
				if (open[1].size() - tp < all.size()) ans -= *all.at(open[1].size() - tp);
			}
			if (tp) ans += *all.at(open[1].size() - 1);
		}

		if (!(open[0].size() + open[1].size())) cout << 0;
		else if (!open[0].size()) cout << sum + ans - *open[1].begin();
		else if (*open[1].begin() > *open[0].rbegin()) cout << sum + ans - *open[1].begin() + *open[0].rbegin();
		else cout << sum + ans;
		cout << '\n';
	}
}