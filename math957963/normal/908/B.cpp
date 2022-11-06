#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
	char a[50][51];
	f(i, 50){
		f(j, 51)a[i][j] = 0;
	}
	char b[101];
	f(i, 101)b[i] = 0;
	int x[4];
	int y[4];
	x[0] = 1;
	y[0] = 0;
	x[1] = -1;
	y[1] = 0;
	x[2] = 0;
	y[2] = 1;
	x[3] = 0;
	y[3] = -1;
	int sx, sy, xx, yy;
	int d[4];
	f(i, 4)d[i] = -1;
	int n, m, l;
	bool v;
	int ans = 0;
	scanf("%d %d", &n, &m);
	f(i,n)scanf("%s", a[i]);
	scanf("%s", b);
	l = strlen(b);
	f(i, n){
		f(j, m){
			if (a[i][j] == 'S'){
				sx = i;
				sy = j;
			}
		}
	}

	f(aa, 4){
		d[aa] = 0;
		f(bb, 4){
			if (d[bb] == -1){
				d[bb] = 1;
				f(cc, 4){
					if (d[cc] == -1){
						d[cc] = 2;
						f(dd, 4){
							if (d[dd] == -1){
								d[dd] = 3;
								xx = sx;
								yy = sy;
								v = false;
								f(i, l){
									xx += x[d[b[i] - 48]];
									yy += y[d[b[i] - 48]];
									if (xx < 0 || xx >= n || yy < 0 || yy >= m)break;
									else if (a[xx][yy] == '#')break;
									else if (a[xx][yy] == 'E'){
										v = true;
										break;
									}
								}
								if (v){
									ans++;
								}
								d[dd] = -1;
							}
						}
						d[cc] = -1;
					}
				}
				d[bb] = -1;
			}
		}
		d[aa] = -1;
	}

	printf("%d\n", ans);

	return 0;
}