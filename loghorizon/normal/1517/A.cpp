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


LL n;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%lld", &n);
		if (n % 2050) puts("-1");
		else {
			n /= 2050;
			LL ans = 0;
			while (n) ans += n % 10, n /= 10;
			printf("%lld\n", ans);
		}
	}
	return 0;
}