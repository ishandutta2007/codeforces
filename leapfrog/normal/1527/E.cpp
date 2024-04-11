//{{{
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:0;
}/*}}}*/
int n,K,a[35005],ls[35005],nx[35005],tn[35005],dp[105][35005],L,R,sm;
inline void move(int dl,int dr)
{
	while(L<dl) sm-=nx[L]<=R?nx[L]-L:0,L++;
	while(L>dl) L--,sm+=nx[L]<=R?nx[L]-L:0;
	while(R<dr) R++,sm+=ls[R]>=L?R-ls[R]:0;
	while(R>dr) sm-=ls[R]>=L?R-ls[R]:0,R--;
}
inline void work(int l,int r,int dl,int dr,int dep)
{
	int md=(l+r)>>1,dmd,vl=2e9;if(l>r||dl>dr) return;
	//printf("%d %d %d %d %d\n",l,r,dl,dr,dep);
	for(int i=dl;i<=md&&i<=dr;i++)
	{
		move(i,md);int nv=dp[dep-1][i-1]+sm;
		if(nv<vl) vl=nv,dmd=i;
	}
	dp[dep][md]=vl,work(l,md-1,dl,dmd,dep),work(md+1,r,dmd,dr,dep);
}
int main()
{
	read(n),read(K);for(int i=1;i<=n;i++) read(a[i]),tn[i]=n+1;
	for(int i=n;i;i--) nx[i]=tn[a[i]],tn[a[i]]=i;
	memset(tn,0,sizeof(tn));for(int i=1;i<=n;i++) ls[i]=tn[a[i]],tn[a[i]]=i;
	memset(dp[0],0x3f,sizeof(dp[0])),dp[0][0]=0;for(int i=1;i<=K;i++) work(1,n,1,n,i);
	//for(int i=1;i<=K;i++) for(int j=1;j<=n;j++) printf("%d%c",dp[i][j],j==n?'\n':' ');
	return printf("%d\n",dp[K][n]),0;
}