#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=1000010;
const int INF=1000000000;
int n,m,x,y,S,T;
int head[MAXN],to[MAXN<<1],next[MAXN<<1],cnt=1;
int q[MAXN<<1],l=1000010,r=1000009;
int d[MAXN],ind[MAXN];
bool used[MAXN];
inline void adde(int f,int t)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt;
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d",&x,&y),adde(y,x),ind[x]++;
    scanf("%d%d",&S,&T);
    for(int i=1;i<=n;i++) d[i]=INF;
    d[T]=0,q[++r]=T;    
    while(l<=r)
    {
        int x=q[l++];
        if(used[x]) continue;
        used[x]=true;
        for(int i=head[x];i;i=next[i])
        {
            ind[to[i]]--;
            if(ind[to[i]]==0)
            {
                if(d[to[i]]>d[x])
                    d[to[i]]=d[x],q[--l]=to[i];
            }
            else
            {
                if(d[to[i]]>d[x]+1)
                    d[to[i]]=d[x]+1,q[++r]=to[i];
            }
        }
    }
    if(d[S]==INF) d[S]=-1;
    printf("%d\n",d[S]);
    return 0;
}