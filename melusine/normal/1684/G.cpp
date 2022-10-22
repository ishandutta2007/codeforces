#include<iostream>
#include<cstdio>
#include<queue>
#define int long long
using namespace std;
inline int read()
{
    int n=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9')
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9')
    {
        n=n*10+ch-'0';
        ch=getchar();
    }
    return n*f;
}
struct bbian
{
    int u,v,w,nex;
}a[800004];
queue<int>que;
int head[100001],cur[100001],tmp=1;
int dep[100001],n;
int s,t,sth;
void addb(int x,int y,int z)
{
    a[++tmp].u=x;
    a[tmp].v=y;
    a[tmp].w=z;
    a[tmp].nex=head[x];
    head[x]=tmp;
}
bool bfs()
{
    for(int i=1;i<=t;i++)dep[i]=0;
    que.push(s);
    dep[s]=1;
    while(!que.empty())
    {
        sth=que.front();
        que.pop();
        for(int i=head[sth];i;i=a[i].nex)
        {
            if(dep[a[i].v]==0&&a[i].w>0)
            {
                dep[a[i].v]=dep[sth]+1;
                que.push(a[i].v);
            }
        }
    }
    if(dep[t]==0)return false;
    return true;
}
int dfs(int x,int f)
{
    if(x==t)return f;
    for(int& i=cur[x];i;i=a[i].nex)
    {
        if((dep[a[i].v]==dep[a[i].u]+1)&&a[i].w!=0)
        {
            int ff=dfs(a[i].v,min(f,a[i].w));
            if(ff>0)
            {
                a[i].w-=ff;
                a[i^1].w+=ff;
                return ff;
            }
        }
    }
    return 0;
}
int qz[100005];
int tid[100005];
signed main()
{
    int m,x,y,z;
    n=read();
    m=read();
    s=n+1;
    t=n+2;
    for(int i=1;i<=n;i++)
    {
    	qz[i]=read();
    	if(qz[i]<=m/3)
		{
			tid[i]=tmp+1; 
			addb(i,t,1);
			addb(t,i,0);
		}
    	else
		{
			tid[i]=tmp+1;
			addb(s,i,1);
			addb(i,s,0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(qz[i]>m/3&&qz[j]<=m/3&&qz[i]%qz[j]==0&&qz[i]*2+qz[j]<=m)
			{
				addb(i,j,1);
				addb(j,i,0);
			}
		}
	}
    int ans=0;
    while(bfs())
    {
        for(int i=1;i<=t;i++)cur[i]=head[i];
        while(x=dfs(s,1000000000))ans+=x;
    }
    for(int i=1;i<=n;i++)
    {
    	if(qz[i]<=m/3)continue;
    	if(a[tid[i]].w!=0)
    	{
    		printf("-1\n");
    		return 0;
		}
	}
	int cnt=0;
	for(int i=2;i<=tmp;i+=2)
	{
		if(a[i].u>n||a[i].v>n)continue;
		if(a[i].w>0)continue;
		cnt++;
	}
	for(int i=1;i<=n;i++)
	{
		if(a[tid[i]].w!=0)cnt++;
	}
	printf("%lld\n",cnt);
	for(int i=2;i<=tmp;i+=2)
	{
		if(a[i].u>n||a[i].v>n)continue;
		if(a[i].w>0)continue;
		printf("%lld %lld\n",2*qz[a[i].u]+qz[a[i].v],qz[a[i].u]+qz[a[i].v]);
	}
	for(int i=1;i<=n;i++)
	{
		if(a[tid[i]].w!=0)printf("%lld %lld\n",3*qz[i],2*qz[i]);
	}
	return 0;
}