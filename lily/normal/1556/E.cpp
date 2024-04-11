#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int N = 1e5 + 5;
const int LOG = 20;


int n, Q;
int a[N], b[N], c[N];
LL sum[N];
LL ma[LOG][N];
LL mi[LOG][N];


LL getmi(int l, int r) {
	int L = __lg (r - l + 1);
	return min(mi[L][l], mi[L][r - (1 << L) + 1]);
}

LL getma(int l, int r) {
	int L = __lg (r - l + 1);
	return max(ma[L][l], ma[L][r - (1 << L) + 1]);
}

int main() {
	scanf("%d%d" , &n, &Q);
	for (int i = 1; i <= n; i++) scanf("%d", a + i);
	for (int i = 1; i <= n; i++) scanf("%d", b + i);
	for (int i = 1; i <= n; i++) c[i] = b[i] - a[i], sum[i] = sum[i - 1] + c[i]; 
	for (int i = 1; i <= n; i++) ma[0][i] = sum[i];
	for (int i = 1; i <= n; i++) mi[0][i] = sum[i];
	for (int i = 1; i < LOG; i++) {
		for (int j = 1, x = 1 << (i - 1); j + x <= n; j++) {
			ma[i][j] = max(ma[i - 1][j], ma[i - 1][j + x]);
		}
	}
	for (int i = 1; i < LOG; i++) {
		for (int j = 1, x = 1 << (i - 1); j + x <= n; j++) {
			mi[i][j] = min(mi[i - 1][j], mi[i - 1][j + x]);
		}
	}
	while (Q--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (sum[r] != sum[l - 1]) {
			puts("-1");
			continue;
		}
		LL start = sum[l - 1];
		LL ma = getma(l, r), mi = getmi(l, r);
		if (mi < start) puts("-1");
		else printf("%lld\n", ma - start);
	}

}