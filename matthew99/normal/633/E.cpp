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

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++) : *(__buffs++))

template<typename T> inline T &Read(T &x)
{
	static char c;
	while (1) 
	{ 
		c = getc(); 
		if (c == '-' || (c >= '0' && c <= '9')) break; 
	}
	bool flag = c == '-';
	x = flag ? 0 : c - '0';
	while (1)
	{
		c = getc();
		if (c < '0' || c > '9') break;
		(x *= 10) += c - '0';
	}
	if (flag) x = -x;
	return x;
}

#undef getc

const int maxn = 1000000, max0 = 20;

int K, n;
int v[maxn + 5], c[maxn + 5];

int Maxv[max0][maxn + 5], Minc[max0][maxn + 5];

int Log[maxn + 5];

inline bool ty(int l, int r)
{
	int tmp = Log[r - l];
	return max(Maxv[tmp][l], Maxv[tmp][r - (1 << tmp)]) * 100 > min(Minc[tmp][l], Minc[tmp][r - (1 << tmp)]);
}

inline int calc(int l, int r)
{
	assert(l < r);
	int tmp = Log[r - l];
	return min(max(Maxv[tmp][l], Maxv[tmp][r - (1 << tmp)]) * 100, min(Minc[tmp][l], Minc[tmp][r - (1 << tmp)]));
}

int val[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(K);
	REP(i, 1, n + 1)
	{
		Log[i] = 0;
		int u = i;
		while (u >>= 1) ++Log[i];
	}
	REP(i, 0, n) Read(v[i]), Maxv[0][i] = v[i];
	REP(i, 0, n) Read(c[i]), Minc[0][i] = c[i];
	REP(i, 1, max0) REP(j, 0, n) if (j + (1 << (i - 1)) >= n) Maxv[i][j] = Maxv[i - 1][j], Minc[i][j] = Minc[i - 1][j]; else Maxv[i][j] = max(Maxv[i - 1][j], Maxv[i - 1][j + (1 << (i - 1))]), Minc[i][j] = min(Minc[i - 1][j], Minc[i - 1][j + (1 << (i - 1))]);
	REP(i, 0, n)
	{
		int l = i + 1, r = n;
		while (l < r)
		{
			int mid = (l + r + 1) >> 1;
			if (!ty(i, mid)) l = mid;
			else r = mid - 1;
		}
		val[i] = calc(i, l);
		if (l + 1 <= n) chkmax(val[i], calc(i, l + 1));
	}
	sort(val, val + n);
	double ans = 0;
	double now = (double)K / n;
	REP(i, 0, n - K + 1)
	{
		ans += val[i] * now;
		now /= n - i - 1;
		now *= n - i - K;
	}
	printf("%.15f\n", ans);
	return 0;
}