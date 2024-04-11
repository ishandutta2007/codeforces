//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}
int n,m,cnt[300005],sum[300005];char buf[2000005];char *ch[300005];const int P=998244353;
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
int main()
{
	read(n),read(m);int lim=max(n,m),res=0,tot=0;ch[1]=buf;
	cnt[0]=cnt[1]=0,cnt[2]=1;for(int i=3;i<=lim;i++) cnt[i]=(ksm(2,i-3)+cnt[i-2])%P;
//	for(int i=1;i<=lim;i++) printf("%d%c",cnt[i],i==lim?'\n':' ');
	sum[0]=sum[1]=0,sum[2]=1;for(int i=3;i<=lim;i++) sum[i]=(sum[i-1]*2ll+cnt[i])%P;
	for(int i=1;i<=n;i++) scanf("%s",ch[i]+1),ch[i+1]=ch[i]+m+2,ch[i][m+1]='*';
	for(int i=1;i<=m;i++) ch[n+1][i]='*';
//	for(int i=1;i<=n+1;i++) for(int j=1;j<=m+1;j++) putchar(ch[i][j]),putchar(j==m+1?'\n':' ');
	for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) tot+=ch[i][j]=='o';
	for(int i=1;i<=n;i++)
	{
		int len=0;for(int j=1;j<=m+1;j++)
			if(ch[i][j]=='o') len++;
			else res=(res+1ll*sum[len]*ksm(2,tot-len))%P,len=0;
	}
	for(int j=1;j<=m;j++)
	{
		int len=0;for(int i=1;i<=n+1;i++)
			if(ch[i][j]=='o') len++;
			else res=(res+1ll*sum[len]*ksm(2,tot-len))%P,len=0;
	}
	return printf("%d\n",res),0;
}