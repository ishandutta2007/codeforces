//
//
#include<bits/stdc++.h>
#define int long long
using namespace std;const int P=998244353;
template<typename T>inline void read(T &x)
{
	x=0;char c=getchar(),f=0;
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=1;
	for(;c>='0'&&c<='9';c=getchar()) x=(x<<1)+(x<<3)+(c^48);
	if(f) x=-x;
}
int T,n,k,a[200005],b[200005],w[200005],fa[200005],le[200005],ri[200005],vl[200005],v[200005];
inline int getf(int x) {return fa[x]==x?x:fa[x]=getf(fa[x]);}
inline void mrg(int x,int y)
{
	int u=getf(x),v=getf(y);if(!(u^v)) return;
	fa[v]=u,le[u]=min(le[u],le[v]),ri[u]=max(ri[u],ri[v]);
}
inline void work()
{
	read(n),read(k);int ans=1;
	for(int i=1;i<=n;i++) read(a[i]),w[a[i]]=i,v[i]=0;
	for(int i=1;i<=k;i++) read(b[i]),v[b[i]]=1;
	if(n==k) return(void)(puts("0"));
	for(int i=0;i<=n;i++) fa[i]=i,le[i]=ri[i]=i,vl[i]=a[i];
	for(int i=1;i<=k;i++)
	{
		int now=getf(w[b[i]]),l=le[now],r=ri[now],lf,rt,lv,rv;char flg1=0,flg2=0;
		if(l>1) {lf=getf(l-1),lv=vl[lf];if(!v[lv]) flg1=1;}
		if(r<n) {rt=getf(r+1),rv=vl[rt];if(!v[rv]) flg2=1;}
		if(!flg1&&!flg2) {ans=0;break;}else v[b[i]]=0;
		{if(flg1&&!flg2) mrg(now,lf);}{if(!flg1&&flg2) mrg(now,rt);}
		if(!(flg1&&!flg2)&&!(!flg1&&flg2)) ans=ans*2%P,mrg(now,lf);
	}
	printf("%lld\n",(ans%P+P)%P);
}
signed main() {for(read(T);T--;) work();return 0;}