#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i != _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

int n, k;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &k);
	int cnt = 0;
	for (int i = 1; ;  ++i)
	{
		printf("%d ", i), ++cnt;
		if (cnt == k + 1) break;
		printf("%d ", k + 2 - i), ++cnt;
		if (cnt == k + 1) break;
	}
	for (int i = k + 2; i <= n; ++i) printf("%d ", i);
	return 0;
}