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
#define N 110


int main() {
	int t, n, m, k;
	char a[N][N];
	char b[N][N];
	char c[65];
	int d[70];
	f(i, 26)c[i] = 'A' + i;
	f(i, 26)c[i+26] = 'a' + i;
	f(i, 10)c[i+52] = '0' + i;
	f(i, N) {
		f(j, N) {
			a[i][j] = 0;
			b[i][j] = 0;
		}
	}
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d %d", &n, &m, &k);
		f(i, n) {
			scanf("%s", a[i]);
		}
		s = 0;
		f(i, n) {
			f(j, m) {
				if (a[i][j] == 'R')s++;
			}
		}
		f(i, k)d[i] = (i*s) / k;
		d[k] = s + 1;
		x = 0;
		y = 0;
		f(i, n) {
			if (i % 2 == 0) {
				f(j, m) {
					b[i][j] = c[y];
					if (a[i][j] == 'R')x++;
					if (x >= d[y + 1])y++;
				}
			}
			else {
				for (int j = m - 1; j >= 0; j--) {
					b[i][j] = c[y];
					if (a[i][j] == 'R')x++;
					if (x >= d[y + 1])y++;
				}
			}
		}
		f(i, n) {
			f(j, m)printf("%c", b[i][j]);
			printf("\n");
		}
		f(i, n) {
			f(j, m + 1) {
				a[i][j] = 0;
				b[i][j] = 0;
			}
		}
	}



	return 0;
}