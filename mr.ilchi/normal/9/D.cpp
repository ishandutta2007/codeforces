/*
 * in the name of god
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */

#include <cstdio>

const int MAXN= 35+5;

int n, minh;
long long dp[MAXN][MAXN];

inline void setDyn (){
	dp[0][0]= dp[1][0]= dp[1][1]= 1;
	for (int i= 2;i<= n;i ++){
		for (int j= 1;j<= i;j ++){
			for (int r= 0;r< i;r ++){
				int l= (i-1)-r;
				dp[i][j]+= dp[r][j-1]*(dp[l][0]-dp[l][j-1]);
			}
			dp[i][j]= (dp[i][j]<<1);
			for (int r= 0;r< i;r ++)
				dp[i][j]+= dp[r][j-1]*dp[(i-1)-r][j-1];
		}
		dp[i][0]= dp[i][1];
	}
}
/*****************************************/
int main (){
	scanf ("%d%d", &n, &minh);
	
	setDyn ();
	
	printf ("%I64d\n", dp[n][minh]); 
	
	return 0;
}