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

const int maxn = 110;

char s[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	scanf("%d", &T);
	while (T--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		REP(i, 0, n) scanf("%s", s[i]);
		bool flag = 0;
		REP(i, 0, n) REP(j, 0, m) if (s[i][j] == 'A') flag = 1;
		if (!flag)
		{
			printf("MORTAL\n");
			continue;
		}
		flag = 0;
		REP(i, 0, n) REP(j, 0, m) if (s[i][j] == 'P') flag = 1;
		if (!flag)
		{
			printf("0\n");
			continue;
		}
		flag = 1;
		REP(i, 0, m) if (s[0][i] != 'A') flag = 0;
		if (flag)
		{
			printf("1\n");
			continue;
		}
		flag = 1;
		REP(i, 0, m) if (s[n - 1][i] != 'A') flag = 0;
		if (flag)
		{
			printf("1\n");
			continue;
		}
		flag = 1;
		REP(i, 0, n) if (s[i][0] != 'A') flag = 0;
		if (flag)
		{
			printf("1\n");
			continue;
		}
		flag = 1;
		REP(i, 0, n) if (s[i][m - 1] != 'A') flag = 0;
		if (flag)
		{
			printf("1\n");
			continue;
		}

		REP(i, 0, n)
		{
			flag = 1;
			REP(j, 0, m) if (s[i][j] != 'A') 
			{
				flag = 0;
				break;
			}
			if (flag) break;
		}
		if (flag)
		{
			printf("2\n");
			continue;
		}

		REP(i, 0, m)
		{
			flag = 1;
			REP(j, 0, n) if (s[j][i] != 'A')
			{
				flag = 0;
				break;
			}
			if (flag) break;
		}
		if (flag)
		{
			printf("2\n");
			continue;
		}

		if (s[0][0] == 'A' || s[0][m - 1] == 'A' || s[n - 1][0] == 'A' || s[n - 1][m - 1] == 'A')
		{
			printf("2\n");
			continue;
		}

		flag = 0;
		REP(i, 0, n) if (s[i][0] == 'A' || s[i][m - 1] == 'A') flag = 1;
		REP(i, 0, m) if (s[0][i] == 'A' || s[n - 1][i] == 'A') flag = 1;

		if (flag)
		{
			printf("3\n");
			continue;
		}
		printf("4\n");
	}
	return 0;
}