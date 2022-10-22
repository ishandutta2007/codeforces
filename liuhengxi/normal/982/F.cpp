#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define fail return puts("-1"),0;
using namespace std;
const int N=1e5+5,M=5e5+5;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int to,nex;
}e[M];
//mc=main cycle  mcl=main cycle length
//mc_0 -> mc_1 -> ... -> mc_mcl (-> mc_0)
int n,m,hd[N],cnt,sta[N],top,mc[N],mcl,val[N],mcpos[N],ans=-1,c[N];
bool ban[N],found,rec=true,vis[N],instk[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].nex=hd[u];
	hd[u]=cnt++;
}
void dfs1(int u)
{
	if(ban[u])return;
	if(found)return;
	if(instk[u])
	{
		sta[top++]=u;
		found=true;
		if(!rec)
		{
			top=0;
			return;
		}
		mc[mcl++]=sta[--top];
		while(sta[--top]!=u)mc[mcl++]=sta[top];
		top=0;
		F(i,0,mcl/2)mc[i]^=mc[mcl-1-i]^=mc[i]^=mc[mcl-1-i];
		return;
	}
	if(vis[u])return;
	sta[top++]=u;
	instk[u]=true;
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].nex)
	{
		int v=e[i].to;
		dfs1(v);
		if(found)return;
	}
	--top;
	instk[u]=false;
}
inline int dist(int a,int b){return mcpos[b]>mcpos[a]?
mcpos[b]-mcpos[a]:mcpos[b]-mcpos[a]+mcl;}
int dfs2(int u,int f)
/* find the farthest vertex on the main cycle from u
 * the vertex found will be wrong if and only if
 * there is v (not on the main cycle)
 * mc_a->v v->mc_b mc_c->v v->mc_d (a<b<c<d)
 * and there isn't answer
 */
{
	if(vis[u])return val[u];
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].nex)
	{
		int v=e[i].to;
		if(~mcpos[v])
		{
			if(!~val[u]||dist(f,val[u])<dist(f,v))val[u]=v;
		}
		else 
		{
			if(!~val[u]||(~dfs2(v,f)&&dist(f,val[u])<dist(f,dfs2(v,f))))
				val[u]=dfs2(v,f);
		}
	}
	return val[u];
}
int main()
{
	read(n);read(m);
	F(i,0,n)hd[i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);
	}
	F(i,0,n)if(!vis[i])dfs1(i);
	found=false;rec=false;
	F(i,0,mcl)ban[mc[i]]=true;
	F(i,0,n)vis[i]=instk[i]=false;
	F(i,0,n)if(!vis[i])dfs1(i);
	if(found)fail;
	F(i,0,n)mcpos[i]=-1;
	F(i,0,mcl)mcpos[mc[i]]=i;
	F(i,0,n)vis[i]=false,val[i]=-1;
	F(i,0,mcl)
	{
		int y=mcpos[dfs2(mc[i],mc[i])],x=i+1;
		if(y==i)
		{
			ans=mc[i];
			break;
		}
		y=(mcl-1+y)%mcl+1;
		++c[x];--c[y];
		if(y<x)++c[0];
	}
	if(!~ans)
	{
		F(i,1,mcl)c[i]+=c[i-1];
		F(i,0,mcl)if(c[i]==0){ans=mc[i];break;}
	}
	F(i,0,n)ban[i]=i==ans,vis[i]=instk[i]=false;
	F(i,0,n)if(!vis[i])dfs1(i);
	if(found)fail;
	printf("%d\n",ans+1);
	return 0;
}