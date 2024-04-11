//Coded by Kamiyama_Shiki on 2021.11.07 {{{
//
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
const int P=998244353;
struct node
{
	int a,b,c;
	inline int operator[](int x) {return (a-2ll*b*x%P+2ll*P+1ll*c*x%P*x)%P;}
	inline node operator+(int x) {node rs;rs.a=(a+1ll*x*x)%P,rs.b=(b+x)%P,rs.c=c+1;return rs;}
}X,Y;int n,m,a[1005][1005],id[1005][1005],tt,dp[1000005],iv[1000005];
struct ${int x,y,w;char operator<($ b) const {return w<b.w;}}t[1000005];
int main()
{
	read(n,m);for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) read(a[i][j]);
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) t[++tt]=($){i,j,a[i][j]};
	sort(t+1,t+tt+1);for(int i=1;i<=tt;i++) id[t[i].x][t[i].y]=i;
	int sf=0,cf=0;iv[1]=1;for(int i=2;i<=tt;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	for(int l=1,r=1;l<=tt;l=++r)
	{
		while(r<tt&&t[r+1].w==t[r].w) r++;
		for(int i=l;i<=r;i++) dp[i]=(1ll*sf+X[t[i].x]+Y[t[i].y])%P*iv[cf]%P;
		for(int i=l;i<=r;i++) X=X+t[i].x,Y=Y+t[i].y,sf=(sf+dp[i])%P,cf++;
	}int p,q;read(p,q);
	return printf("%d\n",dp[id[p][q]]),0;
}