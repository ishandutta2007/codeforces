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
#define N 200010
#define M 100003


int main() {
	bool b[N];
	int c[N];
	int d[N];
	int re[N];
	int ori[N];
	int ans[N];
	f(i, N) {
		c[i] = 0;
		d[i] = 0;
		re[i] = 0;
		ori[i] = 0;
		ans[i] = 0;
	}
	int n, k,q;
	char qqq[2];
	int x, y, z;
	bool v = true;
	scanf("%d %d", &n,&q);
	f(i, n) {
		scanf("%d", &ori[i]);
	}
	f(qq, q) {
		qqq[0] = 0;
		qqq[1] = 0;
		scanf("%s", qqq);
		if (qqq[0] == '>')b[qq] = true;
		else b[qq] = false;
		scanf("%d", &c[qq]);
	}
	f(i, N)d[i] = 0;/* -1,0,1*/
	v = true;
	for (int i = q - 1; i >= 0; i--) {
		if (b[i]) {
			if (c[i] == 0) {
				if (v) {
					x = 1;
					while (d[x+M]==0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				else {
					x = 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
			}
			else if (c[i] > 0) {
				if (v) {
					x = c[i] + 1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i]-1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				else {
					x = c[i] + 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i] - 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
			}
			else {
				c[i] = -c[i];
				if (v) {
					x = c[i];
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i];
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				else {
					x = c[i];
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i];
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				c[i] = -c[i];
			}
		}
		else {
			if (c[i] == 0) {
				if (v) {
					x = 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;	
						if (((x + M) < 0) || ((x + M) >= N))break;

					}
				}
				else {
					x = 1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
			}
			else if (c[i] < 0) {
				c[i] = -c[i];
				if (v) {
					x = c[i] + 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i] - 1;
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				else {
					x = c[i] + 1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i] - 1;
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				c[i] = -c[i];
			}
			else {
				if (v) {
					x = c[i];
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i];
					while (d[x + M] == 0) {
						d[x + M] = 1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
				else {
					x = c[i];
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x++;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
					x = -c[i];
					while (d[x + M] == 0) {
						d[x + M] = -1;
						x--;
						if (((x + M) < 0) || ((x + M) >= N))break;
					}
				}
			}
		}
		if (c[i] < 0 && b[i])v = !v;
		else if (c[i] > 0 && !b[i])v = !v;
	}

	f(i, N) {
		if (i == M)re[M] = 0;
		else {
			re[i] = i - M;
			if (d[i] == -1){
              if (re[i] > 0)re[i] = -re[i];
            }
			else if (d[i] == 1) {
				if (re[i] < 0)re[i] = -re[i];
			}
			else {
				if (!v)re[i] = -re[i];
			}
		}
	}

	f(i, n) {
		ans[i] = re[ori[i] + M];
	}
  
  
	f(i, n-1) {
		printf("%d ", ans[i]);
	}
	printf("%d\n", ans[n-1]);



	return 0;
}