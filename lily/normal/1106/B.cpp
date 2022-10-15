#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(a, b) make_pair(a, b)
#define x first
#define y second

#define N 1234567

int n, m;
int a[N];
pii b[N];
int c[N], C[N];
int Fuck;

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", C + i);
	for (int i = 1; i <= n; i++) b[i] = {C[i], i};
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++) c[b[i].y] = i;
	int p = 1;
	for (int i = 1; i <= m; i++) {
		int k, d;
		scanf("%d%d", &k, &d);
		LL ans = 0;
		while (d) {
			if (a[k] > 0) {
				int take = min(a[k], d);
				d -= take;
				a[k] -= take;
				ans += take * LL(C[k]);
			}
			else {
				while (p <= n && a[b[p].y] == 0) p++; 
				if (p > n) break;
				int pp = b[p].y;
				int take = min(a[pp], d);
				d -= take;
				a[pp] -= take;
				ans += take * LL(C[pp]);
			}
		}
		if (d) ans = 0;
		printf("%lld\n", ans);
	}



	return 0;
}