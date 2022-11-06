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
#define N 200000
vector<long long>dp[N][20];
vector<int>a[N];
bool d[20][20];
char cc[30];
int add[25];
long long as[N];
long long xx, yy, zz;




int main() {
	int n, k, m, mm;
	int x, y, z;
	int xa, xb, xc;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, 20) {
		f(j, 20)d[i][j] = false;
	}
	f(i, n) {
		f(j, 30)cc[j] = 0;
		scanf("%s", cc);
		f(j, n) {
			if (cc[j] == '1')d[i][j] = true;
		}
	}
	vector<int>ff;
	vector<int>nf;
	bool bf[30];
	bool ua[30];
	add[0] = 1;
	f(i, 24)add[i + 1] = add[i] * 2;
	f(i, N)as[i] = 0;

	m = n;
	k = 1;
	f(i, n)k = k * 2;
	f(i, k) {
		x = i;
		y = 0;
		while (x > 0) {
			if (x % 2 == 1)y++;
			x /= 2;
		}
		a[y].push_back(i);
	}


	k = 1;
	f(i, n) {
		f(j, a[i + 1].size()) {
			x = a[i + 1][j];
			if (i == 0) {
				f(ii, n) {
					if (x % 2 == 1) {
						f(jj, k)dp[a[i + 1][j]][ii].push_back(1);
					}
					x /= 2;
				}
			}
			else {
				f(ii, n) {
					if (x % 2 == 1) {
						f(jj, k)dp[a[i + 1][j]][ii].push_back(0);
					}
					x /= 2;
				}
			}

		}
		k = k * 2;
	}


	for (int i = 1; i < n; i++) {
		f(j, a[i].size()) {
			ff.clear();
			nf.clear();
			x = a[i][j];
			f(ii, n) {
				if (x % 2 == 1) {
					ff.push_back(ii);
				}
				else {
					nf.push_back(ii);
				}
				x /= 2;
			}
			f(ii, ff.size()) {
				f(jj, nf.size()) {
					if (d[ff[ii]][nf[jj]]) {
						f(iii, dp[a[i][j]][ff[ii]].size()) {
							dp[(a[i][j] + add[nf[jj]])][nf[jj]][(2 * iii) + 1] += dp[a[i][j]][ff[ii]][iii];
						}
					}
					else {
						f(iii, dp[a[i][j]][ff[ii]].size()) {
							dp[(a[i][j] + add[nf[jj]])][nf[jj]][(2 * iii)] += dp[a[i][j]][ff[ii]][iii];
						}
					}
				}
			}



		}
	}

	m = 1;
	f(i, n)m = m * 2;
	m--;


	k = 1;
	f(i, n - 1)k *= 2;
	f(i, k) {
      ans=0;
      f(j,n)ans+=dp[m][j][i];
		printf("%I64d", ans);
		if (i < (k - 1))printf(" ");
		else printf("\n");
	}


	return 0;
}