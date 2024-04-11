#include <bits/stdc++.h>
using namespace std;

typedef tuple <int, int, int> iii;
typedef long long ll;

#define INF 100000000000000000

int n, k;
iii lra[2005];
ll dp[2005];
ll ans;

int main() {
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; i++) {
		int l, r, a; scanf("%d%d%d", &l, &r, &a);
		lra[i] = iii(l, r, a);
	}
	sort(lra, lra + n);
	for (int i = 0; i < n; i++) dp[i] = INF;
	dp[0] = 0;
	ans = INF;
	for (int i = 0; i < n; i++) {
		int li, ri, ai; tie(li, ri, ai) = lra[i];
		ll suma = dp[i], rem = k;
		bool pos = true;
		for (int j = i; j < n; j++) {
			int lj, rj, aj; tie(lj, rj, aj) = lra[j];
			int reloads = (max(0ll, aj - rem) + k - 1) / k;
			if (reloads > rj - lj) break;
			suma += aj;
			rem = reloads * k + rem - aj;
			if (j + 1 == n) {
				ans = min(ans, suma);
			} else if (lj + reloads < get<0>(lra[j + 1])) {
				dp[j + 1] = min(dp[j + 1], suma + rem);
			}
		}
	}
	if (ans == INF) printf("-1\n");
	else printf("%lld\n", ans);
	return 0;
}