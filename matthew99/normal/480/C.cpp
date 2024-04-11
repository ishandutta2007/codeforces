#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <set>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define x first
#define y second
#define mp make_pair

using namespace std;

const int oo = 0x3f3f3f3f;

const int maxn = 5000;

const int Mod = 1e9 + 7;

int n, a, b, k;

int cur[maxn + 5];
int sum[maxn + 5];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d%d%d", &n, &a, &b, &k);
	if (a > b) a = n - a, b = n - b;
	else --a, --b;
	memset(cur, 0, sizeof cur);
	cur[a] = 1;
	REP(i, 0, k)
	{
		memset(sum, 0, sizeof sum);
		REP(i, 0, b)
		{
			int l = b - i;
			(sum[max(0, i - l + 1)] += cur[i]) %= Mod;
			(sum[i] -= cur[i]) %= Mod;
			(sum[i + 1] += cur[i]) %= Mod;
			(sum[i + l] -= cur[i]) %= Mod;
		}
		cur[0] = sum[0];
		REP(i, 1, b)
			(cur[i] = cur[i - 1] + sum[i]) %= Mod;
	}
	int t = 0;
	REP(i, 0, b)
		(t += cur[i]) %= Mod;
	(t += Mod) %= Mod;
	printf("%d\n", t);
	return 0;
}