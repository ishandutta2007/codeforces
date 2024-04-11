#include <iostream>
#include <cstdio>
#include <cstring>
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

const int N = 105;

int n;



int main() {
	int T; scanf("%d", &T);
	while (T--) {
		read(n);
		bool o = 0;
		if (n % 2 == 0) {
			LL k = n / 2;
			LL t = sqrt(k);
			if (t * t == k) o = 1;
		}
		if (n % 4 == 0) {
			LL k = n / 4;
			LL t = sqrt(k);
			if (t * t == k) o = 1;
		}
		puts(o ? "YES" : "NO");
	}
	return 0;
}