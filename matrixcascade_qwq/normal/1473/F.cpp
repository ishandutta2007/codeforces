//Author : MatrixCascade

#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define clr(f, n) memset(f, 0, sizeof(int) * (n))
#define cpy(f, g, n) memcpy(f, g, sizeof(int) * (n))
#define rev(f, n) reverse(f, f + n)
#define pir pair<int, int>
#define mkp make_pair
#define fst it->first
#define sec it->second
#define int long long
#define up(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define down(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
using namespace std;
int n, m, k;
int read()
{
    int s = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * f;
}
inline void print(int *f, int len)
{
    for (int i = 0; i < len; i++)
        printf("%lld ", f[i]);
    puts("");
}
int s,t;
const int maxn=8e4+10;
int head[maxn],to[maxn],nxt[maxn],w[maxn],tot=1;
int dep[maxn];
int cur[maxn];
const int inf=1<<30;
void addd(int a,int b,int c)
{
	to[++tot]=b;
	w[tot]=c;
	nxt[tot]=head[a];
	head[a]=tot;
}
void add(int a,int b,int c)
{
	addd(a,b,c);
	addd(b,a,0);
}
bool bfs()
{
	memset(dep,0,sizeof(dep));
	queue<int>q;
	cur[s]=head[s];
	q.push(s);
	dep[s]=1;
	while(!q.empty())
	{
		int x=q.front();q.pop();
		for(int i=head[x];i;i=nxt[i])
		{
			int v=to[i];
			if(w[i]&&!dep[v])
			{
				q.push(v);
				dep[v]=dep[x]+1;
				cur[v]=head[v];
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
int dinic(int x,int flow)
{
	if(x==t)return flow;
	int rst=flow;
	int fl;
	for(int i=cur[x];i&&rst;i=nxt[i])
	{
		cur[x]=i;
		int v=to[i];
		if(w[i]&&dep[v]==dep[x]+1)
		{
			fl=dinic(v,min(rst,w[i]));
			if(!fl)dep[v]=0;
			w[i]-=fl;w[i^1]+=fl;
			rst-=fl;
		}
	}
	return flow-rst;
}
int solve()
{
	int flow=0,maxflow=0;
	while(bfs())
	{
		while(flow=dinic(s,inf))maxflow+=flow;
	}
	return maxflow;
}
int a[3030],b[3030];
int pre[202];
signed main()
{
	n=read();
	up(i,1,n)
	{
		a[i]=read();
	}
	up(i,1,n)
	{
		b[i]=read();
	}
	s=0,t=n+1;
	int sum=0;
	up(i,1,n)
	{
		if(b[i]>0)
		{
			sum+=b[i];
			add(s,i,b[i]);
		}
		else if(b[i]<0)
		{
			add(i,t,-b[i]);
		}
		up(j,1,a[i])
		{
			if(a[i]%j==0&&pre[j])add(i,pre[j],inf);
		}
		pre[a[i]]=i;
	}
	cout<<sum-solve();
}