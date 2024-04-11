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
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}/*}}}*/
inline int gc(char x) {return x=='+'?1:(x=='*'?2:3);}
const int N=100005;char c[5],v[5],ch[N];
int n,a[N],cnt=0,L[N],R[N],vv[N],dp[N],pr[N];
inline void solve(int l,int r)
{
	if(l>r) return;else cnt=0,R[0]=l-1;
	int ls=l-1,vl=1;for(int i=l;i<=r;i++)
	{
		if(a[i]^1) {vl=min(10000000,vl*a[i]);continue;}
		{if(ls+1<i) cnt++,L[cnt]=ls+1,R[cnt]=i-1,vv[cnt]=vl;ls=i,vl=1;}
	}if(ls!=r) ++cnt,L[cnt]=ls+1,R[cnt]=r,vv[cnt]=vl;
	vl=1;for(int i=1;i<=cnt;i++) vl=min(10000000ll,1ll*vv[i]*vl);
	for(int i=l;i<L[1];i++) ch[i]='+';
	for(int i=R[cnt];i<r;i++) ch[i]='+';
	if(vl==10000000) return;else for(int i=1;i<=cnt;i++) dp[i]=0;
	for(int i=1;i<=cnt;i++)
	{
		int vl=1;for(int j=i;j>=1;j--)
		{
			vl*=vv[j];if(dp[i]<dp[j-1]+L[j]-R[j-1]-1+vl)
				dp[i]=dp[j-1]+L[j]-R[j-1]-1+vl,pr[i]=j;
		}
	}
	for(int nw=pr[cnt];nw;nw=pr[nw]-1)
		for(int i=R[pr[nw]-1];i<L[pr[nw]];i++) ch[i]='+';
}
int main()
{
	read(n);for(int i=1;i<=n;i++) read(a[i]);
	scanf("%s",c+1);for(int i=1,e=strlen(c+1);i<=e;i++) v[gc(c[i])]=1;
	if(!v[1]&&!v[2]) 
	{
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':'-');
		return 0;
	}
	if(!v[1]&&!v[3])
	{
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':'*');
		return 0;
	}
	if(v[1]&&!v[2])
	{
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':'+');
		return 0;
	}
	if(!v[1]&&v[2])
	{
		for(int i=1;i<=n;i++) if(a[i]==0) ch[i-1]='-';else ch[i-1]='*';
		for(int i=1;i<=n;i++) printf("%d%c",a[i],i==n?'\n':ch[i]);
		return 0;
	}
	for(int i=1;i<n;i++) ch[i]='*';
	for(int i=1;i<=n;i++) if(!a[i]) ch[i-1]='+',ch[i]='+';
	int ls=0;for(int i=1;i<=n+1;i++) if(!a[i]) solve(ls+1,i-1),ls=i;
	for(int i=1;i<n;i++) printf("%d",a[i]),putchar(ch[i]);
	return printf("%d\n",a[n]),0;
}