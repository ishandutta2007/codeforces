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

const int maxn = 100, maxm = 1000;

int n;
int p[maxn + 5];
long double dp[2][maxn * maxm + 5];
long double tot = 1;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int m;
	scanf("%d%d", &n, &m);
	if (m == 1)
	{
		printf("1\n");
		return 0;
	}
	int val = 0;
	tot = 1;
	REP(i, 0, n) scanf("%d", p + i), val += p[i], tot *= (m - 1);
	dp[0][0] = 1;
	REP(i, 0, n)
	{
		int cur = i & 1, nxt = !cur;
		long double sum = 0;
		REP(j, 0, val)
		{
			dp[nxt][j] = sum - (j >= p[i] ? dp[cur][j - p[i]] : (long double)0);
			sum += dp[cur][j];
			if (j >= m) sum -= dp[cur][j - m];
		}
	}
	double tot0 = 0;
	REP(i, 0, val) 
	{
		tot0 += dp[n & 1][i];
	}
	printf("%.15f\n", (double)(tot0 / tot) * (m - 1) + 1);
	return 0;
}