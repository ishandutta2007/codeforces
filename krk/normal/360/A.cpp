#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 5005;

int n, m;
int qa[Maxn], qb[Maxn], qc[Maxn], qd[Maxn];
int a[Maxn], b[Maxn];

bool Check()
{
	for (int i = 1; i <= n; i++) {
		a[i] = min(a[i], Inf);
		b[i] = a[i];
	}
	for (int i = 0; i < m; i++)
		if (qa[i] == 1)
			for (int j = qb[i]; j <= qc[i]; j++)
				b[j] += qd[i];
		else {
			int mx = -2 * Inf;
			for (int j = qb[i]; j <= qc[i]; j++)
				mx = max(mx, b[j]);
			if (mx != qd[i]) return false;
		}
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d %d %d %d", &qa[i], &qb[i], &qc[i], &qd[i]);
	for (int i = 1; i <= n; i++)
		a[i] = Inf;
	for (int i = m - 1; i >= 0; i--)
		if (qa[i] == 1)
			for (int j = qb[i]; j <= qc[i]; j++)
				a[j] -= qd[i];
		else for (int j = qb[i]; j <= qc[i]; j++)
				a[j] = min(a[j], qd[i]);
	if (Check()) {
		printf("YES\n");
		for (int i = 1; i <= n; i++)
			printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
	} else printf("NO\n");
	return 0;
}