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

const int maxn = 1010;

int n;
int a[maxn + 5][5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) REP(j, 0, 5) scanf("%d", a[i] + j);
	if (n >= 100)
	{
		printf("0\n");
	}
	else
	{
		vector<int> ans;
		REP(i, 0, n)
		{
			bool failed = 0;
			REP(j, 0, n) if (j != i)
				REP(k, 0, j) if (k != i)
				{
					int sum = 0;
					REP(l, 0, 5)
						sum += (a[j][l] - a[i][l]) * (a[k][l] - a[i][l]);
					if (sum > 0) failed = 1;
				}
			if (!failed) ans.pb(i);
		}
		printf("%d\n", SZ(ans));
		for (auto u : ans) printf("%d\n", u + 1);
	}
	return 0;
}