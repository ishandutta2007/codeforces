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
#define N 2000000


int main() {
	char a[N + 1];
	int dp[10][10][10];
	int dp2[10];
	int ansdp[10][10];
	int x, y, z;
	f(i, N + 1) {
		a[i] = 0;
	}
	f(i, 10) {
		f(j, 10) {
			x = i;
			y = j;
			f(ii, 10)dp2[ii] = -1;
			dp2[x] = 0;
			dp2[y] = 0;
			f(ii, 10) {
				f(jj, 10) {
					if (dp2[jj] == ii) {
						z = (jj + x) % 10;
						if (dp2[z] == -1)dp2[z] = ii + 1;
						z = (jj + y) % 10;
						if (dp2[z] == -1)dp2[z] = ii + 1;
					}
				}
			}
			f(ii, 10)dp[i][j][ii] = dp2[ii];
		}
	}
	int n, m, k, t;
	int ans;
	scanf("%s", a);
	n = strlen(a);
	f(i, 10) {
		f(j, 10)ansdp[i][j] = 0;
	}
	f(i, n - 1) {
		x = a[i + 1] - a[i];
		x = (x + 10) % 10;
		f(ii, 10) {
			f(jj, 10) {
				if ((ansdp[ii][jj] == -1)||(dp[ii][jj][x] == -1))ansdp[ii][jj] = -1;
				else ansdp[ii][jj] += dp[ii][jj][x];
			}
		}
	}
	f(i, 10) {
		f(j, 10) {
			printf("%d", ansdp[i][j]);
			if (j < 9)printf(" ");
			else printf("\n");
		}
	}


	return 0;
}