// Skyqwq
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 1e6 + 5, P = 998244353;

int n, f[N];

int main() {
	read(n);
	for (int t = 1; t <= n; t++) {
		for (int i = t * 2; i <= n; i += t) {
			f[i]++;
		}
	}
	f[0] = 1;
	int s = 1;
	for (int i = 1; i <= n; i++) {
		(f[i] += s) %= P;
		(s += f[i]) %= P;
	}
	printf("%d\n", f[n]);
	return 0;
}