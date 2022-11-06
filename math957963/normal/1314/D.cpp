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
#define N 81






int main() {
	int a[5][5];
	int dp[6][5];
	int b[5];
	vector<pair<int, int> > d[N][N];
	int r[N][N];
	int n, k, ans, x;
	bool v;
	scanf("%d %d", &n, &k);
	k /= 2;
	f(i, n) {
		f(j, n)scanf("%d", &r[i][j]);
	}
	f(i, n) {
		f(j, n) {
			f(ii, n) {
				if ((i != ii) && (j != ii))d[i][j].push_back(make_pair(r[i][ii] + r[ii][j], ii));
			}
			sort(d[i][j].begin(), d[i][j].end());
		}
	}
	ans = MOD;
	b[0] = 0;
	for (b[1] = 0; b[1] < n; b[1]++) {
		for (b[2] = 0; b[2] < (b[1] + 1); b[2]++) {
			for (b[3] = 0; b[3] < (b[2] + 1); b[3]++) {
				for (b[4] = 0; b[4] < (b[3] + 1); b[4]++) {
					f(i, 5) {
						f(j, 5) {
							a[i][j] = 200000010;
							f(ii, d[b[i]][b[j]].size()) {
								v = true;
								x = d[b[i]][b[j]][ii].second;
								f(jj, 5) {
									if (x == b[jj]) {
										v = false;
										break;
									}
								}
								if (v) {
									a[i][j] = d[b[i]][b[j]][ii].first;
									break;
								}
							}
						}
					}
					f(i, k + 1) {
						f(j, 5)dp[i][j] = MOD;
					}
					dp[0][0] = 0;
					f(i, k) {
						f(ii, 5) {
							f(jj, 5) {
								dp[i + 1][jj] = min(dp[i + 1][jj], dp[i][ii] + a[ii][jj]);
							}
						}
					}
					ans = min(ans, dp[k][0]);
				}
			}
		}
	}
	printf("%d\n", ans);

	return 0;
}