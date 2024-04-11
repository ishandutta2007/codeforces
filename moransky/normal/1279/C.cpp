#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;
const int N = 100005;
typedef long long LL;
int n, m, a[N], b[N], c[N], S;
void inline add(int x, int k) {
	for (; x <= n; x += x & -x) c[x] += k;
}
int inline ask(int x) {
	int res = 0;
	for (; x; x -= x & -x) res += c[x];
	return res;
}
int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		S = log2(n);
		for (int i = 1; i <= n; i++) c[i] = 0;
		for (int i = 1; i <= n; i++) add(i, 1);
		for (int i = 1, x; i <= n; i++) {
			scanf("%d", &x); a[x] = i;
		}
		for (int i = 1; i <= m; i++) scanf("%d", b + i);
		int L = 0;
		LL ans = 0;
		
		
		
		for (int i = 1; i <= m; i++) {
		    int k = b[i];
			if(a[k] > L) {
				ans += ask(a[k] - 1) * 2 + 1;
				add(a[k], -1);
				L = max(L, a[k]);
			} else {
				int x = 0;
				for (int j = S; j >= 0; j--) {
					if(x + (1 << j) < n && c[x + (1 << j)] == 0) x += (1 << j);
				}
				add(x + 1, -1);
				ans++;
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
	
}