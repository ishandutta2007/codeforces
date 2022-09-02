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

LL n;
int m;
LL K;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%" LLFORMAT "d%d%" LLFORMAT "d", &n, &m, &K);
	LL lst = -1;
	int offset = 0;
	int ans = 0;
	REP(i, 0, m)
	{
		LL x;
		scanf("%" LLFORMAT "d", &x);
		--x;
		if ((x - offset) / K != lst)
		{
			++ans;
			offset = i;
			lst = (x - offset) / K;
		}
	}
	printf("%d\n", ans);
	return 0;
}