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

#define ctz __builtin_ctzll
#define bcnt __builtin_popcountll

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxm = 100100;

LL n;
int qn;

int m;
char s[maxm + 5];

inline LL brev(LL x)
{
	LL ret = 0, now = (n + 1) >> 1;
	while (x)
	{
		if (x & 1) ret += now;
		x >>= 1;
		now >>= 1;
	}
	return ret;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%" LLFORMAT "d%d", &n, &qn);
	LL rt = (n + 1) >> 1;
	REP(i, 0, qn)
	{
		LL cur;
		scanf("%" LLFORMAT "d", &cur);
		scanf("%s", s);
		m = strlen(s);
		REP(j, 0, m)
		{
			LL tmp = cur & -cur;
			if (s[j] == 'U')
			{
				if (cur == rt) continue;
				cur -= tmp;
				if ((cur & -cur) != (tmp << 1)) cur += tmp << 1;
			}
			else if (s[j] == 'L') 
			{
				if (cur & 1) continue;
				cur -= tmp >> 1;
			}
			else 
			{
				if (cur & 1) continue;
				cur += tmp >> 1;
			}
		}
		printf("%" LLFORMAT "d\n", cur);
	}
	return 0;
}