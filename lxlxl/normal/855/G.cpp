#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
const int maxn = 210000;

int n,Q; ll ans;
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}

int fa[maxn],s[maxn]; ll f[maxn];
int findfa(const int x){return fa[x]==x?x:fa[x]=findfa(fa[x]);}

ll sqr(int x){ return (ll)x*x; }
ll cal2(int x){ return (ll)x*(x-1)*(n-x)*2; }
ll cal3(int x){ return (ll)x*(x-1)*(x-2); }

int dfn[maxn],id,dep[maxn],siz[maxn],par[maxn];
void dfs(const int x)
{
	fa[x]=x,s[x]=1;
	
	dfn[x]=++id; siz[x]=1;
	for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(y!=par[x])
	{
		par[y]=x,dep[y]=dep[x]+1,dfs(y);
		siz[x]+=siz[y];
		
		f[x]+=sqr(siz[y]);
	}
	
	ans+=(ll)s[x]*(sqr(n-s[x])-f[x]-sqr(n-siz[x]));
	ans+=cal2(s[x]);
	ans+=cal3(s[x]);
}

int q[maxn],tail,t[maxn],tp;

int main()
{
//	freopen("tmp.in","r",stdin);
//	freopen("tmp.out","w",stdout);
	
	read(n);
	for(int i=1;i<n;i++)
	{
		int x,y; read(x); read(y);
		ins(x,y); ins(y,x);
	}
	siz[0]=n+1; par[1]=0,dep[1]=1; dfs(1);
	printf("%lld\n",ans);
	
	read(Q);
	for(int ti=1;ti<=Q;ti++)
	{
		int x,y; read(x); read(y);
		if(x==y) { printf("%lld\n",ans); continue; }
		if(dep[x]>dep[y]) swap(x,y);
		
		tail=tp=0;
		if(dfn[x]<=dfn[y]&&dfn[x]+siz[x]>dfn[y])
		{
			while(dep[y]>=dep[x])
			{
				y=findfa(y);
				t[++tp]=y;
				y=par[y];
			}
		}
		else
		{
			if(dfn[x]>dfn[y]) swap(x,y);
			int f1=x,f2=y,ok=0;
			while(!ok)
			{
				f1=findfa(f1);
				q[++tail]=f1;
				ok|=dfn[f1]<=dfn[x]&&dfn[f1]+siz[f1]>dfn[y];
				f1=par[f1];
			}
			ok=0;
			while(!ok)
			{
				f2=findfa(f2);
				t[++tp]=f2;
				ok|=dfn[f2]<=dfn[x]&&dfn[f2]+siz[f2]>dfn[y];
				f2=par[f2];
			}
		}
		while(tp) 
		{
			if(t[tp]!=q[tail]) q[++tail]=t[tp];
			tp--;
		}
		
		for(int i=1;i<=tail;i++) 
		{
			int x=q[i];
			ans-=(ll)s[x]*(sqr(n-s[x])-f[x]-sqr(n-siz[x]));
			ans-=cal2(s[x]);
			ans-=cal3(s[x]);
		}
		for(int i=1;i<tail;i++)
		{
			int x=q[i],y=q[i+1];
			if(dfn[x]<dfn[y]&&dfn[x]+siz[x]>dfn[y])
				f[x]-=sqr(siz[y]);
			else f[y]-=sqr(siz[x]);
		}
		int top=q[1];
		for(int i=2;i<=tail;i++) if(dep[q[i]]<dep[top]) top=q[i];
		for(int i=1;i<=tail;i++) if(q[i]!=top)
			fa[q[i]]=top,s[top]+=s[q[i]],f[top]+=f[q[i]];
		
		ans+=(ll)s[top]*(sqr(n-s[top])-f[top]-sqr(n-siz[top]));
		ans+=cal2(s[top]);
		ans+=cal3(s[top]);
		printf("%lld\n",ans);
	}
	
	return 0;
}