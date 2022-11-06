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
	int a[N][N];
	f(i, N) {
		f(j,N)a[i][j] = 0;
	}
	int n, m, t, x;
	bool v;
	scanf("%d", &t);
	f(tt, t) {
		scanf("%d %d", &n, &m);
		f(i, n) {
			f(j, m)a[i][j] = 4;
		}
		f(i, n) {
			a[i][0]--;
			a[i][m - 1]--;
		}
		f(j, m) {
			a[0][j]--;
			a[n - 1][j]--;
		}
		v = true;
		f(i, n) {
			f(j, m) {
				scanf("%d", &x);
				if (x > a[i][j])v = false;
			}
		}
		if (!v)printf("NO\n");
		else {
          printf("YES\n");
			f(i, n) {
				f(j, m - 1) {
					printf("%d ", a[i][j]);
				}
				printf("%d\n", a[i][m - 1]);
			}

		}
		
	}

	return 0;
}