#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 5000;

int n;
pair<int, int> a[maxn + 5];

void init()
{
	scanf("%d", &n);
	REP(i, 0, n) scanf("%d%d", &a[i].x, &a[i].y);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	init();
	sort(a, a + n);
	int cur = -oo;
	REP(i, 0, n)
		if (a[i].y >= cur) cur = a[i].y;
		else cur = a[i].x;
	printf("%d\n", cur);
	return 0;
}