#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 805
#define pb push_back 
const int lim=800,INF=1e9;
int n,m,dp[M],tmp[M],mn[M];vector<int> vc[N];
int f(int x) {return x?x*(x+1)/2+2:0;}
int main()
{
	scanf("%d %d",&n,&m);
	for(int i=1,x,y;i<=m;++i) scanf("%d %d",&x,&y),vc[y].pb(n-x+1);
	for(int i=n,up;i;--i)
	{
		up=min(lim,n-i+1);
		for(auto x:vc[i]) for(int j=0;j<=min(up,x-1);++j)
		{if(x<=up) dp[x]=min(dp[x],dp[j]);dp[j]+=3;}tmp[0]=INF;
		for(int j=0;j<=up;++j) tmp[j+1]=dp[j],tmp[0]=min(tmp[0],dp[j]+f(j));
		for(int j=0;j<=up+1;++j) dp[j]=tmp[j];
	}printf("%d\n",dp[0]);return 0;
}