#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
typedef long long LL;
const int MAXN=1000010;
const LL INF=100000000;
int n,d[MAXN],flag[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt;
LL f[MAXN][2];
int add_edge(int i,int j)
{
    ++cnt,to[cnt]=j,next[cnt]=head[i],head[i]=cnt;
    ++cnt,to[cnt]=i,next[cnt]=head[j],head[j]=cnt;
}
void dfs(int x,int fa)
{
    f[x][0]=-1;
    f[x][1]=INF-d[x];
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            dfs(to[i],x);
            f[x][0]+=max(f[to[i]][0],f[to[i]][1]);
            f[x][1]+=f[to[i]][0];
        }
}
void find_answer(int x,int fa,int v)
{
    flag[x]=v;
    if(v==0)
    {
        for(int i=head[x];i;i=next[i])
            if(to[i]!=fa)
            {
                if(f[to[i]][0]>f[to[i]][1]) find_answer(to[i],x,0);
                else find_answer(to[i],x,1);
            }
    }
    else
    {
        for(int i=head[x];i;i=next[i])
            if(to[i]!=fa) find_answer(to[i],x,0);
    }
}
int main()
{
    scanf("%d",&n);
    if(n==2)
    {
        puts("2 2");
        puts("1 1");
        return 0;
    }
    for(int i=1;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        d[x]++,d[y]++;
    }
    dfs(1,0);
    LL ans=0;
    if(f[1][0]>f[1][1])
    {
        ans=f[1][0];
        find_answer(1,0,0);
    }
    else
    {
        ans=f[1][1];
        find_answer(1,0,1);
    }
    LL points=(ans+(INF-1))/INF;
    printf("%I64d %I64d\n",points,points*INF-ans);
    for(int i=1;i<=n;i++)
    {
        if(flag[i]==0) printf("1 ");
        else printf("%d ",d[i]);
    }
    puts("");
    return 0;
}