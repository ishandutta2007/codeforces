#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	ll b, p, f;
	cin >> b >> p >> f;
	ll h, c;
	cin >> h >> c;

	if (c > h) {
		swap(h, c);
		swap(p, f);
	}
	b /= 2;
	p = min(p, b);

	ll res = p * h + min(b-p, f) * c;
	cout << res << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}