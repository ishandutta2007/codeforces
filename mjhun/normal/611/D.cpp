#include <bits/stdc++.h>
#define N 5005
#define MOD 1000000007
using namespace std;

char s[N];
int w[N][N];
int dp[N][N];
int n;

int main(){
	scanf("%d%s",&n,s);
	memset(w,-1,sizeof(w));
	for(int k=n;k;--k){
		dp[k][n-k]=s[n-k]>'0';
		for(int i=n-k-1;i>=0;--i){
			if(s[i]!=s[i+k])w[k][i]=0;
			else if(w[k][i+1]>=0&&w[k][i+1]<k-1)w[k][i]=w[k][i+1]+1;
			else w[k][i]=-1;
			if(s[i]=='0')continue;
			dp[k][i]=dp[k+1][i];
			if(w[k][i]>=0&&s[i+w[k][i]]<s[i+k+w[k][i]])dp[k][i]=(1LL*dp[k][i]+dp[k][i+k])%MOD;
			else dp[k][i]=(1LL*dp[k][i]+dp[k+1][i+k])%MOD;
		}
	}
	printf("%d\n",dp[1][0]);
	return 0;
}