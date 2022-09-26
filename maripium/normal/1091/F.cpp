#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100100;

int n;
ll a[N];
ll pre[N];
char s[N];
ll ans;
bool water;
ll fly, grass;

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%lld", a + i);
		a[i] *= 2;
		pre[i] = pre[i - 1] + a[i];
	}
	scanf("%s", s + 1);
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'W') {
			water = true;
			ll now = min(a[i], (pre[n] - pre[i - 1] - fly) / 2);
			ans += now * 3;
			ans += a[i] - now;
			fly += now;
			fly -= (a[i] - now);
		} else if (s[i] == 'G') {
			ll now = min(a[i], (a[i] + fly) / 2);
			ans += now;
			ans += 5 * (a[i] - now);
			fly -= now;
			fly += (a[i] - now);
			grass += now;
		} else {
			if (fly < a[i]) {
				ll now = min((a[i] - fly) / 2, grass);
				grass -= now;
				fly += now * 2;
				ans += now * 4;
			}
			if (fly < a[i]) {
				if (water) {
					ans += (a[i] - fly) * 3;
				} else {
					ans += (a[i] - fly) * 5;
				}
				fly = a[i];
			}
			fly -= a[i];
			ans += a[i];
		}
	}
	printf("%lld\n", ans / 2);
}