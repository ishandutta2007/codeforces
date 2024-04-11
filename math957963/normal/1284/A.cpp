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
	char a[100][100];
	char b[100][100];
	f(i, 100) {
		f(j, 100) {
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	int n, m, k;
	int x, y, z, yy, zz;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, n) {
		scanf("%s", a[i]);
	}
	f(i, m) {
		scanf("%s", b[i]);
	}
	scanf("%d", &k);

	f(i, k) {
		scanf("%d", &x);
		x--;
		y = x % n;
		z = x % m;
		yy = strlen(a[y]);
		zz = strlen(b[z]);
		f(j, yy)printf("%c", a[y][j]);
		f(j, zz)printf("%c", b[z][j]);
		printf("\n");
	}



	return 0;
}