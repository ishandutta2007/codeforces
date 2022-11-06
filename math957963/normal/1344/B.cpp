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
#define N 1010
char a[N][N];
int n, m, k;
void dfs(int x, int y) {
	a[x][y] = '.';
	if (x > 0) {
		if (a[x - 1][y] == '#')dfs(x - 1, y);
	}
	if (x < n - 1) {
		if (a[x + 1][y] == '#')dfs(x + 1, y);
	}
	if (y > 0) {
		if (a[x][y - 1] == '#')dfs(x, y - 1);
	}
	if (y < m - 1) {
		if (a[x][y + 1] == '#')dfs(x, y + 1);
	}
	return;
}



int main() {

	f(i, N) {
		f(j, N)a[i][j] = 0;
	}
	int x, y, z;
	int s, ans;
	bool v = true;
	bool v1, v2;
	ans = 0;
	scanf("%d %d", &n, &m);
	f(i, n) {
		scanf("%s", a[i]);
	}
	v1 = false;
	f(i, n) {
		x = 0;
		f(j, m) {
			if (x == 0) {
				if (a[i][j] == '#')x = 1;
			}
			else if (x == 1) {
				if (a[i][j] == '.')x = 2;
			}
			else if (a[i][j] == '#')v = false;
		}
		if (x == 0)v1 = true;
	}
	v2 = false;
	f(i, m) {
		x = 0;
		f(j, n) {
			if (x == 0) {
				if (a[j][i] == '#')x = 1;
			}
			else if (x == 1) {
				if (a[j][i] == '.')x = 2;
			}
			else if (a[j][i] == '#')v = false;
		}
		if (x == 0)v2 = true;
	}
	if (v1 && (!v2))v = false;
	if (v2 && (!v1))v = false;
	if (!v) {
		printf("-1\n");
		return 0;
	}
	ans = 0;
	f(i, n) {
		f(j, m) {
			if (a[i][j] == '#') {
				dfs(i, j);
				ans++;
			}
		}
	}

	printf("%d\n", ans);


	return 0;
}