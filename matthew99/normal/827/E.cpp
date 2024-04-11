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

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int Mod = 998244353, fft_g = 3;

const int maxn = 1100000;

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

inline void fft_prepare(int n)
{
	int L = 0;
	for ( ; (1 << L) < n; ++L);
	N = 1 << L;
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	int step = fpm(fft_g, (Mod - 1) / N, Mod);
	w[0] = 1;
	REP(i, 0, N) w[i + 1] = (LL)w[i] * step % Mod;
}

int T;

int n;
int a[maxn + 5], b[maxn + 5];

char s[maxn + 5];

bool ban[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		scanf("%s", s);
		fft_prepare(n << 1);
		REP(i, 0, N) a[i] = b[i] = 0;
		REP(i, 0, n) if (s[i] == 'V') a[i] = 1; else if (s[i] == 'K') b[n - i - 1] = 1;
		fft(a, N);
		fft(b, N);
		REP(i, 0, N) a[i] = (LL)a[i] * b[i] % Mod;
		fft(a, N);
		reverse(a + 1, a + N);
		REP(i, 1, n + 1) ban[i] = 0;
		REP(i, 0, n << 1) if (a[i]) ban[abs(i - (n - 1))] = 1;
		for (int i = 1; i <= n; ++i) if (!ban[i])
			for (int j = i << 1; j <= n; j += i) if (ban[j])
			{
				ban[i] = 1;
				break;
			}
		vector<int> all;
		REP(i, 1, n + 1) if (!ban[i]) all.pb(i);
		printf("%d\n", SZ(all));
		for (auto u : all) printf("%d ", u);
		printf("\n");
	}
	return 0;
}