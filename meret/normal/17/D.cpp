#include <cstdio>
#include <cstring>
#include <cstdlib>

typedef long long LL;

int p[40005], cp;
bool np[40005];

void era() {
	for (int i = 2; i <= 40000; ++i) {
		if (!np[i]) {
			p[cp++] = i;
			for (int j = i * i; j <= 40000; j += i)
				np[j] = 1;
		}
	}
}

int fi(int x) {
	int res = 1;
	for (int i = 0; i < cp && p[i] * p[i] <= x; ++i) {
		if (!(x % p[i])) {
			res *= p[i] - 1;
			x /= p[i];
			while (!(x % p[i])) {
				res *= p[i];
				x /= p[i];
			}
		}
	}
	if (x > 1)
		res *= x - 1;
	return res;
}

const int LEN = 1000005;

char bs[LEN], ns[LEN];

int conv(char* s, int m) {
	int res = 0;
	for (int i = 0; s[i]; ++i) {
		res = (10LL * res + s[i] - '0') % m;
	}
	return res;
}

int gcd(int a, int b){
	while (a && b) a > b ? a %= b : b %= a;
	return a + b;
}

int main() {
	era();
	int c;
	scanf("%s %s %d", bs, ns, &c);
	int b = conv(bs, c);
	int n;
	int res = (c + b - 1) % c;
	if (strlen(ns) < 4)
		n = atoi(ns) - 1;
	else
		n = conv(ns, fi(c)) + fi(c) - 1;
	while (n) {
		if (n & 1) res = (LL(res) * b) % c;
		b = (LL(b) * b) % c;
		n >>= 1;
	}
	if (res == 0)
		res = c;
	printf("%d\n", res);
}