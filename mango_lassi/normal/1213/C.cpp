#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

void solve() {
	ll n, m;
	cin >> n >> m;
	ll k = n / m;
	ll sum = 0;
	for (int i = 0; i < 10; ++i) {
		for (int c = 1; c <= 10; ++c) {
			if (m * c % 10 == i) {
				sum += i * ((k-c+10) / 10);
			}
		}
	}
	cout << sum << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int ti = 0; ti < t; ++ti) solve();
}