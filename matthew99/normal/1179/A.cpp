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

const int maxn = 100010;

int n;
int a[maxn + 5];

pair<int, int> ans[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int qn;
	scanf("%d", &qn);
	REP(i, 0, n) scanf("%d", a + i);
	int Max = *max_element(a, a + n);
	REP(i, 0, n - 1)
	{
		ans[i] = mp(a[i], a[i + 1]);
		if (a[i] > a[i + 1]) swap(a[i], a[i + 1]);
	}
	REP(i, 0, qn)
	{
		LL x;
		scanf("%" LLFORMAT "d", &x), --x;
		if (x < n - 1) printf("%d %d\n", ans[x].x, ans[x].y);
		else printf("%d %d\n", Max, a[x % (n - 1)]);
	}
	return 0;
}