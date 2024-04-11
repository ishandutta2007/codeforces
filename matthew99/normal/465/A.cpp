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

const int oo = 0x3f3f3f3f;

const int maxn = 100;

int n;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d\n", &n);
	int ans = 0;
	REP(i, 0, n)
	{
		static char x;
		scanf("%c", &x);
		if (x == '0') break;
		++ans;
	}
	if (ans < n) ++ans;
	printf("%d\n", ans);
	return 0;
}