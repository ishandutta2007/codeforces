#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 10 + (ll)1e18;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll n, b;
	cin >> n >> b;

	vector<pair<ll, ll>> divs;
	for (ll i = 2; i*i <= b; ++i) {
		int cou = 0;
		while (b % i == 0) {
			++cou;
			b /= i;
		}
		if (cou) divs.push_back({i, cou});
	}
	if (b > 1) divs.push_back({b, 1});

	ll res = INF;
	for (auto pr : divs) {
		ll p = pr.first;
		ll cou = 0;
		ll tmp = n;
		while(tmp >= p) {
			tmp /= p;
			cou += tmp;
		}
		res = min(res, cou / pr.second);
	}
	cout << res << '\n';
}