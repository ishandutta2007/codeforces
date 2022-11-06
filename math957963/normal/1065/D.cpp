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
#define N 200
int n;
int xy[15][15][3];
int xy2[15][15][3];

void init(){
	f(i, 15){
		f(j, 15){
			f(ii, 3){
				xy[i][j][ii] = MOD;
				xy2[i][j][ii] = MOD;
			}
		}
	}
}

void dfs(int x, int y, int k, int z,int w){
	int xx, yy;
	if (xy[x][y][k] > z){
		xy[x][y][k] = z;
		xy2[x][y][k] = w;
	}
	else if (xy[x][y][k] == z&&xy2[x][y][k]>w){
		xy2[x][y][k] = w;
	}
	else return;
	if (z > 3)return;
	if (k == 0){
		xx = x + 2;
		yy = y + 1;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1,w);
		}
		xx = x + 2;
		yy = y - 1;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x - 2;
		yy = y + 1;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x - 2;
		yy = y - 1;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x + 1;
		yy = y + 2;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x + 1;
		yy = y - 2;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x - 1;
		yy = y + 2;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
		xx = x - 1;
		yy = y - 2;
		if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
			dfs(xx, yy, k, z + 1, w);
		}
	}
	else if (k == 1){
		f(i, n){
			xx = x + i + 1;
			yy = y + i + 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x - i - 1;
			yy = y + i + 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x + i + 1;
			yy = y - i - 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x - i - 1;
			yy = y - i - 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
	}
	else{
		f(i, n){
			xx = x + i + 1;
			yy = y;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x - i - 1;
			yy = y;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x;
			yy = y + i + 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
		f(i, n){
			xx = x;
			yy = y - i - 1;
			if (0 <= xx&&xx < n && 0 <= yy&&yy < n){
				dfs(xx, yy, k, z + 1, w);
			}
			else break;
		}
	}
	f(i, 3){
		if (i != k)dfs(x, y, i, z + 1, w + 1);
	}


	return;
}



int main(){
	int x[N];
	int y[N];
	int dp[200][3];
	int dp2[200][3];
	int k, z;
	int s, ans;
	bool v = true;
	ans = 0;
	scanf("%d", &n);
	f(i, n){
		f(j, n){
			scanf("%d", &z);
			x[z - 1] = i;
			y[z - 1] = j;
		}
	}
	f(i, n*n){
		f(j, 3){
			dp[i][j] = MOD;
			dp2[i][j] = MOD;
		}
	}
	dp[0][0] = 0;
	dp2[0][0] = 0;
	dp[0][1] = 0;
	dp2[0][1] = 0;
	dp[0][2] = 0;
	dp2[0][2] = 0;

	f(i, (n*n)-1){
		init();
		dfs(x[i], y[i], 0, 0, 0);
		f(j, 3){
			if (dp[i][0] + xy[x[i + 1]][y[i + 1]][j] < dp[i + 1][j]){
				dp[i + 1][j] = dp[i][0] + xy[x[i + 1]][y[i + 1]][j];
				dp2[i + 1][j] = dp2[i][0] + xy2[x[i + 1]][y[i + 1]][j];
			}
			else if (dp[i][0] + xy[x[i + 1]][y[i + 1]][j] == dp[i + 1][j] && dp2[i][0] + xy2[x[i + 1]][y[i + 1]][j] < dp2[i + 1][j]){
				dp2[i + 1][j] = dp2[i][0] + xy2[x[i + 1]][y[i + 1]][j];
			}
		}
		init();
		dfs(x[i], y[i], 1, 0, 0);
		f(j, 3){
			if (dp[i][1] + xy[x[i + 1]][y[i + 1]][j] < dp[i + 1][j]){
				dp[i + 1][j] = dp[i][1] + xy[x[i + 1]][y[i + 1]][j];
				dp2[i + 1][j] = dp2[i][1] + xy2[x[i + 1]][y[i + 1]][j];
			}
			else if (dp[i][1] + xy[x[i + 1]][y[i + 1]][j] == dp[i + 1][j] && dp2[i][1] + xy2[x[i + 1]][y[i + 1]][j] < dp2[i + 1][j]){
				dp2[i + 1][j] = dp2[i][1] + xy2[x[i + 1]][y[i + 1]][j];
			}
		}
		init();
		dfs(x[i], y[i], 2, 0, 0);
		f(j, 3){
			if (dp[i][2] + xy[x[i + 1]][y[i + 1]][j] < dp[i + 1][j]){
				dp[i + 1][j] = dp[i][2] + xy[x[i + 1]][y[i + 1]][j];
				dp2[i + 1][j] = dp2[i][2] + xy2[x[i + 1]][y[i + 1]][j];
			}
			else if (dp[i][2] + xy[x[i + 1]][y[i + 1]][j] == dp[i + 1][j] && dp2[i][2] + xy2[x[i + 1]][y[i + 1]][j] < dp2[i + 1][j]){
				dp2[i + 1][j] = dp2[i][2] + xy2[x[i + 1]][y[i + 1]][j];
			}
		}

	}
	n = n*n;
	ans = dp[n - 1][0];
	s = dp2[n - 1][0];
	if (dp[n - 1][1] < ans){
		ans = dp[n - 1][1];
		s = dp2[n - 1][1];
	}
	else if (dp[n - 1][1] == ans&&dp2[n - 1][1] < s){
		s = dp2[n - 1][1];
	}

	if (dp[n - 1][2] < ans){
		ans = dp[n - 1][2];
		s = dp2[n - 1][2];
	}
	else if (dp[n - 1][2] == ans&&dp2[n - 1][2] < s){
		s = dp2[n - 1][2];
	}
	printf("%d %d\n", ans, s);


	return 0;
}