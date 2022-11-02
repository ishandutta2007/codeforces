// Problem: CF793G Oleg and chess
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF793G
// Memory Limit: 250 MB
// Time Limit: 6500 ms
// 2022-02-14 11:30:23
// Author : louhao088
// 
// Powered by CP Editor (https://cpeditor.org)

#include<bits/stdc++.h>
using namespace std;
//static char buf[1000000],*p1=buf,*p2=buf;
//#define getchar() p1==p2&&(p2=(p1=buf)+fread(buf,1,1000000,stdin),p1==p2)?EOF:*p1++
#define pi pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ls (rt<<1)
#define rs (rt<<1|1)
#define mid (l+r>>1)
#define lowbit (x&-x)
const int maxn=1e5+5,M=34005,inf=1e9;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
inline void print(int x)
{
    static int a[55];int top=0;
    if(x<0) putchar('-'),x=-x;
    do{a[top++]=x%10,x/=10;}while(x);
    while(top) putchar(a[--top]+48);
}
int n,m,s,t,tot,tag[maxn*4],id[maxn*4],lx,ly,rx,ry;
struct node{int l,r,x;};
vector<node>a[maxn];
struct Dinic
{
	int head[maxn*20],to[maxn*40],nex[maxn*40],w[maxn*40],cnt=1,dis[maxn*20],cur[maxn*20],vis[maxn*20],sum,maxflow;
	void add(int x,int y,int z){to[++cnt]=y,w[cnt]=z,nex[cnt]=head[x],head[x]=cnt;
	to[++cnt]=x,w[cnt]=0,nex[cnt]=head[y],head[y]=cnt;}
	void clear(){memset(head,0,sizeof head),memset(cur,0,sizeof cur),cnt=1,maxflow=0;memset(vis,0,sizeof vis);}
	bool bfs()
	{
		for(int i=1;i<=tot;i++)dis[i]=-1;
		queue<int>q;q.push(s);cur[s]=head[s];dis[s]=0;		
		while(!q.empty())
		{
			int x=q.front();q.pop();
			for(int i=head[x];i;i=nex[i])
				if(dis[to[i]]==-1&&w[i])
					dis[to[i]]=dis[x]+1,q.push(to[i]),cur[to[i]]=head[to[i]];
		}
		return dis[t]!=-1;
	}
	int dfs(int x,int flow)
	{
		if(x==t)return flow;
		int sum=0;
		for(int i=cur[x];i&&flow;i=nex[i])
		{
			cur[x]=i;
			if(w[i]&&dis[to[i]]==dis[x]+1)
			{
				int k=dfs(to[i],min(flow,w[i]));
				flow-=k,sum+=k;w[i]-=k,w[i^1]+=k;
			}
		}return sum;
	}
	void work()
	{
		while(bfs())maxflow+=dfs(s,inf);
	}
}G;
void pushup(int rt)
{
	id[rt]=++tot;
	if(!tag[ls])G.add(id[rt],id[ls],inf);
	if(!tag[rs])G.add(id[rt],id[rs],inf);
}
void build(int rt,int l,int r)
{
	if(l==r){id[rt]=l+n;return;}
	build(ls,l,mid),build(rs,mid+1,r);
	pushup(rt);
}
void change(int rt,int l,int r,int L,int R,int x)
{
	//cout<<rt<<" "<<l<<" "<<r<<endl;
	if(l>R||r<L)return;
	if(l>=L&&r<=R){tag[rt]+=x;return;}
	change(ls,l,mid,L,R,x);change(rs,mid+1,r,L,R,x);
	pushup(rt);
}
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read();tot=2*n+2,s=2*n+1,t=2*n+2;G.cnt=1;
	for(int i=1;i<=m;i++)
	{
		lx=read(),ly=read();rx=read(),ry=read();
		a[lx].pb((node){ly,ry,1}),a[rx+1].pb((node){ly,ry,-1});
	}
	for(int i=1;i<=n;i++)G.add(s,i,1),G.add(i+n,t,1);
	build(1,1,n);
	for(int i=1;i<=n;i++)
	{
		for(auto j:a[i])
			change(1,1,n,j.l,j.r,j.x);
		if(!tag[1])G.add(i,id[1],inf);
	}//return 0;
	G.work();cout<<G.maxflow<<endl;
 	return 0;
}