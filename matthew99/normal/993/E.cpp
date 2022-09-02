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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

typedef complex<long double> comp;

const long double pi = acos((long double)-1);

const int oo = 0x3f3f3f3f;

const int maxn = 524288;

int m;
comp b[maxn + 5], c[maxn + 5];

int N;
comp w[maxn + 5];
int bitrev[maxn + 5];

inline void fft(comp *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
	{
		for (int j = 0; j < n; j += i)
		{
			comp *l = a + j, *r = a + j + (i >> 1), *p = w;
			REP(k, 0, i >> 1)
			{
				comp tmp = *r * *p;
				*r = *l - tmp;
				*l += tmp;
				++l, ++r;
				p += lyc;
			}
		}
	}
}

int n, x;
int a[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &x);
	REP(i, 0, n) scanf("%d", a + i);
	LL none = 0;
	int cnt = 0;
	REP(i, 0, n + 1)
	{
		++cnt;
		if (i == n || a[i] < x)
		{
			b[m++] = cnt;
			none += LL(cnt) * (cnt - 1) >> 1;
			cnt = 0;
		}
	}

	int L = 0;
	for ( ; (1 << L) < (m << 1); ++L);
	N = 1 << L;
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	REP(i, 0, N) w[i] = comp(cos((long double)i / N * 2 * pi), sin((long double)i / N * 2 * pi));

	memcpy(c, b, sizeof c);
	reverse(c, c + m);
	fft(b, N);
	fft(c, N);
	REP(i, 0, N) b[i] *= c[i];
	fft(b, N);
	reverse(b + 1, b + N);
	REP(i, 0, N) b[i] /= N;
	printf("%" LLFORMAT "d ", none);
	REP(i, 1, n + 1)
	{
		LL tmp = abs(b[i + m - 1]) + .5;
		printf("%" LLFORMAT "d ", tmp);
	}
	return 0;
}