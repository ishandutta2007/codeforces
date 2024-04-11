#include <bits/stdc++.h>
using namespace std;
#define N 505
int t,a[2][N],dp[N],pr[N];
void print(int u) {if(!u) return;print(pr[u]);printf("%d ",a[1][u]);}
int main()
{
	for(int i=0;i<2;++i) {scanf("%d",&a[i][0]);for(int j=1;j<=a[i][0];++j) scanf("%d",&a[i][j]);}
	for(int i=1;i<=a[0][0];++i,t=0) for(int j=1;j<=a[1][0];++j)
		if(a[0][i]==a[1][j] && dp[j]<dp[t]+1) dp[j]=dp[t]+1,pr[j]=t;
		else if(a[0][i]>a[1][j] && dp[j]>dp[t]) t=j;
	t=0;for(int i=1;i<=a[1][0];++i) if(dp[i]>dp[t]) t=i;printf("%d\n",dp[t]);print(t);
}