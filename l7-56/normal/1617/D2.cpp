#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn = 10010;
int a[maxn],n,T,res[maxn];

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
		for (int i = 1; i <= n; i += 3) res[i] = ask(i, i + 1, i + 2);
		int x = -1, y = -1;
		for (int i = 4; i <= n; i += 3)
			if (res[i] != res[i - 3]) {
				int t1 = ask(i - 2, i - 1, i), t2 = ask(i - 1, i, i + 1);
				if (t1 != res[i - 3]) {
					a[i - 3] = res[i - 3];
					a[i] = t1;
					x = i;
					y = i - 3;
				}
				else if (t1 != t2) {
					a[i - 2] = t1;
					a[i + 1] = t2;
					x = i - 2;
					y = i + 1;
				}
				else {
					a[i - 1] = t2;
					a[i + 2] = res[i];
					x = i - 1;
					y = i + 2;
				}
				if (a[x] == 1) swap(x, y);
				for (int j = i - 3; j <= i + 2; ++j)
					if (j != x && j != y) a[j] = ask(x, y, j);
				break;
			}
		for (int i = 1; i <= n; i += 3) {
			if (a[i] != -1) continue;
			if (res[i] == 0) {
				int t = ask(y, i, i + 1);
				if (t == 0) a[i] = a[i + 1] = 0, a[i + 2] = ask(x, y, i + 2);
				else a[i + 2] = 0, a[i] = ask(x, y, i), a[i + 1] = !a[i];
			}
			else {
				int t = ask(x, i, i + 1);
				if (t == 0) a[i + 2] = 1, a[i] = ask(x, y, i), a[i + 1] = !a[i];
				else a[i] = a[i + 1] = 1, a[i + 2] = ask(x, y, i + 2);
			}
		}
		int k = 0;
		for (int i = 1; i <= n; ++i) k += (a[i] == 0);
		printf("! %d", k);
		for (int i = 1; i <= n; ++i)
			if (a[i] == 0) printf(" %d", i);
		printf("\n");
		fflush(stdout);
	}
	return 0;
}