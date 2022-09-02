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

#ifdef __WIN32
#define LLFORMAT "I64"
#define Rand() ((rand() << 15) | rand())
#else
#define LLFORMAT "ll"
#define Rand() (rand())
#endif

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

//a.b.c.1234
//a2b3c41
//a.b.c.123
//a1b2c3

inline LL f(const LL &n, const LL &x)
{
	if (n == 1) return 0;
	if (n & 1)
	{
		if (x == n - 1) return (n >> 1) + f((n + 1) >> 1, 0); 
		if (x & 1)
		{
			return (n >> 1) + f((n + 1) >> 1, (x >> 1) + 1);
		}
		return x >> 1;
	}
	if (x & 1) 
		return (n >> 1) + f(n >> 1, x >> 1);
	return x >> 1;
}

LL n;
int qn;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%" LLFORMAT "d%d", &n, &qn);
	REP(i, 0, qn)
	{
		LL x;
		scanf("%" LLFORMAT "d", &x), --x;
		printf("%" LLFORMAT "d\n", f(n, x) + 1);
	}
	return 0;
}