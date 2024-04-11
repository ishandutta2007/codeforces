#include <iostream>
#include <cstdio>
#include <cstring>
#define pb push_back
#define mp make_pair
#define fi first
#define se second

typedef long long LL;

using namespace std;

template <typename T> void inline chkMax(T &x, T y) { if (y > x) x = y; }
template <typename T> void inline chkMin(T &x, T y) { if (y < x) x = y; }


template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

template <typename T> void print(T x) {
	if (x < 0) { putchar('-'); print(x); return ; }
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 2e5 + 5;

int n, t;

char s[N], g[N];

bool inline check() {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		if (g[i] == '(') {
			s++;
		} else {
			if (!s) return 0;
			s--;
		}
	}
	return 1;
}

int main() {
	scanf("%d%s", &n, s + 1);
	if (n & 1) { puts("No"); return 0; }
	int c = 0, p = -1, q = -1;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '(') {
			c++;
			p = i;
		} else {
			if (q == -1) q = i;
		}
	}
	if (c != n / 2) {
		puts("No"); return 0;
	}
	t = 1;
	g[1] = '(';
	for (int i = 1; i <= n; i++) 
		if (i != p) g[++t] = s[i];
	if (check()) {
		puts("Yes");
		return 0;
	}
	t = 0;
	for (int i = 1; i <= n; i++) 
		if (i != q) g[++t] = s[i];
	g[++t] = ')';
	if (check()) {
		puts("Yes");
		return 0;
	}
	puts("No");
}