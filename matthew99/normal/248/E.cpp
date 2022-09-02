//
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>
#include <vector>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

const double eps = 1e-12;

const int maxn = 1e5;
const int maxa = 1e2;

double prob[maxn + 5][maxa + 5], ans = 0;
int n, m, cnt[maxn + 5];
double dp[maxa + 5][maxa + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n), ans = 0;

	REP(i, 0, n)
	{
		scanf("%d", cnt + i);
		if (!cnt[i]) ++ans;
		prob[i][cnt[i]] = 1;
	}

	scanf("%d", &m);

	REP(i, 0, m)
	{
		static int u, v, k;
		scanf("%d%d%d", &u, &v, &k), --u, --v;

		int tot = cnt[u];

		memset(prob[n], 0, sizeof prob[n]);
		REP(j, 0, min(maxa, cnt[u]) + 1)
			if(prob[u][j] > eps)
			{
				REP(a, 0, k + 1)
					REP(b, 0, k + 1)
						dp[a][b] = 0;
				dp[0][0] = prob[u][j];
				REP(a, 0, k + 1)
					REP(b, 0, k + 1)
					{
						dp[a + 1][b] += dp[a][b] * double(tot - j - (a - b)) / (tot - a);
						dp[a + 1][b + 1] += dp[a][b] * double(j - b) / (tot - a);
					}

				REP(a, 0, k + 1) 
					if(a <= j && k - a <= tot - j) prob[n][j - a] += dp[k][a];
			}

		ans -= prob[u][0];
		REP(j, 0, maxa + 1) prob[u][j] = prob[n][j];
		ans += prob[u][0];

		cnt[u] -= k, cnt[v] += k;

		printf("%.15lf\n", ans);
	}

	return 0;
}