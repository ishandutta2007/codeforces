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
#define N 500010
char a[N + 1];
int b[N + 1];
char c[N + 1];
char d[N + 1];

void z_alg(void) {
	int n, j;
	n = strlen(a);
	int k = 0;
	for (int i = 1; i < n; i++) {
		if ((i + b[i - k]) < (k + b[k])) {
			b[i] = b[i - k];
		}
		else {
			j = max(0, k + b[k] - i);
			while ((i + j) < n) {
				if (a[i + j] == a[j])j++;
				else break;
			}
			b[i] = j;
			k = i;
		}
	}
	b[0] = n;
	return;
}


int main() {
	f(i, N + 1) {
		a[i] = 0;
		b[i] = 0;
		c[i] = 0;
		d[i] = 0;
	}
	scanf("%s", c);
	scanf("%s", a);
	z_alg();
	int n = strlen(c);
	int m = strlen(a);
	int x, y, xx, yy, sx, sy, z, zz, k;
	bool v = true;
	x = 0;
	y = 0;
	xx = 0;
	yy = 0;
	sx = 0;
	sy = 0;
	f(i, n) {
		if (c[i] == '0')sx++;
		else sy++;
	}
	f(i, m) {
		if (a[i] == '0')x++;
		else y++;
	}
	zz = m;
	f(i, m - 1) {
		if ((i + 1 + b[i + 1]) == m) {
			zz = i+1;
			break;
		}
	}
	zz = m - zz;

	for (int i = zz; i < m; i++) {
		if (a[i] == '0')xx++;
		else yy++;
	}
	sx -= x;
	sy -= y;
	k = 0;
	if ((sx >= 0) && (sy >= 0)) {
		f(i, m) {
			d[k] = a[i];
			k++;
		}
		while (true) {
			sx -= xx;
			sy -= yy;
			if ((sx >= 0) && (sy >= 0)) {
				for (int i = zz; i < m; i++) {
					d[k] = a[i];
					k++;
				}
			}
			else {
				sx += xx;
				sy += yy;
				f(i, sx) {
					d[k] = '0';
					k++;
				}
				f(i, sy) {
					d[k] = '1';
					k++;
				}
              break;
			}
		}
	}
	else {
		sx += x;
		sy += y;
		k = 0;
		f(i, sx) {
			d[k] = '0';
			k++;
		}
		f(i, sy) {
			d[k] = '1';
			k++;
		}
	}
	printf("%s", d);

	return 0;
}