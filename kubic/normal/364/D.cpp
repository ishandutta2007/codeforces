#include <bits/stdc++.h>
using namespace std;
#define N 1000005 
#define LIM 1000005
#define ll long long
#define gc() (P1==P2 && (P2=(P1=buf)+fread(buf,1,LIM,stdin),P1==P2)?EOF:*P1++)
char *P1,*P2,buf[LIM];int n,b[N],id1[N],id2[N],z[N];ll w,lim,ans,a[N],d[N],p[N];
ll rd()
{
	ll res=0;char c=0;while(!isdigit(c)) c=gc();
	while(isdigit(c)) res=res*10+c-48,c=gc();return res;
}
ll gcd(ll x,ll y) {return y?gcd(y,x%y):x;}
int f(ll x) {return x<=lim?id1[x]:id2[w/x];}
ll slv(int x)
{
	ll t=w=a[x];d[0]=p[0]=0;for(int i=1;1ll*i*i<=w;++i) if(!(w%i)) d[id1[i]=++d[0]]=i;
	lim=d[d[0]];for(int i=d[0];i;--i) if(d[i]*d[i]<w) d[id2[d[i]]=++d[0]]=w/d[i];
	for(int i=1;i<=d[0];++i) z[i]=0;for(int i=1;i<=n;++i) ++z[f(gcd(w,a[i]))];
	for(int i=2;1ll*i*i<=t;++i) if(!(t%i)) {p[++p[0]]=i;while(!(t%i)) t/=i;}if(t>1) p[++p[0]]=t;
	for(int i=1;i<=p[0];++i) for(int j=d[0];j;--j) if(!(d[j]%p[i])) z[f(d[j]/p[i])]+=z[j];
	for(int i=d[0];i;--i) if(z[i]*2>=n) return d[i];return 0;
}
int main()
{
	srand(time(0));n=rd();for(int i=1;i<=n;++i) b[i]=i,a[i]=rd();
	random_shuffle(b+1,b+n+1);for(int i=1;i<=min(n,12);++i) ans=max(ans,slv(b[i]));
	printf("%lld\n",ans);return 0;
}