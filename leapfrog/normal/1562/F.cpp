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
const int N=1000005;int n,a[N],id[N],rs[N],vs[N];ll vl[105][105];
int pr[N],pc,ls[N],ph[N],mu[N];char pv[N];//prinit{{{
inline void prinit(int n)
{
	pv[1]=mu[1]=ph[1]=1,ls[1]=0;for(int i=1;i<=n;i++)
	{
		if(!pv[i]) pr[++pc]=i,mu[i]=-1,ph[i]=i-1,ls[i]=i;
		for(int j=1;j<=pc&&i*pr[j]<=n;j++)
		{
			ls[i*pr[j]]=pr[j],mu[i*pr[j]]=i%pr[j]?-mu[i]:0;
			ph[i*pr[j]]=ph[i]*(pr[j]-!!(i%pr[j]));
			pv[i*pr[j]]=1;if(i%pr[j]==0) break;
		}
	}
}//}}}//
#ifdef ONLINE_JUDGE
inline ll qry(int x,int y) {printf("? %d %d\n",x,y),fflush(stdout);ll r;return read(r),r;}
#else
inline ll qry(int x,int y) {return 1ll*a[x]*a[y]/__gcd(a[x],a[y]);}
#endif
inline void baoli()
{
#ifndef ONLINE_JUDGE
	for(int i=1;i<=n;i++) read(a[i]);
#endif
	ll mx=0;for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++)
		mx=max(mx,vl[i][j]=vl[j][i]=qry(i,j));
	int r=sqrt(mx)-3,l;r=max(r,1),l=r-n+1;while(1ll*r*(r-1)!=mx) r++,l++;
	for(int i=1;i<=n;i++) rs[i]=0;
	for(int nw=r;nw>l;nw--)
	{
		int wa,wb;for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++)
			if(!rs[i]&&!rs[j]&&vl[i][j]==1ll*nw*(nw-1)) wa=i,wb=j;
		int wh=wa;for(int i=1;i<=n;i++) if(wa^i&&vl[wa][i]%nw) {wh=wb;break;}
		rs[wh]=nw;
	}
	for(int i=1;i<=n;i++) if(!rs[i]) rs[i]=l;
	putchar('!');for(int i=1;i<=n;i++) printf(" %d",rs[i]);
	putchar('\n'),fflush(stdout);
}
inline int fac(ll x)
{
	int rs=0;for(int i=1;i<=pc&&x>1000000;i++) if(x%pr[i]==0)
		{rs=max(rs,pr[i]);while(x%pr[i]==0) x/=pr[i];}
	while(x^1) rs=max(rs,ls[x]),x/=ls[x];
	return rs;
}
inline void real()
{
#ifndef ONLINE_JUDGE
	for(int i=1;i<=n;i++) read(a[i]);
#endif
	int mx=0,ma=0,mb=0;ll mw=0;for(int i=1;i<=5000;i++)
	{
		int a=rand()%n+1,b=rand()%n+1;if(a==b) b=b%n+1;
		ll mv=qry(a,b);int vl=fac(mv);if(vl>mx) mx=vl,ma=a,mb=b,mw=mv;
	}
	int qwq=rand()%n+1;while(qwq==ma||qwq==mb) qwq=rand()%n+1;
	if(qry(qwq,ma)%mx) swap(ma,mb);
	//cerr<<"debug : "<<ma<<" "<<mx<<","<<mw/mx<<"=="<<a[ma]<<endl;
	rs[ma]=mx,rs[mb]=mw/mx;for(int i=1;i<=n;i++) if(i!=ma&&i!=mb) rs[i]=qry(ma,i)/mx;
	putchar('!');for(int i=1;i<=n;i++) printf(" %d",rs[i]);
	putchar('\n'),fflush(stdout);
}
inline void solve() {read(n);if(n<=101) return baoli();else return real();}
int main() {int Ca;for(prinit(N-1),read(Ca),srand(time(0));Ca--;) solve();return 0;}