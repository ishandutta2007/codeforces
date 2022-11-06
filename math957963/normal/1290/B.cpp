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
#define N 201000


int main() {
	char a[N];
	int b[26][N];

	f(i, N)a[i] = 0;
	int n, k, q;
	int x, y, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%s", a);
	n = strlen(a);
	f(i, 26) {
		b[i][0] = 0;
		f(j, n) {
			if (a[j] == ('a' + i))b[i][j + 1] = b[i][j] + 1;
			else b[i][j + 1] = b[i][j];
		}
	}
	scanf("%d", &q);
	f(qq, q) {
		scanf("%d %d", &x, &y);
		x--;
		v = false;
		if ((y - x) == 1) {
			v = true;
			printf("Yes\n");
		}
		if (!v) {
			f(i, 26) {
				if ((b[i][y] - b[i][x]) == (y - x)) {
					v = true;
					printf("No\n");
				}
			}
		}
		if (!v) {
			f(i, 26) {
				f(j, i) {
					if ((b[i][y] - b[i][x] + b[j][y] - b[j][x]) == (y - x)) {
						v = true;
						if (a[x] != a[y - 1])printf("Yes\n");
						else printf("No\n");
					}
				}
			}
		}
		if (!v)printf("Yes\n");
	}

	return 0;
}