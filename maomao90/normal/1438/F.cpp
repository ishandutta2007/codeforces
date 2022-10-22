#include <bits/stdc++.h>
using namespace std;

int n, h;
int cnt[3000005];

int main() {
	srand(time(0));
	scanf("%d", &h);
	n = (1 << h) - 1;
	for (int i = 0; i < 420; i++) {
		int a, b, c;
		do {
			a = rand() % n + 1, b = rand() % n + 1, c = rand() % n + 1;
		} while (a == b || b == c || a == c);
		printf("? %d %d %d\n", a, b, c);
		fflush(stdout);
		int x; scanf("%d", &x);
		cnt[x]++;
	}
	int fmax = 0, a = -1, smax = 0, b = -1;
	for (int i = 1; i <= n; i++) {
		if (cnt[i] > fmax) {
			smax = fmax;
			b = a;
			fmax = cnt[i];
			a = i;
		} else if (cnt[i] > smax) {
			smax = cnt[i];
			b = i;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (i == a || i == b) continue;
		printf("? %d %d %d\n", a, b, i);
		fflush(stdout);
		int x; scanf("%d", &x);
		if (x == i) {
			printf("! %d\n", x);
			fflush(stdout);
			return 0;
		}
	}
	return 0;
}