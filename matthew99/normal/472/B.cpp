#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 2000;

int n, k;

int a[maxn + 5], h[maxn + 5] = {0};

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	REP(i, 0, n) scanf("%d", a + i), h[i] = 1;
	sort(a, a + n);
	int cur = n - 1;
	int ans = 0;
	for ( ; ; )
	{
		int tmp = 0;
		while (tmp < k && cur >= 0 && h[cur] != a[cur])
			++tmp, ++h[cur--];
		if (tmp == 0) break;
		++ans;
		if (cur < 0 || h[cur] == a[cur]) cur = n - 1;
		else ++ans;
	}
	ans += a[n - 1] - 1;
	printf("%d\n", ans);
	return 0;
}