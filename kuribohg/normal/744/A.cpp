#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=100010;
int n,m,k,x,y;
int c[MAXN],res[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int sz;
bool used[1010];
void DFS(int x)
{
    sz++;
    used[x]=true;
    for(int i=head[x];i;i=next[i])
        if(!used[to[i]]) DFS(to[i]);
}
int main()
{
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=k;i++) scanf("%d",&c[i]);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        adde(x,y);
    }
    for(int i=1;i<=k;i++) sz=0,DFS(c[i]),res[i]=sz;
    int o=0,sum=0;
    for(int i=1;i<=k;i++)
    {
        sum+=res[i];
        if(res[i]>res[o]) o=i;
    }
    res[o]+=n-sum;
    int ans=0;
    for(int i=1;i<=k;i++)
        ans+=res[i]*(res[i]-1)/2;
    printf("%d\n",ans-m);
    return 0;
}