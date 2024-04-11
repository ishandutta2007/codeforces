#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int H = 1e9;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> hs(n);
	for (int i = 0; i < n; ++i) cin >> hs[i];

	sort(hs.begin(),  hs.end());

	ll ch = H;
	ll ck = 0;
	ll ans = 0;
	for (int i = n-1; i >= 0; --i) {
		ll cou = (n-1) - i;
		
		ll dh = ch - hs[i];
		ch = hs[i];

		if (dh * cou + ck >= k) {
			// First step
			++ans;
			dh -= (k - ck) / cou;
			ck = 0;

			// Intermediate steps
			ll steps = dh / (k / cou);
			ans += steps;
			dh -= (k / cou) * steps;
		}

		
		// Last steps
		ck += dh * cou;
	}
	if (ck > 0) ++ans;
	cout << ans << '\n';
}