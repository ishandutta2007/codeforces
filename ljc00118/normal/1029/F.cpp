#include <bits/stdc++.h>
using namespace std;

long long n, m, ans = LONG_LONG_MAX;
long long a[10000000], len;

int main() {
	cin >> n >> m;
	long long sum = n + m;
	for(long long i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			a[++len] = i;
		}
	}
	a[++len] = 1000000000;
	for(long long i = 1; i * i <= sum; i++) {
		if(sum % i == 0) {
			long long b = sum / i;
			long long wz = lower_bound(a + 1, a + len + 1, i) - a;
			if(a[wz] > i) wz--;
			if(b >= n / a[wz]) ans = min(ans, (i + b) * 2);
		}
	}
	swap(n, m);
	len = 0;
	for(long long i = 1; i * i <= n; i++) {
		if(n % i == 0) {
			a[++len] = i;
		}
	}
	a[++len] = 1000000000;
	for(long long i = 1; i * i <= sum; i++) {
		if(sum % i == 0) {
			long long b = sum / i;
			long long wz = lower_bound(a + 1, a + len + 1, i) - a;
			if(a[wz] > i) wz--;
			if(b >= n / a[wz]) ans = min(ans, (i + b) * 2);
		}
	}
	cout << ans << endl;
	return 0;
}