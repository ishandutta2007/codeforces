#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n;
	cin >> n;
	ll tmp = n;

	vector<ll> divs;
	for (ll i = 2; (ll)i*i <= tmp; ++i) {
		if (tmp % i == 0) {
			divs.push_back(i);
			while(tmp % i == 0) tmp /= i;
		}
	}
	if (tmp > 1 || n == 1) divs.push_back(tmp);

	if (divs.size() > 1) {
		cout << 1 << '\n';
	} else {
		cout << divs[0] << '\n';
	}
}