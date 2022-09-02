#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int Mod = 1e9 + 7;

int a, b;

int ans = 0;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &a, &b);
	for (int i = 1; i < b; ++i)
	{
		int t = a;
		ans = (ans + ((LL)t * (t + 1) >> 1) % Mod * i % Mod * b + (LL)t * i) % Mod;
	}
	printf("%d\n", ans);
	return 0;
}