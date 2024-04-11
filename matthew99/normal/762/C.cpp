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

const int maxn = 100010;

int n, m;
char a[maxn + 5], b[maxn + 5];

int pre[maxn + 5], suf[maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%s%s", a, b);
	n = strlen(a);
	m = strlen(b);
	pre[0] = 0;
	REP(i, 0, n)
	{
		pre[i + 1] = pre[i];
		if (pre[i] < m && a[i] == b[pre[i]]) ++pre[i + 1];
	}
	suf[n] = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		suf[i] = suf[i + 1];
		if (suf[i] < m && a[i] == b[m - suf[i] - 1]) ++suf[i];
	}
	int ans = -1, ansp = -1;
	REP(i, 0, n + 1) if (chkmax(ans, pre[i] + suf[i])) ansp = i;
	if (!ans) puts("-");
	else
	{
		REP(i, 0, pre[ansp]) putchar(b[i]);
		REP(i, max(pre[ansp], m - suf[ansp]), m) putchar(b[i]);
	}
	return 0;
}