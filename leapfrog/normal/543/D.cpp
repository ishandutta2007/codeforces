//Coded by Kamiyama_Shiki on 2021.11.16 {{{
//
#include<bits/stdc++.h>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<48||c>57;c=getchar()) if(!(c^45)) f=1;
	for(;c>=48&&c<=57;c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	f?x=-x:x;
}
template<typename T,typename...L>inline void read(T &x,L&...l) {read(x),read(l...);}//}}}
const int N=200005,P=1000000007;
int fc[N],fi[N],iv[N];//dbinit{{{
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void dbinit(int n=N-1)
{
	fc[0]=1;for(int i=1;i<=n;i++) fc[i]=1ll*fc[i-1]*i%P;
	iv[1]=1;for(int i=2;i<=n;i++) iv[i]=1ll*iv[P%i]*(P-P/i)%P;
	fi[0]=1;for(int i=1;i<=n;i++) fi[i]=1ll*fi[i-1]*iv[i]%P;
}
inline int C(int n,int m) {return n<0||m<0||n<m?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}//}}}
struct edge{int to,nxt;}e[N<<1];int n,et,head[N],f[N][2],g[N][2],h[N];
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void dfs0(int x,int fa)
{
	f[x][0]=f[x][1]=1;
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa)
		dfs0(y,x),f[x][0]=1ll*f[x][0]*(f[y][0]+f[y][1])%P,f[x][1]=1ll*f[x][1]*f[y][1]%P;
}
inline void dfs1(int x,int fa)
{
	//h[y]=f[x][0]/(f[y][0]+f[y][1])*(h[x]+f1)
	int f1=1ll*g[fa][1]*ksm(f[x][1])%P,tmp=1,tot=0;
	g[x][0]=1ll*f[x][0]*(h[x]+f1)%P,g[x][1]=1ll*f[x][1]*f1%P;//h[x]=f0
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa)
		{if((f[y][0]+f[y][1])%P) tmp=1ll*tmp*(f[y][0]+f[y][1])%P;else tot++;}
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa)
		{if((f[y][0]+f[y][1])%P) h[y]=tot?0ll:1ll*tmp*ksm(f[y][0]+f[y][1])%P;else h[y]=tot-1?0:tmp;}
	for(int i=head[x],y;i;i=e[i].nxt) if((y=e[i].to)!=fa) h[y]=1ll*h[y]*(f1+h[x])%P;
	for(int i=head[x];i;i=e[i].nxt) if(e[i].to!=fa) dfs1(e[i].to,x);
}
int main()
{
	read(n);for(int i=2,f;i<=n;i++) read(f),adde(f,i),adde(i,f);
	dfs0(1,0),h[1]=0,g[0][1]=f[1][1],dfs1(1,0);
	for(int i=1;i<=n;i++) printf("%d%c",g[i][0],i==n?'\n':' ');
	return 0;
}