#include <bits/stdc++.h>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const double pi = 3.1415926535897932384626;//3.141592655897932384626

const int oo = 0x3f3f3f3f;

template<typename T> bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }
template<typename T> bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }

struct comp
{
	double a, b;

	comp() { }
	comp(const double &_a, const double &_b): a(_a), b(_b) { }

	friend comp operator+(const comp &a, const comp &b) { return comp(a.a + b.a, a.b + b.b); }
	friend comp operator-(const comp &a, const comp &b) { return comp(a.a - b.a, a.b - b.b); }
	friend comp operator*(const comp &a, const comp &b) { return comp(a.a * b.a - a.b * b.b, a.a * b.b + a.b * b.a); }
};

const int maxN = 65536;
const int maxn = 50, maxm = 100, maxt = 20000;
const int max0 = 3000;

struct edge
{
	int id, g;
	double P[maxt + 5];
	int nxt;

	edge() { memset(P, 0, sizeof P); }
	edge(const int &_id, const int &_g, double *_P, const int &_nxt): id(_id), g(_g), nxt(_nxt) { memcpy(P, _P, sizeof P); }
};

int st[maxn + 5];
edge e[(maxm << 1) + 5];
int en = 0;

int f[maxn + 5][maxn + 5];

int n, m, T, X;

vector<int> reve[maxn + 5];

inline void init()
{
	memset(st, -1, sizeof st), en = 0;
	memset(f, oo, sizeof f);
	scanf("%d%d%d%d", &n, &m, &T, &X);
	REP(i, 0, n) f[i][i] = 0;
	REP(i, 0, m)
	{
		static int x, y, z;
		scanf("%d%d%d", &x, &y, &z), --x, --y;
		reve[y].push_back(en);
		chkmin(f[x][y], z);
		e[en].id = y;
		e[en].g = z;
		e[en].nxt = st[x];
		REP(j, 1, T + 1) 
		{
			static int x;
			scanf("%d", &x);
			e[en].P[j] = double(x) / 100000;
		}
		st[x] = en++;
	}
}

comp tmp[maxN + 5], tmp0[maxN + 5], w[maxN + 5];
int bitrev[maxN + 5];

double dp[maxm + 5][maxN + 5];
double best[maxn + 5][maxN + 5];

void fft(comp *a, const int &n)
{
	REP(i, 0, n) if (i < bitrev[i]) swap(a[i], a[bitrev[i]]);
	for (int i = 1, len = n >> 1; i < n; i <<= 1, len >>= 1)
		for (int j = 0; j < n; j += (i << 1))
		{
			comp *l = a + j, *r = a + j + i;
			comp *w0 = w;
			for (int k = 0; k < i; ++k, ++l, ++r, w0 += len)
			{
				comp s = *l, t = *r * *w0;
				*l = s + t, *r = s - t;
			}
		}
}

inline void calc(const int &l, const int &mid, const int &r)
{
	int N = mid - l + min(T, r - l - 1);
	while (N & (N - 1)) ++N;
	if (r - l <= max0)
	{
		REP(x, 0, n)
		{
			for (int i = st[x]; i != -1; i = e[i].nxt)
				REP(k, l, mid) 
					chkmin(best[x][k], dp[i][k] + e[i].g);
			for (auto i : reve[x])
			{
				REP(j, l, mid)
					REP(k, max(1, mid - j), min(r - j, T + 1))
						dp[i][j + k] += best[x][j] * e[i].P[k];
			}
		}
		return;
	}
	comp step = comp(cos(2 * pi / N), sin(2 * pi / N));
	w[0] = comp(1, 0);
	REP(i, 0, N) w[i + 1] = w[i] * step;
	int L = 0;
	for (L = 0; (1 << L) < N; ++L);
	REP(i, 0, N) bitrev[i] = (bitrev[i >> 1] >> 1) | ((i & 1) << (L - 1));
	REP(x, 0, n)
	{
		for (int i = st[x]; i != -1; i = e[i].nxt)
			REP(k, l, mid) 
				chkmin(best[x][k], dp[i][k] + e[i].g);
		REP(j, 0, N) tmp[j] = comp(0, 0);
		REP(j, l, mid) tmp[j - l] = comp(best[x][j], 0);
		fft(tmp, N);
		for (auto i : reve[x])
		{
			REP(j, 0, N) tmp0[j] = comp(0, 0);
			REP(j, 1, min(T + 1, r - l)) tmp0[j] = comp(e[i].P[j], 0);
			fft(tmp0, N);
			REP(j, 0, N) tmp0[j] = tmp0[j] * tmp[j];
			reverse(w + 1, w + N);
			fft(tmp0, N);
			reverse(w + 1, w + N);
			REP(j, mid, r) dp[i][j] += tmp0[j - l].a / N;
		}
	}
}

inline void work(const int &l, const int &r)
{
	if (r - l <= 1) 
	{
		REP(x, 0, n)
			for (int i = st[x]; i != -1; i = e[i].nxt)
				REP(k, l, r) chkmin(best[x][k], dp[i][k] + e[i].g);
		return;
	}
	int mid = (l + r) >> 1;
	work(l, mid);
	calc(l, mid, r);
	work(mid, r);
}

inline void solve()
{
	REP(k, 0, n)
		REP(i, 0, n)
			REP(j, 0, n)
				chkmin(f[i][j], f[i][k] + f[k][j]);
	REP(i, 0, en)
		REP(j, 0, T << 1 | 1)
			if (j <	T) dp[i][j] = f[e[i].id][n - 1] + X;
			else dp[i][j] = 0;
	REP(i, 0, n)
		REP(j, 0, T << 1 | 1)
			best[i][j] = (i == n - 1 ? (j < T ? X : 0) : oo);
	calc(0, T, T << 1 | 1);
	work(T, T << 1 | 1);
}

inline void output()
{
	printf("%.10f\n", best[0][T << 1]);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	solve();
	output();
	return 0;
}