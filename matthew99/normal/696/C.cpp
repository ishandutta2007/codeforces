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

const int Mod = 1e9 + 7;

inline int fpm(LL b, LL e, int m)
{
	b %= m;
	LL t = 1;
	for ( ; e; e >>= 1, (b *= b) %= m)
		if (e & 1) (t *= b) %= m;
	return t;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int K;
	Read(K);
	int ans = 2;
	LL n = 1;
	bool flag = 1;
	REP(i, 0, K)
	{
		LL x;
		Read(x);
		flag &= (x & 1);
		if (LLONG_MAX / x >= n) n *= x;
		else n = LLONG_MAX;
		ans = fpm(ans, x, Mod);
	}
	if (n == 1) puts("0/1");
	else
	{
		ans = (LL)ans * ((Mod + 1) >> 1) % Mod;
		int tmp = ans;
		if (flag) (ans -= 1) %= Mod;
		else (ans += 1) %= Mod;
		ans = (LL)ans * ((Mod + 1) / 3) % Mod;
		printf("%d/%d\n", ans, tmp);
	}
	return 0;
}