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

char s[20];

void inline clear() {
	fflush(stdout);
}

int inline get() {
	int x; 
	scanf("%d", &x);
	for (int i = 1; i <= x; i++) scanf("%s", s);
	return x;
}

int main() {
	while (1) {
		puts("next 0"); clear();
		get();
		puts("next 0 1"); clear();
		if (get() == 2) break;
	}
	while (1) {
		puts("next 0 1 2 3 4 5 6 7 8 9"); clear();
		if (get() == 1) break;
	}
	puts("done");
	clear();
	return 0;
}