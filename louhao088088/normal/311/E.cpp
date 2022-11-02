// Problem: CF311E Biologist
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF311E
// Memory Limit: 250 MB
// Time Limit: 1500 ms
// 2022-02-18 18:30:43
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
int n,m,g,a[maxn],v[maxn],ans=0,x,y,z,b,k;
struct Dinic
{
	int head[maxn*20],to[maxn*40],nex[maxn*40],w[maxn*40],cnt=1,dis[maxn*20],cur[maxn*20],vis[maxn*20],sum,maxflow,s,t;
	void add(int x,int y,int z){to[++cnt]=y,w[cnt]=z,nex[cnt]=head[x],head[x]=cnt;
	to[++cnt]=x,w[cnt]=0,nex[cnt]=head[y],head[y]=cnt;}
	void clear(){memset(head,0,sizeof head),memset(cur,0,sizeof cur),cnt=1,maxflow=0;memset(vis,0,sizeof vis);}
	bool bfs()
	{
		memset(dis,-1,sizeof dis);
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
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),m=read(),g=read();int s=G.s=n+m+1,t=G.t=n+m+2;G.cnt=1;
	for(int i=1;i<=n;i++)a[i]=read();
	for(int i=1;i<=n;i++){x=read();if(!a[i])G.add(s,i,x);else G.add(i,t,x);}
	for(int i=1;i<=m;i++)
	{
		x=read(),y=read();ans+=y;k=read();
		for(int j=1;j<=k;j++){b=read();if(!x)G.add(n+i,b,inf);else G.add(b,n+i,inf);}
		z=read();if(z)y+=g;if(!x)G.add(s,n+i,y);else G.add(n+i,t,y);
	}
	G.work();//cout<<G.maxflow<<endl;
	cout<<ans-G.maxflow;
 	return 0;
}