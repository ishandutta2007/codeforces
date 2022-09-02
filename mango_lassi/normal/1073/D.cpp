#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

const int N = 2 * (int)1e5;
ll as[N];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	ll t;
	cin >> t;

	for (int i = 0; i < n; ++i) {
		cin >> as[i];
	}

	ll res = 0;
	while(true) {
		ll sum = 0;
		int cou = 0;
		for (int i = 0; i < n; ++i) {
			if (as[i] <= t) {
				sum += as[i];
				++cou;
			}
		}
		if (cou == 0) break;

		res += (t / sum) * cou;
		t %= sum;
		for (int i = 0; i < n; ++i) {
			if (as[i] <= t) {
				t -= as[i];
				++res;
			}
		}
	}
	cout << res << '\n';
}