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

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 710;

int n;
int a[maxn + 5];

bool ok[maxn + 5][maxn + 5];
bool dpl[maxn + 5][maxn + 5], dpr[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) REP(j, 0, n) ok[i][j] = __gcd(a[i], a[j]) > 1;

	REP(l, 1, n + 1) REP(i, 0, n - l + 1)
	{
		int j = i + l;
		if (l == 1) dpl[i][j] = dpr[i][j] = 1;
		else
		{
			REP(k, i, j)
			{
				if (k + 1 < j && ok[j - 1][k] && dpl[i][k + 1] && dpr[k][j - 1]) dpl[i][j] = 1;
				if (k > i && ok[i][k] && dpl[i + 1][k + 1] && dpr[k][j]) dpr[i][j] = 1;
			}
		}
	}

	bool yes = 0;
	REP(i, 0, n) if (dpl[0][i + 1] && dpr[i][n]) { yes = 1; break; }
	if (yes) puts("Yes");
	else puts("No");
	return 0;
}