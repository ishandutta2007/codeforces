#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int maxm = 20, maxn = 1 << maxm;

int m, n;
LL e[maxn + 5], b[maxm + 5], a[maxn + 5];
LL P, t;

void init()
{
	scanf("%d%I64d%I64d", &m, &t, &P), n = 1 << m, P *= n;
	REP(i, 0, n) scanf("%d", e + i);
	REP(i, 0, m + 1) scanf("%d", b + i);
}

int bit_count(int x)
{
	x = ((x & 0xAAAAAAAA) >> 1) + (x & 0x55555555);
	x = ((x & 0xCCCCCCCC) >> 2) + (x & 0x33333333);
	x = ((x & 0xf0f0f0f0) >> 4) + (x & 0x0f0f0f0f);
	x = ((x & 0xff00ff00) >> 8) + (x & 0x00ff00ff);
	return x = ((x & 0xffff0000) >> 16) + (x & 0x0000ffff);
}

void fwt(LL *x, const int &n)
{
	if (n == 0) return;
	int half = n >> 1;
	fwt(x, half), fwt(x + half, half);
	REP(i, 0, half) 
	{
		LL s = x[i], t = x[i + half];
		x[i] = (s + t) % P;
		x[i + half] = (s - t) % P;
	}
}

LL fmm(const LL &x, const LL &y, const LL &mod)
{
	return (x * y - (LL)(((long double)x * y + 0.5) / mod) * mod);
}

LL fpm(LL b, LL e, const LL &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, b = fmm(b, b, m))
		if (e & 1) t = fmm(t, b, m);
	return t;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	REP(i, 0, n) a[i] = b[bit_count(i)];
	fwt(a, n), fwt(e, n);
	REP(i, 0, n) e[i] = fmm(e[i], fpm(a[i], t, P), P);
	fwt(e, n);
	P /= n;
	REP(i, 0, n) ((e[i] /= n) += P) %= P;
	REP(i, 0, n) printf("%I64d\n", e[i]);
	printf("\n");
	return 0;
}