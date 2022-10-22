#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1000005;

int n, m;
int deg[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	while (m--) {
		int a, b; scanf("%d %d", &a, &b);
		deg[a]++; deg[b]++;
	}
	for (int i = 1; i <= n; i++) {
		int a = deg[i], b = n - 1 - deg[i];
		res += ll(a) * ll(a - 1) - ll(a) * ll(b) + ll(b) * ll(b - 1);
	}
	printf("%I64d\n", res / 6ll);
	return 0;
}