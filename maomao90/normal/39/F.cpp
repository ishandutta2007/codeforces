#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 1000000005

int n, m, k;
int d[105], mos[105];
int cnt[105];
int anscnt, minans = INF;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < m; i++) scanf("%d", &d[i]);
	for (int i = 0; i < k; i++) scanf("%d", &mos[i]);
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < m; j++) {
			if (mos[i] % d[j] == 0) cnt[j]++;
		}
	}
	for (int i = 0; i < m; i++) minans = min(minans, cnt[i]);
	for (int i = 0; i < m; i++) if (cnt[i] == minans) anscnt++;
	printf("%d\n", anscnt);
	for (int i = 0; i < m; i++) if (cnt[i] == minans) printf("%d ", i + 1);
	printf("\n");
	return 0;
}