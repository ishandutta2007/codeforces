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
#define LAST(x) ((x)[SZ(x) - 1])

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

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

const int Mod = 1e9 + 7;

const int maxn = 500000;

int n;
int x[(maxn << 1) + 5], y[(maxn << 1) + 5];

LL sum[(maxn << 1) + 5];
int summod[(maxn << 1) + 5];
int sumx[(maxn << 1) + 5];
int sumy[(maxn << 1) + 5];
int sumsum[(maxn << 1) + 5];

inline LL area(int l, int r)
{
	return sum[r] - sum[l] + (LL)x[r] * y[l] - (LL)x[l] * y[r];
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n);
	REP(i, 0, n) Read(x[i]), Read(y[i]), x[n + i] = x[i], y[n + i] = y[i];
	reverse(x, x + (n << 1));
	reverse(y, y + (n << 1));
	sum[0] = 0;
	REP(i, 0, n << 1) sum[i + 1] = sum[i] + (LL)x[i] * y[i + 1] - (LL)x[i + 1] * y[i];
	summod[0] = 0;
	REP(i, 0, n << 1) summod[i + 1] = (summod[i] + (LL)x[i] * y[i + 1] - (LL)x[i + 1] * y[i]) % Mod;
	sumsum[0] = 0;
	REP(i, 0, n << 1) (sumsum[i + 1] = sumsum[i] + summod[i]) %= Mod;
	sumx[0] = 0;
	REP(i, 0, n << 1) sumx[i + 1] = (sumx[i] + x[i]) % Mod;
	sumy[0] = 0;
	REP(i, 0, n << 1) sumy[i + 1] = (sumy[i] + y[i]) % Mod;
	int j = 0;
	int ans = 0;
	REP(i, 0, n)
	{
		while (area(i, j) <= area(j, i + n)) ++j;
		int l = j, r = i + n - 1, cnt = r - l;
		int lyc = (LL(summod[n + i]) * cnt - sumsum[r] + sumsum[l]) % Mod;
		(lyc += ((LL)x[n + i] * (sumy[r] - sumy[l]) - (LL)(sumx[r] - sumx[l]) * y[n + i]) % Mod) %= Mod;
		(ans += (LL(summod[n]) * cnt - (lyc << 1)) % Mod) %= Mod;
	}
	(ans += Mod) %= Mod;
	printf("%d\n", ans);
	return 0;
}