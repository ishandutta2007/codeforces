#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#define inf 2139062143
#define ll long long
#define MAXN 300100
#define mod 998244353
#define N 10
#define lc(x) ch[x][0]
#define rc(x) ch[x][1]
#define wch(x) (rc(fa[x])==x)
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
    while(!isdigit(ch)) {if(ch=='-') f=-1;ch=getchar();}
    while(isdigit(ch)) {x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct SA
{
	double ans=inf,avg;
	int n,m,a[2],s[2],bl[2];
	void work()
	{
	    double T,tmp,res=0;
	    memset(s,0,sizeof(s));
	    for(int i=1;i<=n;i++)
	        bl[i]=rand()%m+1,s[bl[i]]+=a[i];
	    for(int i=1;i<=m;i++) res+=(s[i]-avg)*(s[i]-avg);
	    T=10000;
	    while(T>0.1)
	    {
	        T*=0.9;
	        int t=rand()%n+1,x=bl[t],y;
	        if(T>500) y=min_element(s+1,s+m+1)-s;
	        else y=rand()%m+1;
	        if(x==y) continue;
	        tmp=res;
	        res-=(s[x]-avg)*(s[x]-avg)+(s[y]-avg)*(s[y]-avg);
	        s[x]-=a[t],s[y]+=a[t];
	        res+=(s[x]-avg)*(s[x]-avg)+(s[y]-avg)*(s[y]-avg);
	        if(res<=tmp) bl[t]=y;
	        else if(rand()%10000>T) s[x]+=a[t],s[y]-=a[t],res=tmp;
	        else bl[t]=y;
	    }
	    if(res<ans) ans=res;
	}
};
struct splay
{
	int ch[N][2],fa[N],siz[N],ct[N],rt,ed;ll v[N];
	inline int upd(int x){if (x) siz[x]=siz[lc(x)]+ct[x]+siz[rc(x)];}
	inline void rot(int x)
	{
		int f=fa[x],z=fa[f],k=wch(x);
		ch[f][k]=ch[x][k^1],fa[ch[f][k]]=f,fa[f]=x,ch[x][k^1]=f,fa[x]=z;
		if(z) ch[z][f==ch[z][1]]=x;upd(f);upd(x);
	}
	inline void spl(int x){
		for (int y;y=fa[x];rot(x)) if (fa[y]) rot(((wch(x)==wch(y)))?y:x);rt=x;
	}
	inline void fd(ll x){
		int t=rt;while (v[t]!=x && ch[t][x>v[t]]) t=ch[t][x>v[t]];spl(t);
	}
	inline void ins(ll x)
	{
		if (!rt) {rt=ed=1;v[1]=x;ct[1]=siz[1]=1;return;}int t=rt;
		while (v[t]!=x && ch[t][x>v[t]]) siz[t]++,t=ch[t][x>v[t]];
		siz[t]++;if (v[t]==x) {ct[t]++;upd(t);spl(t);return;}ed++;
		ch[t][x>v[t]]=ed;siz[ed]=ct[ed]=1;v[ed]=x;fa[ed]=t;spl(ed);
	}
	inline int qry(ll x,int k)
	{
		fd(x);int t=rt;if ((v[t]>x && k) || (v[t]<x && !k)) return t;
		t=ch[t][k];while (ch[t][k^1]) t=ch[t][k^1];spl(t);return t;
	}
	inline void del(ll x)
	{
		fd(x);int r=rt;if (ct[r]>1) {ct[r]--;return;}qry(x,0);fa[rc(r)]=rt;ch[rt][1]=rc(r);spl(rc(r));
	}
	inline ll frk(ll x){fd(x);return siz[lc(rt)];}
	inline ll krf(ll x)
	{
		int tmp=0,t=rt;
		while (1)
		{//cout<<v[t]<<' '<<x<<' '<<siz[t]<<"  ";
			if (ch[t][0] && x<=siz[ch[t][0]]) t=ch[t][0];
			else
			{
				tmp=siz[ch[t][0]]+ct[t];
				if (x<=tmp) return t;
				x-=tmp,t=ch[t][1];
			}
		}
	}
}bst;
ll ans[MAXN],sumx[MAXN],sumy[MAXN],xx[MAXN],yy[MAXN];
struct data {int id;ll x,y,val;}g[MAXN];
int n,m;
bool cmp(data a,data b) {return a.val<b.val;}
int main()
{
	n=read(),m=read();int a,b;
	for(int i=1;i<=n;i++) g[i].x=xx[i]=read(),g[i].y=yy[i]=read(),g[i].id=i,g[i].val=xx[i]-yy[i];
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=n;i++) sumx[i]=sumx[i-1]+g[i].x,sumy[i]=sumy[i-1]+g[i].y;
	for(int i=1;i<=n;i++) ans[g[i].id]=sumx[i-1]+((ll)i-1)*g[i].y+(sumy[n]-sumy[i])+((ll)n-i)*(g[i].x);
	while(m--)
	{
		a=read(),b=read();
		ans[a]-=min(xx[a]+yy[b],xx[b]+yy[a]);
		ans[b]-=min(xx[a]+yy[b],xx[b]+yy[a]);
	}
	for(int i=1;i<=n;i++) printf("%I64d ",ans[i]);
}