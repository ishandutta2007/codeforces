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
#include <climits>

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

const int maxn = 10;

int a[1 << maxn];
int sum[1 << maxn];

int Max[1 << maxn];

int ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	++n;
	REP(i, 2, 1 << n) scanf("%d", a + i);
	for (int i = (1 << (n - 1)) - 1; i >= 1; --i) Max[i] = max((a[i << 1] + Max[i << 1]), (a[i << 1 | 1] + Max[i << 1 | 1]));
	REP(i, 1, i << (n - 1)) ans += abs(Max[i << 1] + a[i << 1] - (Max[i << 1 | 1] + a[i << 1 | 1]));
	printf("%d\n", ans);
	return 0;
}