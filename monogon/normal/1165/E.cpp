
#define P 998244353

#include <iostream>
#include <algorithm>

using namespace std;

int n;
long long a[200000], b[200000];

int main() {
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i];
		a[i] *= (i + 1);
		a[i] *= (n - i);
	}
	sort(a, a + n);
	for(int i = 0; i < n; i++) {
		cin >> b[i];
	}
	sort(b, b + n);
	long long ans = 0;
	for(int i = 0; i < n; i++) {
		a[i] %= P;
		b[n - i - 1] %= P;
		ans += (a[i] * b[n - i - 1]) % P;
		ans %= P;
	}
	cout << ans << endl;
}