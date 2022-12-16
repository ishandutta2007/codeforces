#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 1e4 + 10;
int T,n,a[maxn];

int ask(int a, int b, int c) {
	printf("? %d %d %d\n", a, b, c);
	fflush(stdout);
	int x; scanf("%d", &x);
	if (x == -1) exit(0);
	return x;
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) a[i] = -1;
		int lst = ask(1, 2, 3), x = -1, y = -1;
		for (int i = 2; i <= n; ++i) {
			int nw = ask(i, i + 1, i + 2);
			if (lst != nw) {
				a[i - 1] = lst, a[i + 2] = nw, x = i - 1, y = i + 2;
				break;
			}
		}
		int k = 1;
		for (int i = 1; i <= n; ++i)
			if (a[i] == -1) a[i] = ask(x, y, i), k += (a[i] == 0);
		printf("! %d ", k);
		for (int i = 1; i <= n; ++i)
			if (a[i] == 0) printf("%d ", i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}