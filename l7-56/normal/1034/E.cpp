#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n,N,popcnt[(1 << 21) + 10];
void FWT_or(ll *f, int flg) {
	for (int len = 2, hlf = 1; len <= N; len <<= 1, hlf <<= 1)
		for (int i = 0; i < N; i += len)
			for (int k = i; k < i + hlf; ++k)
				f[k + hlf] += flg * f[k];
}
ll a[(1 << 21) + 10],b[(1 << 21) + 10];
char s[(1 << 21) + 10],t[(1 << 21) + 10];

int main() {
	scanf("%d%s%s", &n, s, t);
	N = (1 << n);
	for (int i = 0; i < N; ++i) {
		popcnt[i] = popcnt[i >> 1] + (i & 1);
		a[i] = (s[i] - '0') * (1ll << (popcnt[i] << 1));
		b[i] = (t[i] - '0') * (1ll << (popcnt[i] << 1));
	}
	FWT_or(a, 1), FWT_or(b, 1);
	for (int i = 0; i < N; ++i) a[i] *= b[i];
	FWT_or(a, -1);
	for (int i = 0; i < N; ++i) putchar(((a[i] >> (popcnt[i] << 1)) & 3) + 48);
	putchar('\n');
	return 0;
}