#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void solve() {
	ll a, b;
	cin >> a >> b;
	
	// Cost is K -> 
	// 	For cost k = 2h, we fail when a < h (mod k)
	// 	For cost k = 2h + 1, we fail when a <= h (mod k)

	// -> Pick largest modulo such that a >= h or a > h depending on parity, and check if B works
	// 	That largest modulo k is 2a

	if (b < 2*a) cout << "YES\n";
	else cout << "NO\n";
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int ti = 0; ti < n; ++ti) solve();
}