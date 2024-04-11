#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long LL;

// char buf[1<<23], *p1=buf, *p2=buf, obuf[1<<23], *O=obuf;
// #define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1<<21, stdin), p1 == p2) ? EOF : *p1++)

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

const int N = 105;

int n, a[N], x;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n); read(x);
		int s = 0;
		for (int i = 1; i <= n; i++) read(a[i]), s += a[i];
		if (s == x) puts("NO");
		else {
			s = 0;
			puts("YES");
			for (int i = 1; i <= n; i++) {
				if (s + a[i] == x) {
					swap(a[i], a[i + 1]);
				}
				s += a[i];
				printf("%d ", a[i]);
			}
			puts("");
		}

	}
	return 0;
}