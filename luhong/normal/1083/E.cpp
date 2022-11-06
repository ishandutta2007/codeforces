#include <cstdio>
#include <algorithm>
#define MN 1010000

long long dp[MN], ans = 0;
int q[MN], h = 1, t = 0;
struct xxx{
	int x, y; long long a;
}p[MN];

long long calc(int j, int i) {return dp[j] + 1ll * (p[i].x - p[j].x) * p[i].y - p[i].a;}

double slope(int j, int k) {return 1.0 * (dp[j] - dp[k]) / (p[j].x - p[k].x);}

bool cmp(xxx a, xxx b) {return a.x < b.x;}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d%d%lld", &p[i].x, &p[i].y, &p[i].a);
	std::sort(p + 1, p + n + 1, cmp);
	q[++t] = 0;
	for(int i = 1; i <= n; i++)
	{
		while(h < t && calc(q[h], i) < calc(q[h + 1], i)) h++;
		dp[i] = calc(q[h], i);
		while(h < t && slope(q[t - 1], q[t]) < slope(q[t], i)) t--;
		q[++t] = i;
		ans = std::max(ans, dp[i]);
	}
	printf("%lld\n", ans);
	return 0;
}