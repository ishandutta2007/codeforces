#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=200010;
LL p;
int n,k,dep[MAXN],L,R,mid;
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
void DFS(int x,int fa)
{
    for(int i=head[x];i;i=next[i])
        if(to[i]!=fa)
        {
            dep[to[i]]=dep[x]+1;
            DFS(to[i],x);
        }
}
bool Check()
{
    LL con=10000000000000000LL,d=0;
    for(int i=2;i<=mid+1;i++) d+=dep[i];
    con=min(con,(LL)dep[mid+1]*(LL)mid-d);
    for(int i=mid+2;i<=n;i++)
    {
        d-=dep[i-mid],d+=dep[i];
        con=min(con,(LL)dep[i]*(LL)mid-d);
    }
    return con<=p;
}
int main()
{
    scanf("%d%d%I64d",&n,&k,&p);
    for(int i=1,x,y;i<n;i++) scanf("%d%d",&x,&y),adde(x,y);
    DFS(1,-1);
    sort(dep+1,dep+n+1);
    L=1,R=min(n-1,k);
    while(L<R)
    {
        mid=(L+R+1)>>1;
        if(Check()) L=mid;
        else R=mid-1;
    }
    printf("%d\n",L);
    return 0;
}