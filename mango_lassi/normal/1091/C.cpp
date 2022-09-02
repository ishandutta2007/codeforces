#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

// It is guaranteed that d divides n
ll calc(ll n, ll d) {
	ll cou = n / d;
	return cou + d * ((cou * (cou - 1)) / 2);

	// 0 1 2 3 4 5
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;

	vector<ll> res;
	for (ll d = 1; d*d <= n; ++d) {
		if (n % d == 0) {
			res.push_back(calc(n, d));
			res.push_back(calc(n, n/d));
		} else continue;	
	}
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto v : res) cout << v << ' '; cout << '\n';
}