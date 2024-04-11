#include<cstdio>
int m, n;
bool good[33];
void output(int x) {
	printf("%d\n", x);fflush(stdout);
}
int main() {
	scanf("%d%d", &m, &n);
	for (int i = 0; i < n; i++) {
		output(1);
		int x;
		scanf("%d", &x);
		if (x == 0) {
			return 0;
		}
		if (x == 1)
			good[i] = true;
		else
			good[i] = false;
	}
	int lo = 2, hi = m;
	for (int step = 0; lo != hi; step ++) {
		int mi = (lo + hi) / 2;
		output(mi);
		int x;
		scanf("%d", &x);
		if (x == 0) {
			return 0;
		}
		if ((x == 1) == good[step%n])
			lo = mi + 1;
		else
			hi = mi - 1;
	}
	output(lo);
	return 0;
}