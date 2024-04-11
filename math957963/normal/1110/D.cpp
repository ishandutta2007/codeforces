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
#define N 1000100


int main(){
	int a[N];
	int dp[3][3];
	int dp2[3][3];
	f(i, N){
		a[i] = 0;
	}
	f(ii, 3){
		f(jj, 3){
			dp[ii][jj] = -1;
		}
	}
	dp[0][0] = 0;
	int n, k;
	int x, y, z;
	long long s, ans;
	bool v = true;
	ans = 0;
	scanf("%d %d", &n, &k);
	f(i, n){
		scanf("%d", &x);
		a[x]++;
	}
	for(int i=1;i<=k;i++){
		f(ii, 3){
			f(jj, 3)dp2[ii][jj] = -1;
		}
		f(ii, 3){
			f(jj, 3){
				if (dp[ii][jj] >= 0){
					if (ii + jj <= a[i]){
						y = dp[ii][jj];
						z = a[i] - ii - jj;
						f(kk, 3){
							if(kk<=z)dp2[kk][ii] = max(dp2[kk][ii], y + kk+((z - kk) / 3));
						}
					}
				}
			}
		}
		f(ii, 3){
			f(jj, 3)dp[ii][jj] = dp2[ii][jj];
		}
	}

	printf("%d\n", dp[0][0]);


	return 0;
}