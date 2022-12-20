#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int ask(int a, int b) {
	printf("? %d %d\n", a, b);
	fflush(stdout);
	int x; scanf("%d", &x);
	return x;
}

void work() {
	int x = 0;
	for (int bit = 0; bit < 29; ++bit) {
		int a = (1 << (bit + 1)) - x;
		if (ask(a, (1 << (bit + 1)) + a) != (1 << (bit + 1))) x |= (1 << bit);
	}
	if (!x) x = (1 << 29);
	else if (x != (x & (-x))) {
		if (ask(x, 2 * x) != x) x |= (1 << 29);
	}
	else {
		int a = (x | (1 << 29)) / (x & (-x));
		if (ask(a, 2 * a) == a) x |= (1 << 29);
	}
	printf("! %d\n", x);
	fflush(stdout);
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}