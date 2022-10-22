#include<iostream>
#include<cstdio>
#include<queue>
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
}a[2000004];
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
int ss[100005],aa[100005];
int bu[100005],bv[100005];
int zs[100005];
int rd[100005];
int main()
{
    int m,x,y,z;
    n=read();
    m=read();
    s=n+2;
    t=n+3;
    for(int i=1;i<=n;i++)ss[i]=read();
    for(int i=1;i<=n;i++)aa[i]=read();
    for(int i=1;i<=m;i++)
    {
    	x=read();
    	y=read();
        bu[i]=x;
        bv[i]=y;
        rd[x]++;
        rd[y]--;
        zs[x]++;
        zs[y]++;
        addb(x,y,1);
        addb(y,x,0); 
    }
    for(int i=1;i<=n;i++)
    {
    	if(ss[i]==1)
    	{
    		rd[i]-=aa[i];
    		rd[n+1]+=aa[i];
		}
		else
		{
			addb(n+1,i,zs[i]);
			addb(i,n+1,0);
			rd[i]-=zs[i];
			rd[n+1]+=zs[i];
		}
	}
	for(int i=1;i<=n+1;i++)
	{
		if(rd[i]%2!=0)
		{
			printf("NO\n");
			return 0;
		}
	}
	int het=0;
	for(int i=1;i<=n+1;i++)
	{
		if(rd[i]>0)addb(s,i,rd[i]/2),addb(i,s,0),het+=rd[i]/2;
		else addb(i,t,-rd[i]/2),addb(t,i,0);
	}
	//for(int i=1;i<=n;i++)printf("%d %d\n",rd[i],zs[i]);
	//for(int i=2;i<=tmp;i++)printf("%d %d %d\n",a[i].u,a[i].v,a[i].w);
    int ans=0;
    while(bfs())
    {
        for(int i=1;i<=t;i++)cur[i]=head[i];
        while(x=dfs(s,1000000000))ans+=x;
    }
    //printf("%d %d\n",ans,het);
    if(ans!=het)
    {
    	printf("NO\n");
    	return 0;
	}
	printf("YES\n");
	for(int i=1;i<=m;i++)
	{
		if(a[2*i].w==1)printf("%d %d\n",bv[i],bu[i]);
		else printf("%d %d\n",bu[i],bv[i]);
	}
}