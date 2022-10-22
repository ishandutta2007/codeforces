#include <cstdio>
#include <algorithm>
using namespace std;

int n, m, x, y, z, p;

int main()
{
	scanf("%d %d %d %d %d %d", &n, &m, &x, &y, &z, &p);
	x %= 4; y %= 2; z = z % 4 * 3 % 4;
	while (p--) {
		int r, c; scanf("%d %d", &r, &c);
		int N = n, M = m;
		for (int i = 0; i < x; i++) {
			swap(r, c); c = N - c + 1;
			swap(N, M);
		}
		if (y) c = M - c + 1;
		for (int i = 0; i < z; i++) {
			swap(r, c); c = N - c + 1;
			swap(N, M);
		}
		printf("%d %d\n", r, c);
	}
	return 0;
}