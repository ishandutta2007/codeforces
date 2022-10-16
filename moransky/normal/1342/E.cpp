#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200005, P = 998244353;

typedef long long LL;

int n, fact[N], infact[N];

LL K;

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

int inline S(int n, int k) {
	int res = 0;
	for (int i = 0; i <= k; i++) {
		res = (res + (LL)C(k, i) * ((i & 1) ? -1 : 1) * power(k - i, n) % P + P) % P;
	}
	return (LL)res * power(fact[k], P - 2) % P;
}

int main() {
	scanf("%d%lld", &n, &K);
	fact[0] = infact[0] = 1;
	for (int i = 1; i <= n; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[n] = power(fact[n], P - 2);
	for (int i = n - 1; i; i--) infact[i] = (LL)infact[i + 1] * (i + 1) % P;
	if (K >= n) puts("0");
	else if (K == 0) {
		printf("%d\n", fact[n]);
	} else {
		printf("%lld\n", 2ll * S(n, n - K) % P * C(n, n - K) % P * fact[n - K] % P);
	}
	return 0;
}