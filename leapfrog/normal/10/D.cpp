//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
//dp[i][j]=max(dp[k][w]+1) a[k]=b[w],a[i]=b[j],a[k]<a[i]
int n,m,a[505],b[505],dp[505][505],ps[505][505];
inline void output(int x) {if(x) output(ps[n][x]),printf("%d ",b[x]);}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	read(m);for(int i=1;i<=m;i++) read(b[i]);
	for(int i=1,ls=0;i<=n;i++,ls=0) for(int j=1;j<=m;j++)
	{
		dp[i][j]=dp[i-1][j],ps[i][j]=ps[i-1][j];
		if(a[i]==b[j]&&dp[i-1][ls]+1>dp[i][j]) dp[i][j]=dp[i-1][ls]+1,ps[i][j]=ls;
		if(a[i]>b[j]&&dp[i-1][ls]<dp[i][j]) ls=j;
	}
	int wh=0;for(int i=1;i<=m;i++) if(dp[n][wh]<dp[n][i]) wh=i;
	return printf("%d\n",dp[n][wh]),output(wh),putchar('\n'),0;
}