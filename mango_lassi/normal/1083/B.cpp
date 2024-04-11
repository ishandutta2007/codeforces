#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;
const int C = 26;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n, k;
	cin >> n >> k;

	string low, high;
	cin >> low >> high;

	// The answer is nk - sum LCA.
	// Therefore we want to minimize sum LCA.
	// Count number of available prefixes with length S for all S <= n
	ll res = 0;
	ll sep = 0; // Ones where we can freely choose next char
	bool eq = true; // Do prefixes match
	for (int ln = 0; ln < n; ++ln) {
		if (eq) {
			if (low[ln] == high[ln]) {
				++res;
				continue;
			} else {
				eq = false;

				ll diff = high[ln] - low[ln] + 1;
				sep = max((ll)0, diff - 2);
			}
		} else {
			sep *= 2;
			sep += ('b' - low[ln]);
			sep += (high[ln] - 'a');
		}

		if (sep > k) sep = k;
		ll cou = sep + 2;
		if (cou > k) cou = k;
		res += cou;
	}
	
	cout << res << '\n';
}