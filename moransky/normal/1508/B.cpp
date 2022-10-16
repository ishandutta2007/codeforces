// Skyqwq
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e5 + 5;

int n, ans[N], tot;

bool st[N];

LL K;


int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%lld", &n, &K); 
		if (n == 1 && K > 1) {
			puts("-1"); continue;
		}
		if (pow(2, n - 1) < K) {
			puts("-1"); continue;
		}
		tot = 0;
		for (int i = 1; i <= n; i++) st[i] = false;
		bool ok = true;
		int j = 1;
		while (j < n && pow(2, n - j - 1) >= K) {
			st[j] = 1;
			ans[++tot] = j++;
		}
		int last = ans[tot];
		for (int i = j; i <= n; i++) {
			for (int k = j; k <= n; k++) {
				if (!st[k] && last - 1 <= k) {
					st[k] = 1;
					if (i == n) {
						ans[++tot] = k;
						break;
					}
					bool f = 1;
					int s = 0;
					long double t = 1;
					for (int u = k; u <= n; u++) {
						if (!st[u]) s++;
						else {
							if (s) t *= pow(2, s - 1);
							s = 0;

						}
					}
					if (s) t *= pow(2, s - 1);
					if (K <= t) {
						ans[++tot] = k;
						last = k;
						break;
					} else {
						K -= t;
						st[k] = 0;
					}
				}
			}
		}
		if (false) puts("-1");
		else {
			for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
			puts("");
		}
	}
	return 0;
}