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
const int N=2005,P=1e9+7;int n,m,q,fr[N],tw[N],we[N];ll bl[N][N];
struct edge{int to,w,nxt;}e[N<<1];int et,head[N];ll d[N];
struct line{int k;ll b;}a[N];long double lis[N];const long double eps=1e-8;
inline void adde(int x,int y,int w) {e[++et]=(edge){y,w,head[x]},head[x]=et;}
int main()
{
	read(n,m,q);for(int i=1,x,y,z;i<=m;i++) read(x,y,z),fr[i]=x,tw[i]=y,we[i]=z,adde(x,y,z),adde(y,x,z);
	memset(bl,~0x3f,sizeof(bl)),bl[0][1]=0;int rs=0;for(int i=1;i<=m;i++) a[i].k=we[i],a[i].b=-1e18;
	for(int i=1;i<=n&&i<=q;i++)
	{
		for(int j=1,x=fr[1],y=tw[1];j<=m;x=fr[++j],y=tw[j])
			bl[i][x]=max(bl[i][x],bl[i-1][y]+we[j]),bl[i][y]=max(bl[i][y],bl[i-1][x]+we[j]);
		for(int j=1;j<=m;j++) a[j].b=max(a[j].b,max(bl[i][fr[j]],bl[i][tw[j]])-1ll*i*we[j]);
		ll mx=0;for(int j=1;j<=m;j++) mx=max(mx,1ll*i*a[j].k+a[j].b);
		rs=(rs+mx)%P;
	}
	sort(a+1,a+m+1,[](line a,line b){ll ja=(n+1ll)*a.k+a.b,jb=(n+1ll)*b.k+b.b;return ja^jb?ja>jb:a.k<b.k;});
	lis[0]=1e18;for(int i=1,nw=n+1;nw<=q;)
	{
		for(int j=i+1;j<=n;j++) if(a[i].k==a[j].k) lis[j]=-1;else lis[j]=(a[i].b-a[j].b)*1.0/(a[j].k-a[i].k);
		int pos=0;for(int j=i+1;j<=n;j++) if(lis[j]+eps>=nw&&lis[j]<lis[pos]) pos=j;
		int L=nw,R=(int)(lis[pos]+eps);R=min(R,q);if(!pos) R=q;
		rs=(rs+a[i].b%P*(R-L+1)+1ll*(L+R)*(R-L+1)/2%P*a[i].k)%P,nw=R+1,i=pos;
	}
	return printf("%d\n",(rs+P)%P),0;
}