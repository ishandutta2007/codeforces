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

const int maxn = 100000;

int n;
int a[maxn + 5];

bool check(int x, int y, int z)
{
	return (LL)(a[y] - a[x]) * (z - x) - (LL)(y - x) * (a[z] - a[x]) < 0;
}

inline int get_val(int x, int y)
{
	return (a[y] - a[x] + (y - x) - 1) / (y - x);
}

int val[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int qn;
	scanf("%d%d", &n, &qn);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, qn)
	{
		int l, r;
		scanf("%d%d", &l, &r), --l;
		LL ans = 0;
		val[r - 1] = 0;
		REP(i, l, r - 1) val[i] = abs(a[i + 1] - a[i]);
		int stk[maxn + 5];
		int tot = 0;
		LL sum = 0;
		REP(i, l, r)
		{
			if (tot) ans += sum + (i - stk[tot - 1] - 1) * LL(val[stk[tot - 1]]);
			while (tot && val[stk[tot - 1]] < val[i]) 
			{
				if (tot > 1) sum -= LL(stk[tot - 1] - stk[tot - 2]) * val[stk[tot - 1]];
				else sum -= LL(stk[tot - 1] - l + 1) * val[stk[tot - 1]];
				--tot;
			}
			if (tot) sum += LL(i - stk[tot - 1]) * val[i];
			else sum += (LL)(i - l + 1) * val[i];
			stk[tot++] = i;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}