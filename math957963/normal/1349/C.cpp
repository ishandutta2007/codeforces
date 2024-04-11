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
#define N 1001
char a[N][N];
int b[N][N];
int c1[(N*N)];
int c2[(N*N)];
int itr, itr2;

int main() {
	f(i, N) {
		f(j, N) {
			a[i][j] = 0;
			b[i][j] = -1;
		}
	}
	int n, m, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	itr = 0;
	scanf("%d %d %d", &n, &m, &k);
	f(i, n) {
		scanf("%s", a[i]);
	}
	f(i, n) {
		f(j, m) {
			v = false;
			if (i > 0) {
				if (a[i - 1][j] == a[i][j])v = true;
			}
			if (j > 0) {
				if (a[i][j - 1] == a[i][j])v = true;
			}
			if (i < (n-1)) {
				if (a[i + 1][j] == a[i][j])v = true;
			}
			if (j < (m-1)) {
				if (a[i][j + 1] == a[i][j])v = true;
			}
			if (v) {
				b[i][j] = 0;
				c1[itr] = i;
				c2[itr] = j;
				itr++;
			}
		}
	}
	itr2 = 0;
	while (itr2 < itr) {
		x = c1[itr2];
		y = c2[itr2];
		if (x > 0) {
			if (b[x - 1][y] == -1) {
				b[x - 1][y] = b[x][y] + 1;
				c1[itr] = x - 1;
				c2[itr] = y;
				itr++;
			}
		}
		if (y > 0) {
			if (b[x][y-1] == -1) {
				b[x][y-1] = b[x][y] + 1;
				c1[itr] = x;
				c2[itr] = y - 1;
				itr++;
			}
		}
		if (x < (n-1)) {
			if (b[x + 1][y] == -1) {
				b[x + 1][y] = b[x][y] + 1;
				c1[itr] = x + 1;
				c2[itr] = y;
				itr++;
			}
		}
		if (y < (m-1)) {
			if (b[x][y + 1] == -1) {
				b[x][y + 1] = b[x][y] + 1;
				c1[itr] = x;
				c2[itr] = y + 1;
				itr++;
			}
		}
		itr2++;
	}
	f(kk, k) {
		scanf("%d %d %lld", &x, &y, &s);
		x--;
		y--;
		ans = (long long)b[x][y];
		if (ans == -1)printf("%d\n", a[x][y] - '0');
		else if(s<=ans)printf("%d\n", a[x][y] - '0');
		else {
			s -= ans;
			z = a[x][y] - '0';
			if (s % 2 == 1)z = 1 - z;
			printf("%d\n", z);
		}
	}
	return 0;
}