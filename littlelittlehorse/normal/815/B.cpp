#include<bits/stdc++.h>
using namespace std;
const int N(222222);
typedef long long LL;
const int mod(1e9 + 7);
int a[N], fac[N], invFac[N], inv[N];
int main() {
	fac[0] = invFac[0] = 1;
	for(int i(1); i <= 200000; i++) {
		inv[i] = i == 1 ? 1 : (LL)inv[i - mod % i] * ((mod + i - 1) / i) % mod;
		invFac[i] = invFac[i - 1] * (LL)inv[i] % mod;
		fac[i] = fac[i - 1] * (LL)i % mod;
	}
	int n;
	scanf("%d", &n);

	for(int i(0); i < n; i++) {
		scanf("%d", &a[i]);
	}
	if(n == 1) {
		printf("%d\n", a[0]);
		return 0;
	}
	if(n % 2) {
		for(int i(0); i + 1 < n; i++)
			a[i] = i % 2 == 0 ? (a[i] + a[i + 1]) % mod : (a[i] - a[i + 1] + mod) % mod;
		n--;
	}
	int ans(0);
	for(int i(0); i < n; i++) {
		ans = (ans + (LL)a[i] * (i % 2 && n % 4 == 0 ? mod - 1 : 1) % mod * ((LL)fac[n / 2 - 1] * invFac[i / 2] % mod * invFac[n / 2 - 1 - i / 2] % mod)) % mod;
	}
	cout << ans << endl;
}