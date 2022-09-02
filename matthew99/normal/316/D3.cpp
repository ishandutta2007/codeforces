#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cctype>
#include <ctime>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int Mod = 1000000007;

const int maxn = 1000000;

int n, ans;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	int k[2] = {0};
	REP(i, 0, n) 
	{
		static int x;
		scanf("%d", &x), ++k[--x];
	}
	int a = 0, b = 1;
	REP(i, 0, k[0]) swap(a= (b + (LL)a * i) % Mod, b);
	ans = b;
	REP(i, 0, k[1]) ans = (LL)ans * (k[0] + i + 1) % Mod;
	printf("%d\n", ans);
	return 0;
}