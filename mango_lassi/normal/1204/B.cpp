#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	ll low = (ll)(n - l) + ((1ll<<l) - 1);
	ll high = (ll)(n - r) * (1ll<<(r-1)) + ((1ll<<r) - 1);
	cout << low << ' ' << high << '\n';
}