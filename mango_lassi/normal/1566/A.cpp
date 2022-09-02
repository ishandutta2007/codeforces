#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll n, s;
	cin >> n >> s;
	ll k = n / 2 + 1;
	cout << s / k << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}