// Skyqwq
#include <iostream>
#include <cstdio>

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

const int N = 3e5 + 5;

int n, k, a[N], b[N];

char s[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &k, s + 1);
		for (int i = 0; i < k; i++) a[i] = -1;
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			if (s[i] != '?') {
				int t = i % k, b = s[i] - '0';
				if (~a[t] && a[t] != b) {
					ok = false;
				}
				a[t] = b;
			}
		}
		for (int i = 1; i <= n; i++) b[i] = a[i % k];
		int c0 = 0, c1 = 0;
		for (int i = 1; i <= k; i++) {
			if (b[i] == 0) c0++;
			else if (b[i] == 1) c1++;
		}
		if (c1 > k / 2 || c0 > k / 2) ok = false;
		puts(ok ? "YES" : "NO");
	}
	return 0;
}