#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
int n,q[MAXN],l=1,r,ind[MAXN];
int head[MAXN],to[MAXN],next[MAXN],cnt;
int t[MAXN],tot,t2[MAXN],tot2;
bool used[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int main()
{
    scanf("%d",&n);
    for(int i=1,u,v;i<=n;i++)
    {
        scanf("%d%d",&u,&v);
        used[u]=true,used[v]=true;
        if(v!=0) adde(u,v),ind[v]++;
    }
    q[++r]=0,used[0]=false;
    while(l<=r)
    {
        int x=q[l++];
        if(x!=0) t[++tot]=x;
        for(int i=head[x];i;i=next[i])
        {
            ind[to[i]]--;
            if(ind[to[i]]==0&&used[to[i]]) q[++r]=to[i],used[to[i]]=false;
        }
    }
    l=1,r=0;
    for(int i=0;i<=1000000;i++)
        if(used[i]&&ind[i]==0) q[++r]=i;
    while(l<=r)
    {
        int x=q[l++];
        t2[++tot2]=x;
        for(int i=head[x];i;i=next[i])
        {
            ind[to[i]]--;
            if(ind[to[i]]==0&&used[to[i]]) q[++r]=to[i],used[to[i]]=false;
        }
    }
    for(int i=1;i<=tot;i++) printf("%d %d ",t2[i],t[i]);
    if(tot2>tot) printf("%d\n",t2[tot2]);
    return 0;
}