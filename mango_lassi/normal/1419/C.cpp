#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	int n;
	ll x;
	cin >> n >> x;

	// 1 possible if we can get everyone to x
	// 2 is always possible
	//	If n >= 3
	//	1. Pull everyone except one person to killjoy
	//	2. Meet that person with someone else
	//	If n = 2, just infect both persons, one each round
	// If someone starts where killjoy does, we can certainly infect everyone in one round
	
	ll sum = 0;
	int match = 0;
	for (int i = 0; i < n; ++i) {
		ll a;
		cin >> a;
		sum += a;
		if (a == x) match += 1;
	}
	if (match == n) cout << '0' << '\n';
	else if (match > 0 || sum == n*x) cout << '1' << '\n';
	else cout << '2' << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}