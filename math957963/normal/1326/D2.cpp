#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<functional>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
using namespace std;
#define MOD 1000000007
#define f(i,n) for(int i=0;i<int(n);i++)
#define N 2000020
char a[N + 1];
int b[N + 1];

void z_alg(void) {
	int n, j;
	n = strlen(a);
	b[0] = n;
	int i = 1;
	int k = 0;
	while (i < n) {
		while ((i + k) < n) {
			if (a[i + k] == a[k])k++;
			else break;
		}
		b[i] = k;
		if (k > 0) {
			j = 1;
			while (((i + j) < n) && ((j + b[j]) < k)) {
				b[i + j] = b[j];
				j++;
			}
			i += j;
			k -= j;
		}
		else i++;
	}
	return;
}


int main() {
	char c[N];
	char d[N];
	f(i, N) {
		c[i] = 0;
		d[i] = 0;
		a[i] = 0;
		b[i] = 0;
	}

	int n, k, t;
	int x, y, z, w;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%s", c);
		n = strlen(c);
		x = 0;
		y = n - 1;
		while (x < n) {
			if (c[x] != c[y])break;
			x++;
			y--;
		}
		if (x > y) {
			printf("%s\n", c);
			continue;
		}
		for (int i = x; i <= y; i++) {
			d[i - x] = c[i];
		}
		k = n;
		n = y - x + 1;
		f(i, n) {
			a[i] = d[i];
			a[(2 * n) - i - 1] = d[i];
		}
		z_alg();
		z = 0;
		for (int i = n; i < (2 * n); i++) {
			if ((b[i] + i) == (2 * n)) {
				z = b[i];
				break;
			}
		}
		f(i, (2 * n) + 1) {
			a[i] = 0;
			b[i] = 0;
		}

		f(i, n) {
			a[i] = d[n-i-1];
			a[(2 * n) - i - 1] = d[n - i - 1];
		}
		z_alg();

		w = 0;
		for (int i = n; i < (2 * n); i++) {
			if ((b[i] + i) == (2 * n)) {
				w = b[i];
				break;
			}
		}
		f(i, x)printf("%c", c[i]);
		if (z > w) {
			f(i, z)printf("%c", d[i]);
		}
		else {
			f(i, w)printf("%c", a[i]);
		}

		for(int i=y+1;i<k;i++)printf("%c", c[i]);
		printf("\n");
		f(i, (2 * n) + 1) {
			a[i] = 0;
			b[i] = 0;
		}


		f(i, k + 1)c[i] = 0;
		f(i, n + 2) {
			d[i] = 0;
		}
	}


	return 0;
}