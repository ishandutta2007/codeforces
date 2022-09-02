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

const int maxn = 70100;

int n;

int a[maxn + 5];

int pw[11];

map<int, pair<int, int> > all;

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	pw[0] = 1;
	REP(i, 0, 10) pw[i + 1] = pw[i] * 10;
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n)
	{
		REP(j, 0, 9)
			REP(k, j + 1, 10)
			{
				int tmp = a[i] / pw[j] % pw[k - j] + pw[k - j];
				if (!all.count(tmp)) all[tmp] = mp(i, i);
				else chkmax(all[tmp].y, i);
			}
	}
	REP(i, 0, n)
	{
		int len = oo, ans = -1;
		REP(j, 0, 9)
			REP(k, j + 1, 10)
			{
				int tmp = a[i] / pw[j] % pw[k - j] + pw[k - j];
				if (all[tmp] == mp(i, i) && chkmin(len, k - j)) ans = tmp;
			}
		for (int j = len - 1; j >= 0; --j) printf("%d", int(ans / pw[j] % 10));
		printf("\n");
	}
	return 0;
}