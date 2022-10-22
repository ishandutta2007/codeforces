#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const ll Inf = 1000000000000000000ll;
const int Maxn = 5005;

int n, s, e;
int x[Maxn];
int A[Maxn], B[Maxn], C[Maxn], D[Maxn];
ll dp[2][Maxn];
int cur;
ll res;

ll Solve(int s1, int s2, int e1, int e2, ll add)
{
	fill((ll*)dp, (ll*)dp + 2 * Maxn, Inf); dp[cur][1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i + 1; j++) if (dp[cur][j] != Inf) {
			int a = j - 1;
			if (s < i) a += s1;
			if (e < i) a += e1;
			int b = j - 1;
			if (s < i) b += s2;
			if (e < i) b += e2;
			if (i > 0 && a == 0 && b == 0) { dp[cur][j] = Inf; continue; }
			if (i == s) {
				if (a + s1 >= 0 && b + s2 >= 0)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j]);
			} else if (i == e) {
				if (a + e1 >= 0 && b + e2 >= 0)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j]);
			} else {
				if (a - 1 >= 0 && b - 1 >= 0)
					dp[!cur][j - 1] = min(dp[!cur][j - 1], dp[cur][j] + ll(A[i]) + ll(C[i]));
				if (a - 1 >= 0)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + ll(A[i]) + ll(D[i]));
				if (b - 1 >= 0)
					dp[!cur][j] = min(dp[!cur][j], dp[cur][j] + ll(B[i]) + ll(C[i]));
				dp[!cur][j + 1] = min(dp[!cur][j + 1], dp[cur][j] + ll(B[i]) + ll(D[i]));
			}
			dp[cur][j] = Inf;
		}
		cur = !cur;
	}
	ll best = Inf;
	for (int j = 0; j <= n; j++) {
		int a = j - 1 + s1 + e1;
		int b = j - 1 + s2 + e2;
		if (a == 0 && b == 0) best = min(best, dp[cur][j]);
	}
	return best + add;
}

int main()
{
	scanf("%d %d %d", &n, &s, &e); s--; e--;
	for (int i = 0; i < n; i++)
		scanf("%d", &x[i]);
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]); A[i] += x[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &B[i]); B[i] -= x[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &C[i]); C[i] += x[i];
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &D[i]); D[i] -= x[i];
	}
	res = Inf;
	res = min(res, Solve(0, -1, -1, 0, ll(C[s]) + ll(A[e])));
	res = min(res, Solve(0, -1, 0, 1, ll(C[s]) + ll(B[e])));
	res = min(res, Solve(1, 0, -1, 0, ll(D[s]) + ll(A[e])));
	res = min(res, Solve(1, 0, 0, 1, ll(D[s]) + ll(B[e])));
	printf("%I64d\n", res);
	return 0;
}