#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll INF = 1e18;
const ll HIGH = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	ll x1, y1;
	cin >> x1 >> y1;
	ll x2, y2;
	cin >> x2 >> y2;
	x2 -= x1;
	y2 -= y1;
	
	int n;
	cin >> n;
	string str;
	cin >> str;

	ll tx = 0;
	ll ty = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'U') ++ty;
		if (str[i] == 'R') ++tx;
		if (str[i] == 'D') --ty;
		if (str[i] == 'L') --tx;
	}

	ll res = INF;
	ll cx = 0;
	ll cy = 0;
	for (int i = 0; i < n; ++i) {
		if (str[i] == 'U') ++cy;
		if (str[i] == 'R') ++cx;
		if (str[i] == 'D') --cy;
		if (str[i] == 'L') --cx;

		ll low = 0;
		ll high = HIGH + 1;
		while(low <= high) {
			ll mid = (low + high) >> 1;
			ll x = cx + tx * mid;
			ll y = cy + ty * mid;
			ll d = abs(x2 - x) + abs(y2 - y);
			ll s = i+1 + n*mid;

			if (d <= s) {
				res = min(res, s);
				if (low == high) break;
				high = mid;
			} else low = mid + 1;
		}
	}
	if (res >= INF) cout << "-1\n";
	else cout << res << '\n';
}