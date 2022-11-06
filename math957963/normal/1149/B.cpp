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
#define N 251
#define M 100001

int main() {
	char xx[N], yy[N], zz[N];
	int a[N][N][N];
	int b[M][26];
	char c[M];
	char d[5];
	int n,k,q;
	int x, y, z;
	scanf("%d %d", &n, &q);
	f(i, M) {
		f(j,26)b[i][j] = MOD;
		c[i] = 0;
	}
	f(i, N) {
		f(j, N) {
			f(ii, N)a[i][j][ii] = 0;
		}
	}
	scanf("%s", c);
	f(j, 26) {
		k = MOD;
		for (int i = n - 1; i >= 0; i--) {
			b[i+1][j] = k;
			if (c[i] == 'a' + j) {
				k = i + 1;
			}
		}
		b[0][j] = k;
	}
	x = 0;
	y = 0;
	z = 0;
	f(qq, q) {
		f(i, 5)d[i] = 0;
		scanf("%s", d);
		if (d[0] == '+') {
			scanf("%d", &k);
			f(i, 5)d[i] = 0;
			scanf("%s", d);
			if (k == 1) {
				x++;
				xx[x - 1] = d[0];
				f(i, y+1) {
					f(j, z+1) {
						a[x][i][j] = MOD;
						if (a[x - 1][i][j] != MOD)a[x][i][j] = min(a[x][i][j], b[a[x - 1][i][j]][xx[x - 1] - 'a']);
						if (i > 0) {
							if (a[x][i-1][j] != MOD)a[x][i][j] = min(a[x][i][j], b[a[x][i - 1][j]][yy[i - 1] - 'a']);
						}
						if (j > 0) {
							if (a[x][i][j-1] != MOD)a[x][i][j] = min(a[x][i][j], b[a[x][i][j-1]][zz[j - 1] - 'a']);
						}
					}
				}
			}
			else if (k == 2) {
				y++;
				yy[y - 1] = d[0];
				f(i, x + 1) {
					f(j, z + 1) {
						a[i][y][j] = MOD;
						if (a[i][y-1][j] != MOD)a[i][y][j] = min(a[i][y][j], b[a[i][y-1][j]][yy[y - 1] - 'a']);
						if (i > 0) {
							if (a[i - 1][y][j] != MOD)a[i][y][j] = min(a[i][y][j], b[a[i - 1][y][j]][xx[i - 1] - 'a']);
						}
						if (j > 0) {
							if (a[i][y][j - 1] != MOD)a[i][y][j] = min(a[i][y][j], b[a[i][y][j - 1]][zz[j - 1] - 'a']);
						}
					}
				}
			}
			else {
				z++;
				zz[z - 1] = d[0];
				f(i, x + 1) {
					f(j, y + 1) {
						a[i][j][z] = MOD;
						if (a[i][j][z-1] != MOD)a[i][j][z] = min(a[i][j][z], b[a[i][j][z-1]][zz[z - 1] - 'a']);
						if (i > 0) {
							if (a[i - 1][j][z] != MOD)a[i][j][z] = min(a[i][j][z], b[a[i-1][j][z]][xx[i - 1] - 'a']);
						}
						if (j > 0) {
							if (a[i][j - 1][z] != MOD)a[i][j][z] = min(a[i][j][z], b[a[i][j-1][z]][yy[j - 1] - 'a']);
						}
					}
				}
			}
		}
		else {
			scanf("%d", &k);
			if (k == 1)x--;
			if (k == 2)y--;
			if (k == 3)z--;
		}
		if (a[x][y][z] < MOD)printf("YES\n");
		else printf("NO\n");
	}


	return 0;
}