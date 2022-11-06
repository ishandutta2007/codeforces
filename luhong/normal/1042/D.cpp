#include <cstdio>
#include <algorithm>

long long b[210000], a[201000], t;
int N;
long long c[210000];

void add(int x, int v) {for(int i = x; i <= N; i += i & -i) c[i] += v;}
long long query(int x) {long long ans = 0; for(int i = x; i; i -= i & -i) ans += c[i]; return ans;}

int main()
{
	int n;
	scanf("%d%lld", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%lld", &a[i]), a[i] += a[i - 1], b[i] = a[i];
	b[n + 1] = 0;
	std::sort(b + 1, b + n + 1 + 1); N = std::unique(b + 1, b + n + 1 + 1) - b - 1;
	long long ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int p = std::lower_bound(b + 1, b + N + 1, a[i - 1]) - b;
		add(p, 1); 
		int P = std::upper_bound(b + 1, b + N + 1, a[i] - t) - b - 1;
		ans += query(N) - query(P);
	}
	printf("%lld\n", ans);
	return 0;
}