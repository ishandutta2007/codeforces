#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ls tr[rt].lon
#define rs tr[rt].ron
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
const int maxn=400005;
struct edge
{
	int v,w,nex;
}e[maxn*10];
struct tree
{
	int lon,ron;
}tr[maxn*8];
struct node
{
	int id,num;
	bool operator < (const node & a)const{return a.num<num;}
};
int n,tot=0,x,y,ans=0,t,cnt=0,head[maxn*4],dis[maxn*4],id[maxn*4],id2[maxn*4],rt1,rt2,k,z,L,R,m,s;
void add(int u,int v,int w)
{
	e[++cnt].v=v,e[cnt].w=w,e[cnt].nex=head[u],head[u]=cnt;
}
void build1(int &rt,int l,int r)
{
	if(!rt)rt=++tot;
	if(l==r){id[l]=rt;return;}
	int mid=l+r>>1;
	build1(ls,l,mid),build1(rs,mid+1,r);
	add(rt,ls,0);add(rt,rs,0);
}
void build2(int &rt,int l,int r)
{
	if(!rt)rt=++tot;
	if(l==r){add(id[l],rt,0),add(rt,id[l],0);id2[l]=rt;return;}
	int mid=l+r>>1;
	build2(ls,l,mid),build2(rs,mid+1,r);
	add(ls,rt,0);add(rs,rt,0);
}
void find1(int rt,int l,int r,int L,int R,int x,int z)
{
	if(r<L||l>R)return;
	else if(l>=L&&r<=R){add(id2[x],rt,z);return;}
	int mid=l+r>>1;
	find1(ls,l,mid,L,R,x,z);find1(rs,mid+1,r,L,R,x,z);
}
void find2(int rt,int l,int r,int L,int R,int x,int z)
{
	if(r<L||l>R)return;
	else if(l>=L&&r<=R){add(rt,id[x],z);return;}
	int mid=l+r>>1;
	find2(ls,l,mid,L,R,x,z);find2(rs,mid+1,r,L,R,x,z);
}
void dij(int x)
{
	bool vis[maxn*4],F=0;
	priority_queue<node>q;
	node p;p.id=x,p.num=0;
	memset(dis,0x3f,sizeof dis);
	q.push(p);dis[x]=0;
	while(!q.empty())
	{
		node p=q.top();q.pop();
		int u=p.id;
		if(vis[u])continue;vis[u]=1;//cout<<u<<endl;
		for(int i=head[u];i;i=e[i].nex)
		{
			int v=e[i].v;
			if(dis[v]>dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				if(!vis[v])q.push((node){v,dis[v]});
			}
		}
	}
}
signed main()
{
	n=read();m=read(),s=read();build1(rt1,1,n),build2(rt2,1,n);
	for(int i=1;i<=m;i++)
	{
		k=read();
		if(k==1)
		{
			x=read(),y=read(),z=read();
			add(id[x],id[y],z);
		}
		else if(k==2)
		{
			x=read(),L=read(),R=read(),z=read();
			find1(rt1,1,n,L,R,x,z);
		}
		else 
		{
			x=read(),L=read(),R=read(),z=read();
			find2(rt2,1,n,L,R,x,z);
		}
	}
	dij(id[s]);
	for(int i=1;i<=n;i++)
	{
		if(dis[id[i]]==dis[0])printf("-1 ");
		else printf("%lld ",dis[id[i]]);
	}
	return 0;
}