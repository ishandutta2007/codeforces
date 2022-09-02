#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
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

const int Mod = 1e9 + 7;

const int maxk = 30000, max0 = 65536, max1 = 30;

int fac[maxk + 5], ifac[maxk + 5];

inline int fpm(LL b, int e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

LL n;
int K;
int ans;

struct comp
{
	double x, y;

	comp(): x(0), y(0) { }
	comp(const double &_x, const double &_y): x(_x), y(_y) { }

};

inline comp operator+(const comp &a, const comp &b) { return comp(a.x + b.x, a.y + b.y); }
inline comp operator-(const comp &a, const comp &b) { return comp(a.x - b.x, a.y - b.y); }
inline comp operator*(const comp &a, const comp &b) { return comp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline comp conj(const comp &a) { return comp(a.x, -a.y); }

const double PI = acos(-1);

int N, L;

comp w[max0 + 5];
int bitrev[max0 + 5];

inline void prepare()
{
	fac[0] = 1;
	REP(i, 0, K) fac[i + 1] = (LL)fac[i] * (i + 1) % Mod;
	ifac[K] = fpm(fac[K], Mod - 2, Mod);
	for (int i = K - 1; i >= 0; --i) ifac[i] = (LL)ifac[i + 1] * (i + 1) % Mod;
}

void fft(comp *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 2, lyc = n >> 1; i <= n; i <<= 1, lyc >>= 1)
		for (int j = 0; j < n; j += i)
		{
			comp *l = a + j, *r = a + j + (i >> 1), *p = w;
			REP(k, 0, i >> 1)
			{
				comp tmp = *r * *p;
				*r = *l - tmp, *l = *l + tmp;
				++l, ++r, p += lyc;
			}
		}
}

inline void fft_prepare()
{
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	REP(i, 0, N) w[i] = comp(cos(2 * PI * i / N), sin(2 * PI * i / N));
}

inline void conv(int *x, int *y, int *z)
{
	REP(i, 0, K + 1) (x[i] += Mod) %= Mod, (y[i] += Mod) %= Mod;
	static comp a[max0 + 5], b[max0 + 5];
	static comp dfta[max0 + 5], dftb[max0 + 5], dftc[max0 + 5], dftd[max0 + 5];

	REP(i, 0, K + 1) a[i] = comp(x[i] & 32767, x[i] >> 15);
	REP(i, 0, K + 1) b[i] = comp(y[i] & 32767, y[i] >> 15);
	REP(i, K + 1, N) a[i] = b[i] = comp(0, 0);
	fft(a, N), fft(b, N);
	REP(i, 0, N)
	{
		int j = (N - i) & (N - 1);
		static comp da, db, dc, dd;
		da = (a[i] + conj(a[j])) * comp(0.5, 0);
		db = (a[i] - conj(a[j])) * comp(0, -0.5);
		dc = (b[i] + conj(b[j])) * comp(0.5, 0);
		dd = (b[i] - conj(b[j])) * comp(0, -0.5);
		dfta[j] = da * dc;
		dftb[j] = da * dd;
		dftc[j] = db * dc;
		dftd[j] = db * dd;
	}
	REP(i, 0, N) a[i] = dfta[i] + dftb[i] * comp(0, 1);
	REP(i, 0, N) b[i] = dftc[i] + dftd[i] * comp(0, 1);
	fft(a, N), fft(b, N);
	REP(i, 0, K + 1)
	{
		int da = (LL)(a[i].x / N + 0.5) % Mod;
		int db = (LL)(a[i].y / N + 0.5) % Mod;
		int dc = (LL)(b[i].x / N + 0.5) % Mod;
		int dd = (LL)(b[i].y / N + 0.5) % Mod;
		z[i] = (da + ((LL)(db + dc) << 15) + ((LL)dd << 30)) % Mod;
	}
}

inline void mul(int *a, int *b, const int &step)
{
	static int tmp[maxk + 5];
	int tmp0 = fpm(2, step, Mod), tmp1 = 1;
	REP(i, 0, K + 1) tmp[i] = (LL)a[i] * tmp1 % Mod, tmp1 = (LL)tmp1 * tmp0 % Mod;
	conv(tmp, b, a);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n >> K;
	N = (K + 1) << 1;
	L = 0;
	while ((1 << L) < N) ++L;
	N = 1 << L;
	prepare();
	fft_prepare();
	if (n > K) printf("0\n");
	else
	{
		static vector<int> path[maxk + 5];
		static int q[maxk + 5];
		int head = 0, rear = 0;
		REP(i, 0, n + 1) path[i].clear();
		path[1].pb(1);
		q[rear++] = 1;
		while (head != rear)
		{
			int x = q[head++];
			for (auto y : path[x])
			{
				int u = x + y;
				if (u <= n && !SZ(path[u])) path[u] = path[x], path[u].pb(u), q[rear++] = u;
			}
		}
		static int ret[maxk + 5], tmp[max1][maxk + 5];
		memset(tmp, 0, sizeof tmp);
		ret[0] = 1;
		REP(i, 1, K + 1) tmp[0][i] = ifac[i];
		REP(i, 1, SZ(path[n]))
		{
			memcpy(tmp[i], tmp[i - 1], sizeof tmp[i]);
			REP(j, 0, i) if (path[n][i - 1] + path[n][j] == path[n][i]) mul(tmp[i], tmp[j], path[n][j]);
		}
		memcpy(ret, tmp[SZ(path[n]) - 1], sizeof ret);
		ans = 0;
		REP(i, 0, K + 1) (ans += (LL)ret[i] * ifac[K - i] % Mod * fac[K] % Mod) %= Mod;
		(ans += Mod) %= Mod;
		printf("%d\n", ans);
	}
	return 0;
}