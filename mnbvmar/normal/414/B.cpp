#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string.h>
#include <string>

using namespace std;

const int MaxN = 2005,
          MOD = 1000000007;

int n, k;

void input(){
	scanf("%d%d", &n, &k);
}

int dp[MaxN][MaxN];


int main(){
	input();
	
	dp[0][1] = 1;
	fill(dp[0]+2, dp[0]+n+1, 0);
	
	for(int ik = 0; ik < k; ik++){
		for(int in = 1; in <= n; in++){
			for(int u = in; u <= n; u += in){
				dp[ik+1][u] = (dp[ik+1][u]+dp[ik][in])%MOD;
			}
		}
	}
	
	int sum = 0;
	for(int in = 1; in <= n; in++)
		sum = (sum+dp[k][in])%MOD;
	
	printf("%d\n", sum);
}