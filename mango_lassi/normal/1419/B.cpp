#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll m;
	cin >> m;

	ll ans = 0, cur = 0, act = 1, pw = 4;
	while(cur + act <= m) {
		cur += act;
		act = 2*act + pw;
		pw *= 4;
		++ans;
	}
	cout << ans << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}