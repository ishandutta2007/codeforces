#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005, P = 998244353;

int n, fact[N], infact[N];

typedef long long LL;

int inline power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int inline C(int a, int b) {
	return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int main() {
	scanf("%d", &n);
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[n] = power(fact[n], P - 2);
	for (int i = n - 1; ~i; i--) infact[i] = (LL) infact[i + 1] * (i + 1) % P;
	for (int i = 1; i <= n; i++) {
		int v = 0;
		if (i < n) {
			v = 2ll * 10 * 9 * power(10, n - i - 1) % P;
			if (i < n - 1) {
				v = (v + (LL)10 * 9 * 9 * power(10, n - i - 2) % P * (n - i - 2 + 1)) % P;
			}
		} else v = 10;
		printf("%d ", v);
	}
	return 0;
}