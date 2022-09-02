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

LL Mod, fft_g;

inline LL mul(LL b, LL e, const LL &m)
{
	b %= m;
	e %= m;
	LL t = b * e - LL((long double)b * e / m) * m;
	while (t < 0) t += m;
	while (t >= m) t -= m;
	return t;
}
 
inline LL Fpm(LL b, LL e, const LL &m)
{
	LL t = 1;
	for ( ; e; e >>= 1, b = mul(b, b, m))
		if (e & 1) t = mul(t, b, m);
	return t;
}

const int maxn = 262144;

int N;

LL w[maxn + 5];
int bitrev[maxn + 5];

inline void fft(LL *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
	{
		for (int j = 0; j < n; j += i)
		{
			LL *l = a + j, *r = a + j + (i >> 1), *p = w;
			REP(k, 0, i >> 1)
			{
				LL tmp = mul(*r, *p, Mod);
				*r = (*l - tmp) % Mod;
				(*l += tmp) %= Mod;
				++l, ++r;
				p += lyc;
			}
		}
	}
}

const LL lim = 1.01e12;
const int lima = 9000;

inline void fft_prepare()
{
	int L = 31 - __builtin_clz(N);
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	LL step = Fpm(fft_g, (Mod - 1) / N, Mod);
	w[0] = 1;
	REP(i, 0, N) w[i + 1] = mul(w[i], step, Mod);
}

LL chirpz_w[maxn + 5];
LL chirpz_dft[maxn + 5];

LL chirpz_coe[maxn + 5];

inline void chirpz(LL *a, int n)
{
	static LL tmp[maxn + 5];
	REP(i, 0, n) tmp[i] = mul(a[i], chirpz_w[((n - ((LL)i * (i - 1) >> 1)) % n + n) % n], Mod);
	REP(i, n, N) tmp[i] = 0;
	fft(tmp, N);
	REP(i, 0, N) tmp[i] = mul(tmp[i], chirpz_coe[i], Mod);
	fft(tmp, N);
	reverse(tmp + 1, tmp + N);
	LL invN = Fpm(N, Mod - 2, Mod);
	REP(i, 0, N) tmp[i] = mul(tmp[i], invN, Mod); 
	REP(i, 0, N)
	{
		a[i] = mul(tmp[(n << 1) - 1 - i], chirpz_w[((n - ((LL)i * (i - 1) >> 1)) % n + n) % n], Mod);
	}
}

int n;

inline void chirpz_prepare()
{
	LL step = Fpm(fft_g, (Mod - 1) / n, Mod);
	chirpz_w[0] = 1;
	REP(i, 0, n) chirpz_w[i + 1] = mul(chirpz_w[i], step, Mod); 
	REP(i, 0, n << 1) chirpz_coe[(n << 1) - i - 1] = chirpz_w[((LL)i * (i - 1) >> 1) % n];
	REP(i, n << 1, N) chirpz_coe[i] = 0;
	fft(chirpz_coe, N);
}

inline void get_Mod()
{
	Mod = 1;
	LL each = (LL)N * n;
	Mod += (lim + each - 1) / each * each;
	while (1)
	{
		bool failed = 0;
		for (LL i = 2; i * i <= Mod; ++i)
			if (!(Mod % i))
			{
				failed = 1;
				break;
			}
		if (!failed) break;
		Mod += each;
	}
	fft_g = 2;
	while (1)
	{
		bool failed = 0;
		for (LL i = 2; i * i <= Mod - 1; ++i)
			if (!((Mod - 1) % i)) 
			{
				if (Fpm(fft_g, i, Mod) == 1) 
				{
					failed = 1;
					break;
				}
				if (Fpm(fft_g, (Mod - 1) / i, Mod) == 1) 
				{
					failed = 1;
					break;
				}
			}
		if (!failed) break;
		++fft_g;
	}
}

int b_input[maxn + 5], c_input[maxn + 5];
LL a[maxn + 5], b[maxn + 5], c[maxn + 5];

int ans[2][maxn + 5];
bool ok[2];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) 
	{
		scanf("%d", b_input + i);
	}
	REP(i, 0, n) 
	{
		scanf("%d", c_input + i);
	}
	reverse(c_input + 1, c_input + n);

	N = n << 1;
	while (N & (N - 1)) N += N & -N;

	get_Mod();
	fft_prepare();
	chirpz_prepare();

	REP(i, 0, n) b[i] = b_input[i], c[i] = mul((c_input[(i + 1) % n] - c_input[i]), -((Mod + 1) >> 1), Mod);
	REP(i, n, N) b[i] = c[i] = 0;
	chirpz(b, n);
	chirpz(c, n);
	REP(i, 0, n) 
	{
		a[i] = mul(c[i], Fpm(b[i], Mod - 2, Mod), Mod);
	}
	chirpz(a, n);
	reverse(a + 1, a + n);
	LL invn = Fpm(n, Mod - 2, Mod);
	REP(i, 0, n) a[i] = mul(a[i], invn, Mod);
	LL tmp_sum = 0;
	REP(i, 0, n) 
	{
		LL tmp_a = a[i];
		a[i] = tmp_sum;
		(tmp_sum += tmp_a) %= Mod;
	}
	reverse(a + 1, a + n);

	REP(i, 0, n)
	{
		(a[i] += Mod) %= Mod;
		if (a[i] > lima) a[i] = a[i] - Mod;
		if (a[i] < -lima) return puts("0"), 0;
	}

	LL c2 = 0, c1 = 0, c0 = -c_input[0];
	REP(i, 0, n)
	{
		c2 += 1;
		c1 -= (b_input[i] - a[i]) << 1;
		c0 += (b_input[i] - a[i]) * (b_input[i] - a[i]);
	}

	LL delta = c1 * c1 - 4 * c2 * c0;
	if (delta < 0) return puts("0"), 0;

	LL sqrtd = sqrt(delta) + .5;
	if (sqrtd * sqrtd != delta) return puts("0"), 0;
	if (!((-c1 - sqrtd) % (c2 << 1)))
	{
		ok[0] = 1;
		REP(i, 0, n) ans[0][i] = (-c1 - sqrtd) / (c2 << 1) + a[i];
	}
	if (sqrtd && !((-c1 + sqrtd) % (c2 << 1)))
	{
		ok[1] = 1;
		REP(i, 0, n) ans[1][i] = (-c1 + sqrtd) / (c2 << 1) + a[i];
	}
	printf("%d\n", ok[0] + ok[1]);
	REP(i, 0, 2) if (ok[i])
	{
		REP(j, 0, n) printf("%d ", ans[i][j]);
		printf("\n");
	}
	return 0;
}