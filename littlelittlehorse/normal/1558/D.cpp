#include <bits/stdc++.h>

using namespace std;

const int P = 998244353;
int f[200001], test, n, m, a[200001][2], c[400001];
long long u[400001], d[400001];

inline void add(int x, int y) {
	for ( ; x <= 200000; x += x & (-x))
		f[x] += y;
}

int calc(int x) {
	int ans = 0;
	for (; x; x -= x & (-x))
		ans += f[x];
	return ans;
}

int rp(long long now, int k) {
	long long cnt = 1;
	for (; k; k >>= 1, now *= now, now %= P)
		if (k & 1)
			cnt *= now, cnt %= P;
	return cnt;
}

int C(int n, int m) {
	return 1LL * u[n] * d[m] % P * d[n - m] % P;
}

int main() {
	u[0] = d[0] = 1;
	for (int i = 1; i <= 400000; i++)
		u[i] = u[i - 1] * i % P,
		       d[i] = rp(u[i], P - 2);
	scanf("%d", &test);
	for (int i = 1; i <= 200000; i++)
		f[i] = 0;
	for (int i = 1; i <= 200000; i++)
		add(i, 1);
	for (; test--; ) {
		scanf("%d%d", &n, &m);
		int N = n;
		for (int i = 1; i <= m; i++)
			scanf("%d%d", &a[i][0], &a[i][1]);
		int cnt = 0, l = n + 1;
		int wo = 0;
		for (int i = m; i; --i) {
			int z = l - a[i][0] - 1;
			int sum = 0, cur = 0;
			for (int j = 20; j >= 0; --j)
				if (cur + (1 << j) <= n && sum + f[cur + (1 << j)] < l - 1 - z)
					cur += 1 << j, sum += f[cur];
			++cur;
			n = cur;
			if (l != a[i][0] + 1 && cur != n) {
				++cur;
				if (calc(cur) - calc(cur - 1) == 1)
					add(cur, -1), c[++wo] = cur;
			}

			sum = 0;
			cur = 0;
			for (int j = 20; j >= 0; --j)
				if (cur + (1 << j) <= n && sum + f[cur + (1 << j)] < a[i][1])
					cur += 1 << j, sum += f[cur];
			++cur;
			if (cur != n && calc(cur + 1) - calc(cur) == 1)
				++cnt;
			add(cur, -1);
			c[++wo] = cur;
			l = a[i][0];
			//printf("%d\n", cnt);
		}
		cnt = N - 1 - cnt;
		printf("%d\n", C(N + cnt, cnt));
		for (int i = 1; i <= wo; i++)
			add(c[i], 1);
	}
}