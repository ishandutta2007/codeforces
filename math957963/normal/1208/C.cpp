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

int main() {
	int x, y, z;
	int a[1020][1020];
	scanf("%d", &x);
	y = x / 2;
	z = 0;
	f(i, y) {
		f(j, y) {
			a[(2 * i)][(2 * j)] = (4 * z);
			a[(2 * i) + 1][(2 * j)] = (4 * z) + 1;
			a[(2 * i)][(2 * j) + 1] = (4 * z) + 2;
			a[(2 * i) + 1][(2 * j) + 1] = (4 * z) + 3;
			z++;
		}
	}
	f(i, x) {
		f(j, x - 1) {
			printf("%d ", a[i][j]);
		}
		printf("%d\n", a[i][x - 1]);
	}
	return 0;
}