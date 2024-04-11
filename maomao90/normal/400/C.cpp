#include <cstdio>

using namespace std;

int n, m, x, y, z, p;
int r[100005], c[100005];

int main() {
	scanf("%d%d%d%d%d%d", &n, &m, &x, &y, &z, &p);
	x %= 4; y %= 2; z %= 4;
	for (int i = 0; i < p; i++) {
		scanf("%d%d", &r[i], &c[i]);
	}
	for (int k = 0; k < x; k++) {
		for (int i = 0; i < p; i++) {
			int nr = c[i], nc = n - r[i] + 1;
			r[i] = nr, c[i] = nc;
		}
		n = n ^ m;
		m = n ^ m;
		n = n ^ m;
	}
	for (int  k = 0; k < y; k++) {
		for (int i = 0; i < p; i++) {
			c[i] = m - c[i] + 1;
		}
	}
	for (int k = 4; k > z; k--) {
		for (int i = 0; i < p; i++) {
			int nr = c[i], nc = n - r[i] + 1;
			r[i] = nr, c[i] = nc;
		}
		n = n ^ m;
		m = n ^ m;
		n = n ^ m;
	}
	for (int i = 0; i < p; i++) printf("%d %d\n", r[i], c[i]);
	return 0;
}