#include <cstdio>
using namespace std;

const int Maxn = 100005;

int ind[Maxn], cnt[Maxn];
int b[Maxn];
int n, m;
int res[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		int f; scanf("%d", &f);
		ind[f] = i; cnt[f]++;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &b[i]);
		if (cnt[b[i]] == 0) { printf("Impossible\n"); return 0; }
	}
	for (int i = 1; i <= m; i++) {
		if (cnt[b[i]] > 1) { printf("Ambiguity\n"); return 0; }
		res[i] = ind[b[i]];
	}
	printf("Possible\n");
	for (int i = 1; i <= m; i++)
		printf("%d%c", res[i], i + 1 <= m? ' ': '\n');
	return 0;
}