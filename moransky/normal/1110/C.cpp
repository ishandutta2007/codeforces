// Skyqwq
#include <iostream>
#include <cstdio>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef long long LL;

template <typename T> void chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void chkMin(T &x, T y) { if (y < x) x = y; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}
 
template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(-x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}
 
int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int b[30] = {0,1,1,5,1,21,1,85,73,341,89,1365,1,5461,4681,21845,1,87381,1,349525,299593,1398101,178481,5592405,1082401 };

int q, x;

int main() {
	read(q);
	while (q--) {
		read(x);
		int c = 0, p = 0;
		for (int i = 0; i < 25; i++) {
			if (x >> i & 1) {
				c++;
				p = i;
			}
		}
		if (p + 1 == c) {
			printf("%d\n", b[p]);
		} else {
			printf("%d\n", (1 << (p + 1)) - 1);
		}
	}
	return 0;
}