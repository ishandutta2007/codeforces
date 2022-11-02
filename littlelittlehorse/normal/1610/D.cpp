#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int test, n, m, a[200001], r[200001], l, c[31];
const int p = 1000000007;
long long f[200001];

long long rp(long long n, long long k) {
	long long res = 1;
	for (; k; k >>= 1, n *= n, n %= p)
		if (k & 1)
			res *= n, res %= p;
	return res;
}

long long C(int n, int m) {
	return f[n] * rp(f[m], p - 2) % p * rp(f[n - m], p - 2) % p;
}

int main() {
	scanf("%d", &n);
	f[0] = 1;
	for (int i = 1; i <= n; i++)
		f[i] = (f[i - 1] * i) % p;
	r[0] = 1;
	for (int i = 1; i <= n; i++)
		r[i] = (r[i - 1] * 2) % p;
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		int cnt = 0;
		for (; !(x & 1); x >>= 1)
			++cnt;
		++c[cnt];
	}
	int ans = r[n] - 1;
	for (int i = 1; i <= 30; i++) {
		int tot = 0;
		for (int j = i + 1; j <= 30; j++)
			tot += c[j];
		for (int j = 1; j <= c[i]; j += 2) {
			ans -= 1LL * C(c[i], j) * r[tot] % p;
			if (ans < 0)
				ans += p;
		}
	}
	printf("%d\n", ans);
}