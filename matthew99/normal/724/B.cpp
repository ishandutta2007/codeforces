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

const int maxn = 100;

int n, m;

int a[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) REP(j, 0, m) scanf("%d", a[i] + j), --a[i][j];
	REP(i, 0, m) REP(j, 0, i + 1)
	{
		static int p[maxn + 5];
		REP(k, 0, m) p[k] = k;
		swap(p[i], p[j]);
		bool failed = 0;
		REP(k, 0, n)
		{
			int cnt = 0;
			REP(l, 0, m) if (a[k][l] != p[l]) ++cnt;
			if (cnt > 2) { failed = 1; break; }
		}
		if (!failed) puts("YES"), exit(0);
	}
	puts("NO");
	return 0;
}