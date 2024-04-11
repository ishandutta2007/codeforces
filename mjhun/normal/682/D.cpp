#include <bits/stdc++.h>
#define fore(i,a,b) for(int i=a;i<(b);++i)
using namespace std;

char s[1024],t[1024];
int dp[1024][1024][16][2];
int n,m,p;

int f(int i, int j, int k, int w){
	if(dp[i][j][k][w]<0){
		if(!i||!j||(!k&&!w))dp[i][j][k][w]=0;
		else {
			dp[i][j][k][w]=max(f(i-1,j,k,0),f(i,j-1,k,0));
			if(s[i]==t[j])dp[i][j][k][w]=max(dp[i][j][k][w],1+f(i-1,j-1,k-(w^1),1));
		}
	}
	return dp[i][j][k][w];
}

int main(){
	scanf("%d%d%d%s%s",&n,&m,&p,s+1,t+1);
	memset(dp,-1,sizeof(dp));
	printf("%d\n",f(n,m,p,0));
	return 0;
}