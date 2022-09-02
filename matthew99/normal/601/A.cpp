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

const int maxn = 400;

int n, m;
int f[maxn + 5][maxn + 5];

const int __buffsize = 100000;
char __buff[__buffsize];
char *__buffs, *__buffe;

#define getc() (__buffs == __buffe ? fread(__buff, 1, __buffsize, stdin), __buffe = __buff + __buffsize, *((__buffs = __buff)++): *(__buffs++))

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

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(m);
	REP(i, 0, m)
	{
		int x, y;
		Read(x), Read(y), --x, --y;
		f[x][y] = 1;
		f[y][x] = 1;
	}
	if (f[0][n - 1])
	{
		REP(i, 0, n) REP(j, 0, n) f[i][j] = !f[i][j];
	}
	REP(i, 0, n) REP(j, 0, n) if (i != j && !f[i][j]) f[i][j] = oo;
	REP(k, 0, n) REP(i, 0, n) REP(j, 0, n) chkmin(f[i][j], f[i][k] + f[k][j]);
	if (f[0][n - 1] == oo) printf("-1\n");
	else printf("%d\n", f[0][n - 1]);
	return 0;
}