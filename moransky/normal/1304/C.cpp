#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
const int N = 105;
int n, m, T[N], L[N], R[N];
int main() {
	int Case; scanf("%d", &Case);
	while (Case--) {
		scanf("%d%d", &n, &m);
		bool ok = true;
		LL x = m, y = m;
		for (int i = 1; i <= n; i++) 
			scanf("%d%d%d", T + i, L + i, R + i);
		for (int i = 1; i <= n; i++) {
			int t = T[i] - T[i - 1], l = L[i], r = R[i];
			if (y + t < l) { ok = false; break; }
			if (x - t > r) { ok = false; break; }
			x = max(x - t, (LL)l);
			y = min(y + t, (LL)r);
		}

		puts(ok ? "YES" : "NO");
	}
	return 0;
}