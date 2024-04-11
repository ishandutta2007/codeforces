#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
const int MAXN=400010;
int n,m,d[MAXN],f[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
LL ans;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,x,y;i<=m;i++) scanf("%d%d",&x,&y),d[x]++,d[y]++,adde(x,y);
    for(int x=1;x<=n;x++)
    {
        f[x]=1;
        for(int i=head[x];i;i=next[i])
            if(to[i]<x) f[x]=max(f[x],f[to[i]]+1);
    }
    for(int i=1;i<=n;i++) ans=max(ans,(LL)f[i]*d[i]);
    printf("%I64d\n",ans);
    return 0;
}