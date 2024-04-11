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

const int maxn = 2100;

int n, m;
double f[maxn + 5][maxn + 5];

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	f[0][0] = 1;
	REP(ipj, 1, n + m + 1)
	{
		REP(i, 0, ipj + 1)
		{
			int j = ipj - i;
			if (!i) f[i][j] = 1. / (j + 1);
			else if (!j) f[i][j] = 1;
			else
			{
				double &u = f[j][i - 1], &v = f[j - 1][i];
				double invnj = 1. / (j + 1);
				double a = u + invnj, b = (1 - u - (1 + j - j * v) * invnj), c = -invnj, d = (1 + j - j * v) * invnj;
				f[i][j] = invnj;
				double mid = -c / a;
				if (mid > 0)
				{
					if (a + b < 0) chkmax(f[i][j], c + d);
					else chkmax(f[i][j], (a + b) * mid + c + d);
				}
				if (mid < 1)
				{
					if (b < 0) chkmax(f[i][j], b * mid + d);
					else chkmax(f[i][j], b + d);
				}
			}
		}
	}
	printf("%.15f %.15f\n", f[n][m], 1 - f[n][m]);
	return 0;
}