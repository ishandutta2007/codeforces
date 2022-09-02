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

const int maxn = 500, maxm = 1000;

int n, m;
int ans = 0;
int w[maxn + 5];
int id[maxn + 5];
int tot = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	REP(i, 0, n) scanf("%d", w + i);
	tot = 0;
	REP(i, 0, m)
	{
		static int x, cnt;
		scanf("%d", &x), --x;
		cnt = 0;
		for (int i = tot - 1; i >= 0; --i)
		{
			if (id[i] == x)
			{
				ans += cnt;
				for (int j = i; j < tot - 1; ++j) id[j] = id[j + 1];
				id[tot - 1] = x;
				goto yyt;
			}
			cnt += w[id[i]];
		}
		ans += cnt;
		id[tot++] = x;
		yyt:;
	}
	printf("%d\n", ans);
	return 0;
}