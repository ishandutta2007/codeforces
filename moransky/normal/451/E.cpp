#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 20, P = 1e9 + 7;
int n, ans, infact;
LL m, a[N];
int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}
//  a  b 
int C(LL a, int b) {
	int res = 1;
	for (int i = 0; i < b; i++) res = (LL)res * ((a - i) % P) % P;
	return (LL)res * infact % P;
}
int main() {
	scanf("%d%lld", &n, &m);
	int val = 1;
	for (int i = 2; i < n; i++) val = (LL)val * i % P;
	infact = power(val, P - 2);
	for (int i = 0; i < n; i++) scanf("%lld", a + i);
	for (int i = 0; i < (1 << n); i++) {
		int cnt = 0;
		LL s = n + m - 1;
		for (int j = 0; j < n; j++) 
			if (i >> j & 1) cnt ++, s -= a[j];
		s -= cnt;
		if (s < n - 1) continue;
		if (cnt & 1) ans = ((ans - C(s, n - 1)) % P + P) % P;
		else (ans += C(s, n - 1)) %= P;
	}
	printf("%d\n", ans);
	return 0;
}