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
#define N 300000
int b[N][20][2][2];
vector<int>a;

int solve(int x, int k, int w, int l) {
	if (k == 1) {
		x = x * 2;
		if ((a[x] == 1) && (a[x+1] == 1)) {
			if (w == 1) {
				if (l == 1) return 1;
				else return -1;
			}
			else {
				if (l == 1) return -1;
				else return -1;
			}
		}
		if ((a[x] == 1) && (a[x + 1] == 0)) {
			if (w == 1) {
				if (l == 1) return -1;
				else return 1;
			}
			else {
				if (l == 1) return 1;
				else return -1;
			}
		}
		if ((a[x] == 0) && (a[x + 1] == 1)) {
			if (w == 1) {
				if (l == 1) return -1;
				else return 1;
			}
			else {
				if (l == 1) return 1;
				else return -1;
			}
		}
		if ((a[x] == 0) && (a[x + 1] == 0)) {
			if (w == 1) {
				if (l == 1) return -1;
				else return -1;
			}
			else {
				if (l == 1) return -1;
				else return 0;
			}
		}
	}

	int ret1[2][2];
	int ret2[2][2];
	int ans = -1;
	f(i, 2) {
		f(j, 2) {
			ret1[i][j] = b[(2*x)][k-1][i][j];
			ret2[i][j] = b[(2*x)+1][k-1][i][j];
		}
	}
	if (w == 1) {
		if (l == 1) {
			if ((ret1[0][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {

				}
				if ((ret2[1][0] >= 0)) {

				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[0][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {

				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][1] + 3);
				}
			}
			if ((ret1[1][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[1][0] + 2);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[1][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][0] + 3);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[1][1] + 3);
				}
			}
		}


		else {
			if ((ret1[0][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {

				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][0] + 1);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[0][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {

				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][1] + 3);
				}
			}
			if ((ret1[1][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][0] + 1);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[1][0] + 2);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[1][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][0] + 3);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {

				}
			}
		}
}


	else {
		if (l == 1) {

			if ((ret1[0][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {

				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[0][1] + 2);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][0] + 2);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[0][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[0][0] + 2);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[0][1] + 2);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][1] + 3);
				}
			}
			if ((ret1[1][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][0] + 2);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {

				}
				if ((ret2[1][1] >= 0)) {

				}
			}
			if ((ret1[1][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][0] + 3);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {

				}
				if ((ret2[1][1] >= 0)) {

				}
			}


		}
		else {

			if ((ret1[0][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[0][0]);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[0][1] + 2);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][0] + 2);
				}
				if ((ret2[1][1] >= 0)) {
					ans = max(ans, ret1[0][0] + ret2[1][1] + 3);
				}
			}
			if ((ret1[0][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[0][0] + 2);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[0][1] + 2);
				}
				if ((ret2[1][0] >= 0)) {
					ans = max(ans, ret1[0][1] + ret2[1][0] + 3);
				}
				if ((ret2[1][1] >= 0)) {
				}
			}
			if ((ret1[1][0] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][0] + 2);
				}
				if ((ret2[0][1] >= 0)) {
					ans = max(ans, ret1[1][0] + ret2[0][1] + 3);
				}
				if ((ret2[1][0] >= 0)) {

				}
				if ((ret2[1][1] >= 0)) {

				}
			}
			if ((ret1[1][1] >= 0)) {
				if ((ret2[0][0] >= 0)) {
					ans = max(ans, ret1[1][1] + ret2[0][0] + 3);
				}
				if ((ret2[0][1] >= 0)) {

				}
				if ((ret2[1][0] >= 0)) {

				}
				if ((ret2[1][1] >= 0)) {

				}
			}

		}
	}
	return ans;




}




int main() {

	int n, k, nn,nnn;
	int x, y;
	int s, ans;
	scanf("%d %d", &n, &k);
	x = 1;
	f(i, n)x = x * 2;
	nn = x;
	f(i, nn)a.push_back(0);
	f(i, k) {
		scanf("%d", &x);
		a[x - 1] = 1;
	}
	nn /= 2;
	y = 1;
	while (nn >= 1) {
		f(i, nn) {
			f(ii, 2) {
				f(jj, 2) {
					b[i][y][ii][jj] = solve(i, y, ii, jj);
				}
			}
		}
		nn /= 2;
		y++;
	}
	y--;
	ans = 0;
	s = b[0][y][0][0];
	if(s>=0)ans = max(ans, s);
	s = b[0][y][0][1];
	if(s>=0)ans = max(ans, s+1);
	s = b[0][y][1][0];
	if(s>=0)ans = max(ans, s+1);
	s = b[0][y][1][1];
	if(s>=0)ans = max(ans, s+1);
	printf("%d\n", ans);


	return 0;
}