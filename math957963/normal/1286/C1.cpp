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
#define f(i,n) for(int i=0;i<(int)(n);i++)
#define N 200010


int main() {
	int a[100][30];
	int b[100][30];
	int d[110];
	f(i, 100) {
		f(j, 30) {
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	char c[N];
	f(i, N)c[i] = 0;
	int n, k;
	int x, y, z, yy, zz;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	if (n == 1) {
		printf("? 1 1\n");
		fflush(stdout);
		scanf("%s", c);
		printf("! %c\n", c[0]);
		fflush(stdout);
		return 0;
	}
	printf("? 1 %d\n", n);
	fflush(stdout);
	k = n * (n + 1);
	k = k / 2;
	y = (n + 1) / 2;
	f(i, k) {
		scanf("%s", c);
		x = strlen(c);
		if (x <= y) {
			f(j, x)a[x][(c[j] - 'a')]++;
		}
		f(i, x + 1)c[i] = 0;
	}
	for (int i = y - 2; i >= 0; i--) {
		f(j, 30)a[i + 2][j] -= a[i + 1][j];
	}
	f(i, y - 1) {
		f(j, 30)a[i + 1][j] -= a[i + 2][j];
	}
	printf("? 1 %d\n", n - 1);
	fflush(stdout);
	k = n * (n - 1);
	k = k / 2;
	y = n / 2;
	f(i, k) {
		scanf("%s", c);
		x = strlen(c);
		if (x <= y) {
			f(j, x)b[x][(c[j] - 'a')]++;
		}
		f(i, x + 1)c[i] = 0;
	}
	for (int i = y - 2; i >= 0; i--) {
		f(j, 30)b[i + 2][j] -= b[i + 1][j];
	}
	f(i, y - 1) {
		f(j, 30)b[i + 1][j] -= b[i + 2][j];
	}
	if (n % 2 == 0) {
		y = n / 2;
		while (y >= 1) {
			z = y - 1;
			zz = n - y;
			f(j, 30)if (b[y][j] > 0)d[z] = j;
			a[y][d[z]]--;
			f(j, 30)if (a[y][j] > 0)d[zz] = j;
			y--;
			b[y][d[zz]]--;
		}
	}
	else {
		y = (n + 1) / 2;
		zz = y - 1;
		f(j, 30)if (a[y][j] > 0)d[zz] = j;
		y--;
		b[y][d[zz]]--;
		while (y >= 1) {
			z = y - 1;
			zz = n - y;
			f(j, 30)if (b[y][j] > 0)d[z] = j;
			a[y][d[z]]--;
			f(j, 30)if (a[y][j] > 0)d[zz] = j;
			y--;
			b[y][d[zz]]--;
		}
	}
	printf("! ");
	f(i, n)printf("%c", 'a' + d[i]);
	printf("\n");
	fflush(stdout);


	return 0;
}