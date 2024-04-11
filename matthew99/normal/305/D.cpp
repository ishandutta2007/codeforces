#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define FOR(i, a, b) for (int i = (a), _end_ = (b); i <= _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define EXIT(...) printf(__VA_ARGS__), exit(0)

using namespace std;

typedef long long LL;

const int Mod = 1000000007;

const int oo = 0x3f3f3f3f;

const int maxn = 1e6;

int sum[maxn + 5];

int ans = 1;

int pm[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	pm[0] = 1;
	REP(i, 0, n) pm[i + 1] = (pm[i] << 1) % Mod;
	int first = n, last = 0;
	REP(i, 0, n - k - 1) sum[i] = 1;
	REP(i, 0, m)
	{
		static int u, v;
		scanf("%d%d", &u, &v), --u, --v;
		if (v - u == k + 1) 
		{
			sum[u] = 0;
			if (first == n) first = u;
			last = u;
		}
		else if (v - u != 1) EXIT("0\n");
	}
	if (first + k + 1 <= last) EXIT("0\n");
	REP(i, 1, n) 
	{
		sum[i] += sum[i - 1];
		if (sum[i] >= Mod) sum[i] -= Mod;
	}
	if (first != n) --ans;
	REP(i, max(0, last - k), min(n - k - 1, first + 1))
	{
		ans += pm[sum[i + k] - sum[i]];
		if (ans >= Mod) ans -= Mod;
	}
	printf("%d\n", ans);
	return 0;
}