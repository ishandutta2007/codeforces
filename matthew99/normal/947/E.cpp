#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

typedef long long LL;

const int Mod = 998244353, fft_g = 3;

const int maxn = 262144;

inline int fpm(LL b, int e, const int &m)
{
	LL t = 1;
	for ( ; e; (b *= b) %= m, e >>= 1)
		if (e & 1) (t *= b) %= m;
	return t;
}

int N;

int w[maxn + 5];
int bitrev[maxn + 5];

inline void fft(int *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
	{
		for (int j = 0; j < n; j += i)
		{
			int *l = a + j, *r = a + j + (i >> 1), *p = w;
			REP(k, 0, i >> 1)
			{
				int tmp = (LL)*r * *p % Mod;
				(*r = *l - tmp) %= Mod;
				(*l += tmp) %= Mod;
				++l, ++r;
				p += lyc;
			}
		}
	}
}

inline void fft_prepare()
{
	int L = 0;
	for ( ; (1 << L) < N; ++L);
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	int step = fpm(fft_g, (Mod - 1) / N, Mod);
	w[0] = 1;
	REP(i, 0, N) w[i + 1] = (LL)w[i] * step % Mod;
}

int fac[maxn + 5], ifac[maxn + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, maxn) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[maxn] = fpm(fac[maxn], Mod - 2, Mod);
	for (int i = maxn - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

int n;
LL m;

int inv[maxn + 5];

int ans[maxn + 5];

int a[maxn + 5], b[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	prepare();
	cin >> n >> m;
	N = (n + 1) << 1;
	while (N & (N - 1)) ++N;
	int invN = fpm(N, Mod - 2, Mod);
	fft_prepare();
	REP(i, 0, n + 1)
	{
		inv[i] = fpm(n + 1 - i, (-m % (Mod - 1) + Mod - 1) % (Mod - 1), Mod);
	}
	REP(i, 0, n + 1) scanf("%d", a + i);
	static int tmp0[maxn + 5], tmp1[maxn + 5];
	REP(i, 0, n + 1)
	{
		tmp0[i] = (LL)a[i] * fac[i] % Mod;
	}
	REP(i, 0, n + 1)
	{
		tmp1[i] = ifac[n - i];
	}
	REP(i, n + 1, N) tmp0[i] = tmp1[i] = 0;
	fft(tmp0, N);
	fft(tmp1, N);
	REP(i, 0, N) tmp0[i] = (LL)tmp0[i] * tmp1[i] % Mod;
	fft(tmp0, N);
	reverse(tmp0 + 1, tmp0 + N);
	REP(i, 0, N) tmp0[i] = (LL)tmp0[i] * invN % Mod;

	REP(i, 0, n + 1) 
	{
		b[i] = tmp0[2 * n - i];
		b[i] = (LL)b[i] * fac[i] % Mod * ifac[n] % Mod;
	}
	REP(i, 0, n + 1) b[i] = (LL)b[i] * inv[i] % Mod;

	REP(i, 0, n + 1)
	{
		tmp0[i] = (LL)b[i] * ifac[i] % Mod;
	}
	REP(i, 0, n + 1)
	{
		tmp1[i] = ifac[i];
		if (i & 1) tmp1[i] = -tmp1[i];
	}
	REP(i, n + 1, N) tmp0[i] = tmp1[i] = 0;
	fft(tmp0, N);
	fft(tmp1, N);
	REP(i, 0, N) tmp0[i] = (LL)tmp0[i] * tmp1[i] % Mod;
	fft(tmp0, N);
	reverse(tmp0 + 1, tmp0 + N);
	REP(i, 0, N) tmp0[i] = (LL)tmp0[i] * invN % Mod;
	REP(i, 0, n + 1) debug("%d ", tmp0[i]);
	debug("\n");

	REP(i, 0, n + 1)
	{
		ans[i] = tmp0[n - i];
		ans[i] = (LL)ans[i] * fac[n] % Mod * ifac[i] % Mod;
	}

	REP(i, 0, n + 1) debug("%d ", ans[i]);
	debug("\n");

	REP(i, 0, n + 1)
	{
		(ans[i] += Mod) %= Mod;
		printf("%d ", ans[i]);
	}

	return 0;
}