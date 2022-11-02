#include <bits/stdc++.h>

using namespace std;

int n, A, R, M, a[100001];

long long calc(int x) {
	long long P = 0, Q = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] <= x)
			P += x - a[i];
		else
			Q += a[i] - x;
	if (P <= Q)
		return 1LL * P * M + 1LL * (Q - P) * R;
	else
		return 1LL * Q * M + 1LL * (P - Q) * A;
}

int main() {
	scanf("%d%d%d%d", &n, &A, &R, &M);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	M = min(M, A + R);
	int L = 0, R = 1e9;
	while (L + 2 < R) {
		int M1 = (R - L) / 3 + L;
		int M2 = (R - L) / 3 * 2 + L;
		if (calc(M1) > calc(M2))
			L = M1;
		else
			R = M2;
	}
	long long ans = calc(L);
	for (int i = L + 1; i <= R; i++)
		ans = min(ans, calc(i));
	printf("%lld\n", ans);
}