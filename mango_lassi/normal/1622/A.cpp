#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b, c;
	cin >> a >> b >> c;

	bool works = 0;
	if (a == c && (b % 2 == 0)) works = 1;
	if (a == b && (c % 2 == 0)) works = 1;
	if (b == c && (a % 2 == 0)) works = 1;
	if (a + c == b) works = 1;
	if (a + b == c) works = 1;
	if (b + c == a) works = 1;
	if (works) cout << "YES\n";
	else cout << "NO\n";

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}