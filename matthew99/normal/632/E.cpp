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

const double pi = acos((double)-1);

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

const int max0 = 1048576;

int N;
int n, m;

comp a[max0 + 5], b[max0 + 5], c[max0 + 5];

comp w[max0 + 5];
int bitrev[max0 + 5];

comp w0[max0 + 5];

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

inline void conv(int *x, int n, int *y, int m, int *ans)
{
	int L = 0;
	for ( ; (1 << L) < (n + m) >> 1; ++L);
	int N = 1 << L;
	REP(i, 0, N) bitrev[i] = bitrev[i >> 1] >> 1 | ((i & 1) << (L - 1));
	int tmp = max0 / N;
	REP(i, 0, N) w[i] = w0[i * tmp];
	REP(i, 0, N)
	{
		a[i].x = (i << 1) < n ? x[i << 1] : 0.0;
		b[i].x = (i << 1) < m ? y[i << 1] : 0.0;
		a[i].y = (i << 1 | 1) < n ? x[i << 1 | 1] : 0.0;
		b[i].y = (i << 1 | 1) < m ? y[i << 1 | 1] : 0.0;
	}
	fft(a, N), fft(b, N);
	REP(i, 0, N)
	{
		int j = (N - i) & (N - 1);
		c[i] = (comp(4, 0) * conj(a[j] * b[j]) - (conj(a[j]) - a[i]) * (conj(b[j]) - b[i]) * (w[i] + comp(1, 0))) * comp(0, 0.25);
	}
	reverse(w + 1, w + N);
	fft(c, N);
	REP(i, 0, ((n + m - 1) >> 1) + 1)
	{
		ans[i << 1] = !!int(c[i].y / N + 0.5);
		ans[i << 1 | 1] = !!int(c[i].x / N + 0.5);
	}
}

int len_now, len_tmp;
int now[max0 + 5], tmp[max0 + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	REP(i, 0, max0) w0[i] = comp(cos(2 * pi * i / max0), sin(2 * pi * i / max0));
	int n, k;
	scanf("%d%d", &n, &k);
	len_now = 0;
	REP(i, 0, n)
	{
		int x;
		scanf("%d", &x);
		now[x] = 1;
		chkmax(len_now, x + 1);
	}
	len_tmp = 1;
	memset(tmp, 0, sizeof tmp);
	tmp[0] = 1;
	for ( ; k; k >>= 1, conv(now, len_now, now, len_now, now), --(len_now <<= 1))
		if (k & 1) conv(tmp, len_tmp, now, len_now, tmp), --(len_tmp += len_now);
	REP(i, 1, len_tmp) if (tmp[i]) printf("%d ", i);
	printf("\n");
	return 0;
}