#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 500005, P = 998244353;

int n, K, m, ans = 1;
int cnt[N], pre[N], f[N];
int L[N], R[N], X[N];

int inline solve(int w) {
	memset(f, 0, sizeof f);
	memset(cnt, 0, sizeof cnt);
	memset(pre, 0, sizeof pre);
	for (int i = 1; i <= m; i++) {
		if (X[i] >> w & 1) cnt[L[i]]++, cnt[R[i] + 1]--;
		else pre[R[i]] = max(pre[R[i]], L[i]);
	}
	for (int i = 1; i <= n; i++) cnt[i] += cnt[i - 1];
	f[0] = 1;
	int s = 1, j = 0;
	for (int i = 1; i <= n; i++) {
		if (!cnt[i]) f[i] = s;
		(s += f[i]) %= P;
		while (j < pre[i]) s = ((LL)s - f[j++] + P) % P;
	}
	int res = 0;
	for (int i = j; i <= n; i++) (res += f[i]) %= P;
	return res;
}

int main() { 
	scanf("%d%d%d", &n, &K, &m);
	for (int i = 1; i <= m; i++) scanf("%d%d%d", L + i, R + i, X + i);
	for (int k = 0; k < K; k++) ans = (LL)ans * solve(k) % P;
	printf("%d\n", ans); 
}