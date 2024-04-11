//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),bz=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) bz=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	bz?x=-x:x;
}/*}}}*/
int n,m,dp[5005][5005],tp[5005],rs=0;char ch[5005][5005];
int main()
{
	read(n),read(m);for(int i=1;i<=n;i++) scanf("%s",ch[i]+1);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) if(ch[i][j]==49) dp[i][j]=dp[i][j-1]+1;
	for(int j=1;j<=m;j++)
	{
		for(int i=1;i<=n;i++) tp[i]=dp[i][j];
		sort(tp+1,tp+n+1,greater<int>());
		for(int i=1;i<=n;i++) rs=max(rs,tp[i]*i);
	}
	return printf("%d\n",rs),0;
}