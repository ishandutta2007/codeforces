#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <cctype>
#include <cassert>
#include <ctime>
#include <set>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 50;

int n;
char a[maxn + 5][maxn + 5];

char ans[(maxn << 1) + 5][(maxn << 1) + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	assert(n > 0);
	REP(i, 0, n)
		scanf("%s", a[i]);
	memset(ans, 'x', sizeof ans);
	ans[n - 1][n - 1] = 'o';
	REP(i, 0, n)
		REP(j, 0, n)
			if (a[i][j] == 'o')
				REP(k, -n + 1, n)
					REP(l, -n + 1, n)
					{
						int u = i + k, v = j + l;
						if (u >= 0 && u < n && v >= 0 && v < n && a[u][v] == '.') ans[k + n - 1][l + n - 1] = '.';
					}
	REP(i, 0, n)
		REP(j, 0, n)
			if (a[i][j] == 'o')
				REP(k, -n + 1, n)
					REP(l, -n + 1, n)
					{
						int u = i + k, v = j + l;
						if (u >= 0 && u < n && v >= 0 && v < n && a[u][v] == 'x' && ans[k + n - 1][l + n - 1] == 'x') a[u][v] = '.';
					}
	REP(i, 0, n)
		REP(j, 0, n)
			if (a[i][j] == 'x') EXIT("NO\n");
	printf("YES\n");
	REP(i, 0, (n << 1) - 1)
	{
		REP(j, 0, (n << 1) - 1) printf("%c", ans[i][j]);
		printf("\n");
	}
	return 0;
}