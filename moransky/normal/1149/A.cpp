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

const int N = 2e5 + 5;

int n, a[N];

int main() {
	read(n);
	int c1 = 0, c2 = 0;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] == 1) c1++;
		else c2++;
	}
	if (c2) {
		c2--;
		printf("2 ");
	}
	int n1 = c1;
	if (n1 && n1 % 2 == 0) n1--;
	for (int i = 1; i <= n1; i++) printf("1 ");
	for (int i = 1; i <= c2; i++) printf("2 ");
	if (n1 != c1) printf("1");
	return 0;
}