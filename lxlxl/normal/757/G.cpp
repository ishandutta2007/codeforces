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
#define pb push_back
using namespace std;

inline void read(int &x)
{
	char c; while(!((c=getchar())>='0'&&c<='9'));
	x=c-'0';
	while((c=getchar())>='0'&&c<='9') (x*=10)+=c-'0';
}
inline void up(int &a,const int &b){if(a<b)a=b;}
const int maxn = 410000;
const int maxd = 21;
const int maxp = maxn*30;

int Ln,n,m;
int per[maxn];
vector<int>V[maxn],Vc[maxn];
struct edge{int y,c,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y,const int c){a[++len]=(edge){y,c,fir[x]};fir[x]=len;}

void buildedge(const int x,const int fa)
{
	int od=(int)V[x].size()-(fa>0);
	int las=x,i=0;
	for(int j=0;j<(int)V[x].size();j++) if(V[x][j]!=fa)
	{
		int y=V[x][j],c=Vc[x][j];
		if(i&&i+1!=od) ins(las,n+1,0),ins(n+1,las,0),las=++n;
		i++;
		ins(las,y,c); ins(y,las,c);
	}
	for(int j=0;j<(int)V[x].size();j++) if(V[x][j]!=fa)
		buildedge(V[x][j],x);
}
struct Divide_And_Conquer
{
	int root;
	int dep[maxn],fa[maxn][maxd],son[maxn][3];
	int siz[maxn],nowrt;
	void fr(int x,int Fa,const int Siz)
	{
		siz[x]=1; int mxs=0;
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(!dep[y]&&y!=Fa)
		{
			fr(y,x,Siz);
			siz[x]+=siz[y];
			up(mxs,siz[y]);
		}
		if(mxs*2<=Siz&&(Siz-siz[x])*2<=Siz) nowrt=x;
	}
	ll dis[maxd][maxn],Dis[maxn]; int nowdep;
	void dfs(const int x,const int Fa)
	{
		fa[x][nowdep]=nowrt;
		siz[x]=1;
		dis[nowdep][x]=Dis[x];
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(!dep[y]&&y!=Fa)
		{
			Dis[y]=Dis[x]+a[k].c;
			dfs(y,x);
			siz[x]+=siz[y];
		}
	}
	void Divide(int &loc,int x,int Fa,int Siz)
	{
		fr(x,Fa,Siz); x=nowrt;
		
		nowdep=dep[x]=dep[Fa]+1; loc=x;
		Dis[x]=0; dfs(x,Fa);
		
		int l=0;
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y) if(!dep[y])
			Divide(son[x][l++],y,x,siz[y]);
	}
	struct node
	{
		int siz;
		ll dis[3];
		int son[3];
	}p[maxp]; int cnt,rtc[maxn];
	void upd(int &x,int lx,int u,int addp)
	{
		p[x=++cnt]=p[lx]; p[x].siz++;
		if(u==addp) return;
		int d=dep[u];
		int l;for(int i=0;i<3;i++) if(fa[addp][d+1]==son[u][i]) { l=i;break; }
		p[x].dis[l]+=dis[d][addp];
		upd(p[x].son[l],p[lx].son[l],son[u][l],addp);
	}
	void Build()
	{
		memset(dep,0,sizeof dep);
		Divide(root,1,0,n);
		cnt=0;
		for(int i=1;i<=Ln;i++) upd(rtc[i],rtc[i-1],root,per[i]);
	}
	void Swap(int i)
	{
		swap(per[i],per[i+1]);
		upd(rtc[i],rtc[i-1],root,per[i]);
		upd(rtc[i+1],rtc[i],root,per[i+1]);
	}
	ll q(int x,int u,int qp)
	{
		if(u==qp) { return p[x].dis[0]+p[x].dis[1]+p[x].dis[2]; }
		int d=dep[u];
		int l;for(int i=0;i<3;i++) if(fa[qp][d+1]==son[u][i]) { l=i;break; }
		ll re=0;
		for(int i=0;i<3;i++) if(i!=l) re+=p[x].dis[i];
		re+=(ll)(p[x].siz-p[p[x].son[l]].siz)*dis[d][qp];
		return re+q(p[x].son[l],son[u][l],qp);
	}
	ll Query(int l,int r,int x) 
	{
		ll r1=q(rtc[r],root,x);
		ll r2=q(rtc[l-1],root,x);
		return r1-r2;
	}
}Tr;

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	read(n); read(m); Ln=n;
	for(int i=1;i<=n;i++) read(per[i]);
	for(int i=1;i<n;i++)
	{
		int x,y,c; read(x);read(y);read(c);
		V[x].pb(y); Vc[x].pb(c);
		V[y].pb(x); Vc[y].pb(c);
	}
	buildedge(1,0);
	Tr.Build();
	
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		ans&=(1<<30)-1;
		int op; read(op);
		if(op==1)
		{
			int l,r,v; read(l); read(r); read(v);
			l^=ans,r^=ans,v^=ans;
			ans=Tr.Query(l,r,v);
			printf("%lld\n",ans);
		}
		else
		{
			int l; read(l);
			l^=ans; Tr.Swap(l);
		}
	}
	
	return 0;
}