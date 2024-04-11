#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

ll cou1(ll n) {
	return (n * (n-1)) / 2;
}
ll cou2(ll n) {
	return max((ll)0, (n+1) / 2);
}

int main() {
	ll n, m;
	cin >> n >> m;
	ll minc = n;
	ll maxc = 0;
	for (ll i = 0; i <= n; ++i) {
		if (cou1(n - i) >= m && m >= cou2(n - i)) {
			minc = min(minc, i);
			maxc = max(maxc, i);
		}
	}
	cout << minc << ' ' << maxc << '\n';
}