#pragma GCC optimize("O3")
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
#define N 500


int main() {
	bool a[N];
	int cc[N];
	int c[N][3];
	bool b[N];
	int fc[N];
	int n, k, t;
	int now;
	int cnt;
	int num;
	int x, y, z, xx;
	int cx, cy;
	int dep;
	int ntop;
	long long s, ans;
	bool v = true;
	bool v1, v2;
	bool fin;
	int itr;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d", &n);
		f(i, N)a[i] = false;
		a[0] = true;
		fin = false;
		now = 0;
		dep = -1;
		printf("? 1\n");
		fflush(stdout);
		scanf("%d", &num);
		f(i, num) {
			scanf("%d", &c[now][i]);
			c[now][i]--;
		}
		if (num == 2) {
			fin = true;
			printf("! 1\n");
			fflush(stdout);
			continue;
		}
		if (num == 1) {
			now = c[0][0];
			dep = n - 2;
		}
		else {
			v1 = false;
			v2 = false;
			x = c[now][0];
			y = c[now][1];
			f(i, 4) {
				printf("? %d\n", x + 1);
				a[x] = true;
				fflush(stdout);
				scanf("%d", &num);
				f(j, num) {
					scanf("%d", &c[x][j]);
					c[x][j]--;
				}
				if (num == 2) {
					fin = true;
					printf("! %d\n", x + 1);
					fflush(stdout);
					break;
				}
				if (num == 1)v1 = true;
				else {
					f(j, num) {
						z = c[x][j];
						if (!a[z])xx = z;
					}
					x = xx;
				}

				printf("? %d\n", y + 1);
				a[y] = true;
				fflush(stdout);
				scanf("%d", &num);
				f(j, num) {
					scanf("%d", &c[y][j]);
					c[y][j]--;
				}
				if (num == 2) {
					fin = true;
					printf("! %d\n", y + 1);
					fflush(stdout);
					break;
				}
				if (num == 1)v2 = true;
				else {
					f(j, num) {
						z = c[y][j];
						if (!a[z])xx = z;
					}
					y = xx;
				}
				if (v1 || v2) {
					dep = n - 3 - i;
					if (v1&&v2)now = c[0][2];
					else if (v2)now = c[0][0];
					else now = c[0][1];

					break;
				}
			}
			if (fin)continue;
		}
		if (fin)continue;
		if (dep == -1) {
			printf("! %d\n", c[0][2] + 1);
			fflush(stdout);
			continue;
		}
		f(i, N)a[i] = false;
		a[0] = true;
		a[now] = true;
		ntop = now;
		while (dep > 2) {
			f(i, N) {
				if (a[i])b[i] = true;
				else b[i] = false;
			}
			f(i, n - dep - 1) {
				printf("? %d\n", now + 1);
				b[now] = true;
				fflush(stdout);
				scanf("%d", &num);
				f(j, num) {
					scanf("%d", &c[now][j]);
					c[now][j]--;
				}
				if (num == 2) {
					fin = true;
					printf("! %d\n", now + 1);
					fflush(stdout);
					break;
				}
				if (i == 0) {
					cx = -1;
					cy = -1;
				}
				f(j, num) {
					z = c[now][j];
					if (!b[z])xx = z;
					if (i == 0) {
						if ((!b[z]) && (cx < 0))cx = z;
						else if (!b[z])cy = z;
					}
				}
				now= xx;
			}
			if (fin)break;
			printf("? %d\n", now + 1);
			b[now] = true;
			fflush(stdout);
			scanf("%d", &num);
			f(j, num) {
				scanf("%d", &c[now][j]);
				c[now][j]--;
			}
			if (num == 2) {
				fin = true;
				printf("! %d\n", now + 1);
				fflush(stdout);
				break;
			}
			if (num == 1) {
				now = cx;
				ntop = cx;
				dep--;
			}
			else {
				now = cy;
				ntop = cy;
				dep--;
			}
			a[now] = true;
		}
		if (fin)continue;
		f(i, N)fc[i] = -1;
		fc[0] = now;
		itr = 1;
		f(i, 6) {
			printf("? %d\n", fc[i] + 1);
			a[fc[i]] = true;
			fflush(stdout);
			scanf("%d", &num);
			f(j, num) {
				scanf("%d", &c[fc[i]][j]);
				c[fc[i]][j]--;
			}
			if (num == 2) {
				fin = true;
				printf("! %d\n", fc[i] + 1);
				fflush(stdout);
				break;
			}
			if (num == 3) {
				f(j, num) {
					if (!a[c[fc[i]][j]]) {
						fc[itr] = c[fc[i]][j];
						itr++;
					}
				}
			}
		}
		if (fin)continue;
		printf("! %d\n", fc[6] + 1);
		fflush(stdout);
	}


	printf("Finish\n");
	return 0;
}