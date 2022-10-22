#include <cstdio>
using namespace std;

const int Maxn = 305;

int n, m, k;
bool marked[Maxn];
int a, b;

void Phase1()
{
	for (int i = 1; i <= n; i++) if (i != a && i != b) {
		printf("%d %d\n", a, i); m--;
	}
	for (int i = 1; i <= n && m; i++) if (!marked[i]) {
		printf("%d %d\n", b, i); m--;
	}
}

void Phase2()
{
	for (int i = 1; i <= n && m; i++) if (i != a && i != b)
		for (int j = i + 1; j <= n && m; j++) if (j != a && j != b) {
			printf("%d %d\n", i, j); m--;
		}
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	if (k == n || m < n - 1 || m > (n - 1) * (n - 2) / 2 + n - k) { printf("-1\n"); return 0; }
	while (k--) {
		int v; scanf("%d", &v);
		marked[v] = true;
	}
	a = 1; while (!marked[a]) a++;
	b = a + 1; while (!marked[b]) b++;
	Phase1(); Phase2();
	return 0;
}