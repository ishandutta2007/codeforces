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

const int maxn = 100000;

int n, m;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &m);
	int lst = -1, lsth = 0;
	int ret = 0;
	REP(i, 0, m)
	{
		static int d, h;
		scanf("%d%d", &d, &h);
		if (lst == -1) ret = max(ret, h + d - 1);
		else
		{
			int tmp = abs(d - lst) - abs(lsth - h);
			if (tmp < 0) EXIT("IMPOSSIBLE\n");
			ret = max(ret, max(lsth, h) + (tmp >> 1));
		}
		lst = d, lsth = h;
	}
	ret = max(ret, lsth + (n - lst));
	printf("%d\n", ret);
	return 0;
}