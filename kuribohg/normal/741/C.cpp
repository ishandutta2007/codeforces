#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=400010;
int n,x[MAXN],y[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt=1;
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt;
}
int ans[MAXN];
void DFS(int x)
{
    for(int i=head[x];i;i=next[i])
        if(!ans[to[i]])
        {
            ans[to[i]]=3-ans[x];
            DFS(to[i]);
        }
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) adde(i*2-1,i*2);
    for(int i=1;i<=n;i++) scanf("%d%d",&x[i],&y[i]),adde(x[i],y[i]);
    for(int i=1;i<=n+n;i++)
        if(!ans[i]) ans[i]=1,DFS(i);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",ans[x[i]],ans[y[i]]);
    return 0;
}