#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

void solve() {
	int a, b, c, d, k;
	cin >> a >> b >> c >> d >> k;

	int na = (a + c-1) / c;
	int nb = (b + d-1) / d;
	if (na + nb > k) cout << "-1\n";
	else cout << na << ' ' << nb << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
	
}