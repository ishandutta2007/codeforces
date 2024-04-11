#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, m;

int main() {
	cin.tie(0); cout.tie(0);
	ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		ll a, b;
		cin >> a >> b;
		if((a + b) % 2 == 0) {
			ll t = a - 1;
			ll ans = t / 2 * n;
			if(t % 2 == 1) ans += (n + 1) / 2;
			ans += (b + 1) / 2;
			cout << ans << endl;
		} else {
			ll t = a - 1;
			ll ans = t / 2 * n + (n * n + 1) / 2;
			if(t % 2 == 1) ans += n / 2;
			ans += (b + 1) / 2;
			cout << ans << endl;
		}
	}
	return 0;
}