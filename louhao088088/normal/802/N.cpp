// Problem: CF802N April Fools' Problem (medium)
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF802N
// Memory Limit: 250 MB
// Time Limit: 4000 ms
// 2022-03-13 20:26:40
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
#define int long long
const int maxn=2205+5,M=1e5,inf=1e15;
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
int n,k,x,y,z;
struct SSP
{
	int head[maxn],to[M],nex[M],w[M],c[M],cnt=1,dis[maxn],cur[maxn],vis[maxn],mincost,maxflow,s,t;
	void add(int x,int y,int z,int cost){
		//cout<<x<<" "<<y<<" "<<z<<endl;
		to[++cnt]=y,w[cnt]=z,c[cnt]=cost,nex[cnt]=head[x],head[x]=cnt;
	to[++cnt]=x,w[cnt]=0,c[cnt]=-cost,nex[cnt]=head[y],head[y]=cnt;}
	void clear(){memset(head,0,sizeof head),memset(cur,0,sizeof cur),cnt=1,maxflow=0,mincost=0;memset(vis,0,sizeof vis);}
	bool spfa()
	{
		memset(dis,0x3f,sizeof dis);memcpy(cur,head,sizeof head);
  		queue<int>q;q.push(s);dis[s]=0;vis[s]=1		;
		while(!q.empty())
		{
			int x=q.front();q.pop();vis[x]=0;
			for(int i=head[x];i;i=nex[i])
				if(dis[to[i]]>dis[x]+c[i]&&w[i])
				{
					dis[to[i]]=dis[x]+c[i];
					if(!vis[to[i]])q.push(to[i]),vis[to[i]]=1;
				}	
		}
		return dis[t]!=dis[0];
	}
	int dfs(int x,int flow)
	{
		if(x==t)return flow;
		int sum=0;vis[x]=1;
		for(int i=cur[x];i&&flow;i=nex[i])
		{
			cur[x]=i;
			if(!vis[to[i]]&&w[i]&&dis[to[i]]==dis[x]+c[i])
			{
				int k=dfs(to[i],min(flow,w[i]));
				flow-=k,sum+=k;w[i]-=k,w[i^1]+=k;mincost+=k*c[i];
			}
		}vis[x]=0;
		return sum;
	}
	void work()
	{
		while(spfa())maxflow+=dfs(s,inf);
	}
}G;
signed main()
{
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	n=read(),k=read();int s,t,s1,t1;s=G.s=n+3,G.t=t=s+1;s1=s-2,t1=s-1;
	for(int i=1;i<=n;i++)
		x=read(),G.add(s1,i,1,x);
	for(int i=1;i<=n;i++)
		x=read(),G.add(i,t1,1,x),G.add(i,i+1,1e6,0);
	G.add(s,s1,k,0),G.add(t1,t,k,0);
	G.work();
	cout<<G.mincost;
 	return 0;
}