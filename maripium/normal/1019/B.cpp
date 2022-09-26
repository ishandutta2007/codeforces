#include <bits/stdc++.h>
using namespace std;

int query(int pos) {
	cout << '?' << ' ' << pos << '\n';
	int x; cin >> x;
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	int n; cin >> n;
	if (n % 4 == 2) {
		return cout << '!' << ' ' << -1 << '\n',0;
	}
	pair<int,int> cur = make_pair(query(1), query((n / 2) + 1));
	int l = 1, r = (n / 2);
	while (l < r) {
		int mid = (l + r) / 2;
		pair<int,int> tmp = make_pair(query(mid), query(mid + (n / 2)));
		if (1ll * (tmp.first - tmp.second) * (cur.first - cur.second) <= 0) r = mid;
		else l = mid + 1;
	}
	cout << '!' << ' ' << l << '\n';
}