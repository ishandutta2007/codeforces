// Skyqwq
#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

typedef long long LL;

typedef long long LL;

typedef pair<int, int> PII;


void inline read(int &x) {
    x = 0; char s = getchar();
    while (s < '0' || s > '9') s = getchar();
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
}

void print(int x) {
    if (x >= 10) print(x / 10);
    putchar((x % 10) + '0');
}

const int N = 5e6 + 5;

int n, a[N], cnt[N], X[N], Y[N], pos[N], b[N], tot;

PII e[N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", a + i), cnt[a[i]]++;
	int s = 0, x = 0, y;
	for (int i = 1; i <= 2500000; i++) {
		if (cnt[i] >= 4) {
			puts("YES");
			int t = 0;
			for (int j = 1; j <= n; j++) {
				if (a[j] == i) {
					printf("%d ", j);
					t++;
					if (t == 4) return 0;
				}
			}
		}
		if (cnt[i] >= 2) {
			s++;
			if (!x) x = i;
			else y = i;
		}
	}
	if (s > 1) {
		int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
		for (int i = 1; i <= n; i++) {
			if (a[i] == x) {
				if (!c1) c1 = i;
				else c2 = i;
			}
			if (a[i] == y) {
				if (!c3) c3 = i;
				else c4 = i;
			}
		}
	 	puts("YES");
	 	printf("%d %d %d %d\n", c1, c3, c2, c4);
	 	return 0;
	 }
	for (int i = 1; i <= n; i++) pos[a[i]] = i;
	int last = -1;
	for (int i = 1; i <= 2500000; i++) {
		if (pos[i]) {
			if (last != -1) {
				if (X[i - last]) {
					if (Y[i - last] != last) {
						puts("YES");
						printf("%d %d %d %d\n", pos[X[i - last]], pos[i], pos[Y[i - last]], pos[last]);
						return 0;
					}
				} else X[i - last] = last, Y[i - last] = i;
			}
			last = i;
		}
	}
	int c0 = 0, c1 = 0;
	for (int i = 1; i <= n; i++) {
		if (pos[a[i]] == i) b[++tot] = i;
		if (a[i] == x) {
			if (!c0) c0 = i;
			else c1 = i;
		}
	}
	e[2 * x] = make_pair(c0, c1);
	for (int A = 1; A <= tot; A++) {
		int i = b[A];
		for (int B = A + 1; B <= tot; B++) {
			int j = b[B];
			int t = a[i] + a[j];
			if (e[t].first) {puts("YES");
				printf("%d %d %d %d\n", e[t].first, e[t].second, i, j);
				return 0;
			}
			e[t] = make_pair(i, j);
		}
	}
	puts("NO");
	return 0;
}