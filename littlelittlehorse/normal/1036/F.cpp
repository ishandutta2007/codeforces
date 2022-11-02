#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;

int c[11], u[101], len, cnt, T;
bool b[11];
long long a[11], n;

bool check(long long cur, int i, long long n) {
	if (i * log(cur) > log(1e18) + 2)
		return false;
	long long now = 1;
	for (int j = 1; j <= i; j++)
		now *= cur;
	return now <= n;
}

long long calc(long long n, int i) {
	if (i == 1)
		return n;
	long long L = 1, R = pow(n, 1.0 / i) * 2, M = (L + R) >> 1;
	for (; L + 1 < R; M = (L + R) >> 1)
		if (check(M, i, n))
			L = M;
		else 
			R = M;
	return L;
}

int main() {
	memset(b, false, sizeof(b));
	b[1] = true; len = 0;
	for (int i = 2; i <= 10; i++) {
		if (!b[i])
			c[++len] = i;
		for (int j = 1; j <= len && c[j] * i <= 10; j++) {
			b[c[j] * i] = true;
			if (!(i % c[j]))
				break;
		}
	}
	for (int i = 1; i <= 100; i++) {
		u[i] = 1;
		int now = i;
		for (int j = 1; j <= len && c[j] * c[j] <= now; j++)
			if (!(now % c[j])) {
				int cnt = 0;
				for (; !(now % c[j]); now /= c[j])
					++cnt;
				if (cnt > 1)
					u[i] = 0;
				else
					u[i] = -u[i];
			}
		if (now != 1)
			u[i] = -u[i];
	} 
	scanf("%d", &T);
	for (; T--; ) {
		scanf("%lld", &n);
		long long ans = 0;
		for (int i = 1; i <= 100; i++) 
			if (u[i]) {
				long long d = calc(n, i);
				if (d == 1) 
					break;
				ans += u[i] * (d - 1);
			}
		printf("%lld\n", ans);
	}
}