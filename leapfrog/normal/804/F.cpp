//
#include<bits/stdc++.h>
using namespace std;typedef long long ll;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
const int P=1e9+7,N=5005;int n,n1,n2,et,head[N];struct edge{int to,nxt;}e[N*N];
int dt,ln[N],fc[N],fi[N],dfn[N],low[N],st[N],tp,cl[N],clt,cnt[N],res=0;
int mn[N],mx[N],cg[N];char vs[N],ch[N],bfc[10000005],*g[N],*f[N];
inline int ksm(int x,int q=P-2) {int r=1;for(;q;q>>=1,x=1ll*x*x%P) if(q&1) r=1ll*r*x%P;return r;}
inline void adde(int x,int y) {e[++et]=(edge){y,head[x]},head[x]=et;}
inline void init(int N)
{
	fc[0]=fi[0]=1;for(int i=1;i<=N;i++) fc[i]=1ll*fc[i-1]*i%P;
	fi[N]=ksm(fc[N]);for(int i=N;i;i--) fi[i-1]=1ll*fi[i]*i%P;
}
inline int C(int n,int m) {return n<m||n<0||m<0?0:1ll*fc[n]*fi[m]%P*fi[n-m]%P;}
inline int gcd(int a,int b) {return b?gcd(b,a%b):a;}
inline void tarjan(int x)
{
	dfn[x]=low[x]=++dt,st[++tp]=x,vs[x]=1;
	for(int i=head[x];i;i=e[i].nxt)
		if(!dfn[e[i].to]) tarjan(e[i].to),low[x]=min(low[e[i].to],low[x]);
		else if(vs[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
	if(low[x]==dfn[x]) {int y=++clt;do y=st[tp--],vs[y]=0,cl[y]=clt,cg[clt]=gcd(cg[clt],ln[y]);while(y^x);}
}
int main()
{
	read(n),read(n1),read(n2),g[1]=bfc,f[1]=bfc+5000002,init(N-5);
	for(int i=1;i<=n;i++) {scanf("%s",ch+1);for(int j=1;j<=n;j++) if(ch[j]=='1') adde(i,j);}
	for(int i=1;i<=n;i++)
	{
		read(ln[i]),scanf("%s",g[i]),g[i+1]=g[i]+ln[i]+1;
		for(int j=0;j<ln[i];j++) g[i][j]^=48,mn[i]+=g[i][j];
	}
	for(int i=1;i<=n;i++) if(!dfn[i]) tarjan(i);
	for(int i=2;i<=clt;i++) f[i]=f[i-1]+cg[i-1]+3;
	for(int i=1;i<=n;i++) for(int j=0;j<ln[i];j++) f[cl[i]][j%cg[cl[i]]]|=g[i][j];
	for(int i=clt;i>1;i--)
	{
		int qwq=gcd(cg[i],cg[i-1]);
		for(int j=0;j<cg[i];j++) f[i-1][j%qwq]|=f[i][j],cnt[i]+=f[i][j];
	}
	//for(int i=1;i<=n;i++) for(int j=0;j<ln[i];j++) printf("%d%c",f[i][j],j==ln[i]-1?'\n':' ');
	for(int i=0;i<cg[1];i++) cnt[1]+=f[1][i];
	for(int i=1;i<=n;i++) mx[i]=1ll*cnt[cl[i]]*ln[i]/cg[cl[i]];
	for(int i=1;i<=n;i++)
	{
		int cn1=0,cn2=0;
		for(int j=1;j<=n;j++) if(i^j) {if(mn[j]>mx[i]) ++cn1;else if(mx[j]>mx[i]||(mx[j]==mx[i]&&j<i)) ++cn2;}
		if(0>n1-1-cn1) continue;
		for(int j=n2-cn1-1;j<=n2&&j<=cn2&&j<=n1-cn1-1;j++) (res+=1ll*C(cn2,j)*C(cn1,n2-j-1)%P)%=P;
	}
	return printf("%d\n",res),0;
}