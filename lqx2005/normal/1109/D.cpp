#include <bits/stdc++.h>
#define FILL(a, n, x) memset((a), (x), sizeof ((a)[0]) * (n))
#define COPY(a, n, b) memcpy((b), (a), sizeof ((a)[0]) * (n))

using namespace std;
const int N = 1e6 + 10, P = 1e9 + 7;
int n, m, a, b;
int pown[N], powm[N], fac[N], ifac[N];

int qpow(int a, int b, int c = 1) {
	for(; b; b >>= 1, a = 1ll * a * a % P)
		if(b & 1)
			c = 1ll * c * a % P;
	return c;
}

int C(int n, int m) {return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P; }

void initmath(int m) {
	fac[0] = 1;
	for(int i = 1; i <= m; i++) fac[i] = 1ll * fac[i - 1] * i % P;
	ifac[m] = qpow(fac[m], P - 2);
	for(int i = m - 1; i >= 0; i--) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % P;
	return;
}

int main() {
	cin >> n >> m >> a >> b;
	pown[0] = 1, powm[0] = 1;
	for(int i = 1; i <= n; i++) pown[i] = 1ll * pown[i - 1] * n % P, powm[i] = 1ll * powm[i - 1] * m % P;
	initmath(max(n, m));
	int ans = 0;
	for(int i = 1; i <= m && i + 1 <= n; i++) {
		int s = n - i;
		int tmp = 1ll * C(m - 1, i - 1) * powm[n - 1 - i] % P * C(n - 2, i - 1) % P * fac[i - 1] % P;
		if(s == 1) (ans += tmp) %= P;
		else (ans += 1ll * tmp * pown[s - 2] % P * (i + 1) % P) %= P;
	}
	cout << ans << endl;
	return 0;
}