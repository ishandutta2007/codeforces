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
#define N 200000
bool a[2000];
char c[10];

void writ(int d, int k) {
	for (int i = d * k; i < (d*(k + 1)); i++) {
		printf("? %d\n", i+1);
		fflush(stdout);
		f(i, 10)c[i] = 0;
		scanf("%s", c);
		if (c[0] == 'Y')a[i] = false;
	}
}

int main() {
	int n, k;
	int x, y, z;
	int s, ans;
	scanf("%d %d", &n, &k);
	f(i, 2000)a[i] = false;
	f(i, n)a[i] = true;
	if (k == 1) {
		f(i, n) {
			f(j, i) {
				printf("? %d\n", j+1);
				fflush(stdout);
				f(i,10)c[i] = 0;
				scanf("%s", c);
				printf("? %d\n", i+1);
				fflush(stdout);
				f(i, 10)c[i] = 0;
				scanf("%s", c);
				if (c[0] == 'Y')a[i] = false;
			}
		}
	}
	else {
		x = k / 2;
		y = n / k;
		y *= 2;
		for (int i = 1; i < y; i++) {
			f(j, i) {
				if ((i + j) < y) {
					z = j;
					while (z < y) {
						writ(x, z);
						z += i;
					}
					printf("R\n");
					fflush(stdout);
				}
			}
		}
	}



	ans = 0;
	f(i, n)if (a[i])ans++;
	printf("! %d\n", ans);
	fflush(stdout);
	return 0;
}