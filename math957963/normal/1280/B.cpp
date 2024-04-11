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
#define N 100


int main() {
	char a[N][N];
	f(i, N) {
		f(j,N)a[i][j] = 0;
	}
	int n, m, k, t;
	int x, y, z;
	int s, ans;
	bool v,vv;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, n) {
			scanf("%s", a[i]);
		}
		x = 0;
		y = n * m;
		f(i, n) {
			f(j, m) {
				if (a[i][j] == 'A')x++;
			}
}
		if (x == 0) {
			printf("MORTAL\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}
		if (x == y) {
			printf("0\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}
		vv = false;
		v = true;
		f(i, n) {
			if (a[i][0] == 'P')v = false;
		}
		if (v)vv = true;
		v = true;
		f(i, n) {
			if (a[i][m-1] == 'P')v = false;
		}
		if (v)vv = true;
		v = true;
		f(i, m) {
			if (a[0][i] == 'P')v = false;
		}
		if (v)vv = true;
		v = true;
		f(i, m) {
			if (a[n-1][i] == 'P')v = false;
		}
		if (v)vv = true;
		if (vv) {
			printf("1\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}
		if (a[0][0] == 'A')vv = true;
		if (a[0][m-1] == 'A')vv = true;
		if (a[n-1][0] == 'A')vv = true;
		if (a[n-1][m-1] == 'A')vv = true;
		if (vv) {
			printf("2\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}
		f(i, n) {
			v = true;
			f(j, m) {
				if (a[i][j] == 'P')v = false;
			}
			if (v)vv = true;
	}
		f(i, m) {
			v = true;
			f(j, n) {
				if (a[j][i] == 'P')v = false;
			}
			if (v)vv = true;
		}
		if (vv) {
			printf("2\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}

		f(i, n) {
			if (a[i][0] == 'A')vv = true;
		}
		f(i, n) {
			if (a[i][m - 1] == 'A')vv = true;
		}

		f(i, m) {
			if (a[0][i] == 'A')vv = true;
		}
		f(i, m) {
			if (a[n - 1][i] == 'A')vv = true;
		}
		if (vv) {
			printf("3\n");
			f(i, n + 1) {
				f(j, m + 1)a[i][j] = 0;
			}
			continue;
		}
		else {
				printf("4\n");
				f(i, n + 1) {
					f(j, m + 1)a[i][j] = 0;
				}
				continue;
		}
	}



	return 0;
}