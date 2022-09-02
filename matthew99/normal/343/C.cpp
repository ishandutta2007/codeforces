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

typedef long long LL;

const int maxn = 100000, maxm = 100000;

int n, m;
LL a[maxn + 5];
LL b[maxm + 5];

inline LL calc(int x, int l, int r)
{
	if (b[l] >= a[x]) return b[r] - a[x];
	if (b[r] <= a[x]) return a[x] - b[l];
	return min(((a[x] - b[l]) << 1) + (b[r] - a[x]), ((a[x] - b[l]) + ((b[r] - a[x]) << 1)));
}

inline bool work(LL x)
{
	int j = 0;
	REP(i, 0, n)
	{
		int k = j;
		while (k < m && calc(i, j, k) <= x) ++k;
		j = k;
	}
	return j == m;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Read(n), Read(m);
	REP(i, 0, n) Read(a[i]);
	REP(i, 0, m) Read(b[i]);
	LL l = 0, r = 20000000000LL;
	while (l < r)
	{
		LL mid = (l + r) >> 1;
		if (!work(mid)) l = mid + 1;
		else r = mid;
	}
	printf("%I64d\n", l);
	return 0;
}