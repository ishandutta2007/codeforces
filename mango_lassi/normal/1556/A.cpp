#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll c, d;
	cin >> c >> d;
	if ((c & 1) != (d & 1)) cout << -1 << '\n';
	else if (c == 0 && d == 0) cout << 0 << '\n';
	else if (c == d) cout << 1 << '\n';
	else cout << 2 << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}