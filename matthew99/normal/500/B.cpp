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

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

using namespace std;

typedef long long LL;

const int maxn = 300;

int n;
int a[maxn + 5];
bool f[maxn + 5][maxn + 5];
char c[maxn + 5][maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d", a + i);
	REP(i, 0, n) scanf("%s", c[i]);
	REP(i, 0, n)
		REP(j, 0, n)
			f[i][j] = c[i][j] == '1';
	REP(i, 0, n) f[i][i] = 1;
	REP(k, 0, n)
		REP(i, 0, n)
			REP(j, 0, n)
				f[i][j] |= f[i][k] & f[k][j];
	REP(i, 0, n)
	{
		int Minp = -1;
		REP(j, i, n)
			if (f[i][j] && (Minp == -1 || a[j] < a[Minp])) Minp = j;
		printf("%d ", a[Minp]);
		swap(a[i], a[Minp]);
	}
	printf("\n");
	return 0;
}