#include <cstdio>
#include <algorithm>

using namespace std;

#define INF 100000005

int n, m, k;
int rmin[1005];
int ans;

int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i <= m; i++) rmin[i] = INF;
	for (int i = 0; i < n; i++) {
		int r, c; scanf("%d%d", &r, &c);
		rmin[r] = min(rmin[r], c);
	}
	for (int i = 0; i <= m; i++) {
		if (rmin[i] != INF) ans += rmin[i];
	}
	printf("%d\n", min(ans, k));
	return 0;
}