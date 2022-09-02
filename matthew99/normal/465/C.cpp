#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second

using namespace std;

typedef long long LL;

const int maxn = 1000;

int n, p;

char st[maxn + 5];
char tmp;

bool find(const int &x)
{
	if (x == -1) return 0;
	for (int i = 1; ; ++i)
	{
		if (st[x] + i >= tmp) break;
		if (x > 0 && st[x - 1] == st[x] + i) continue;
		if (x > 1 && st[x - 2] == st[x] + i) continue;
		st[x] += i;
		return 1;
	}
	if (!find(x - 1)) return 0;
	st[x] = 'a';
	for (int i = 0; ; ++i)
	{
		if (st[x] + i >= tmp) break;
		if (x > 0 && st[x - 1] == st[x] + i) continue;
		if (x > 1 && st[x - 2] == st[x] + i) continue;
		st[x] += i;
		return 1;
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &p);
	tmp = 'a' + p;
	scanf("%s", st);
	if (find(n - 1)) printf("%s\n", st);
	else printf("NO\n");
	return 0;
}