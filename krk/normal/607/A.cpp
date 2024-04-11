#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;

int n;
ii p[Maxn];
int res[Maxn];
int best;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d %d", &p[i].first, &p[i].second);
	sort(p, p + n);
	for (int i = 0; i < n; i++) {
		int ind = lower_bound(p, p + n, ii(p[i].first - p[i].second, 0)) - p - 1;
		if (ind < 0) res[i] = 1;
		else res[i] = 1 + res[ind];
		best = max(best, res[i]);
	}
	printf("%d\n", n - best);
	return 0;
}