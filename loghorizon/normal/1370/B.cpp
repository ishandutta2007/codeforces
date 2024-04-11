#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 2005;

int n, a[N], d1[N], d2[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int c1 = 0, c2 = 0;
		for (int i = 1; i <= 2 * n; i++) { 
			scanf("%d", &a[i]);
			if (a[i] & 1) d1[++c1] = i;
			else d2[++c2] = i;
		}

		int p = n - 1;
		for (int i = 1; i <= c1; i += 2) {
			if (i + 1 > c1) break;
			if (p == 0) break;
			printf("%d %d\n", d1[i], d1[i + 1]);
			p--;
			
		}
		for (int i = 1; i <= c2; i += 2) {
			if (i + 1 > c2) break;
			if (p == 0) break;
			printf("%d %d\n", d2[i], d2[i + 1]);
			p--;
			
		}
	}
	return 0;
}