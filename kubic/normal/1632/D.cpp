#include <bits/stdc++.h>
using namespace std;
#define N 200005
int n,lg[N],dp[N],w[18][N];
int gcd(int x,int y) {return y?gcd(y,x%y):x;}
int qry(int l,int r)
{int t=lg[r-l+1];return gcd(w[t][l],w[t][r-(1<<t)+1]);}
int main()
{
	scanf("%d",&n);for(int i=2;i<=n;++i) lg[i]=lg[i/2]+1;
	for(int i=1;i<=n;++i) scanf("%d",&w[0][i]);
	for(int i=1;i<=17;++i) for(int j=1;j+(1<<i)-1<=n;++j)
		w[i][j]=gcd(w[i-1][j],w[i-1][j+(1<<i-1)]);
	for(int i=1,t=1,mx=0;i<=n;++i)
	{
		while(t<=i && qry(t,i)<i-t+1) ++t;
		if(t<=i && qry(t,i)==i-t+1) mx=max(mx,t);
		dp[i]=mx?dp[mx-1]+1:0;printf("%d ",dp[i]);
	}return 0;
}