#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef long long LL;
const int MAXN=1000010;
int n,size[MAXN],Q,sub,tar,fa[MAXN];
int head[MAXN],to[MAXN],next[MAXN],r[MAXN],cnt=1;
LL w[MAXN],f[MAXN],ans;
double con;
inline void adde(int f,int t,LL ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=ww;
}
void DFS(int x)
{
    size[x]=1;
    for(int i=head[x];i;i=next[i])
        if(fa[x]!=to[i])
        {
            fa[to[i]]=x,r[i]=to[i],r[i^1]=to[i];
            DFS(to[i]);
            size[x]+=size[to[i]];
            f[x]+=(LL)f[to[i]]+(LL)w[i]*(LL)size[to[i]];
        }
    for(int i=head[x];i;i=next[i])
        if(fa[x]!=to[i]) ans+=(LL)(size[x]-size[to[i]])*(LL)(f[to[i]]+(LL)w[i]*(LL)size[to[i]]);
}
int main()
{
    scanf("%d",&n);
    for(int i=1,x,y,z;i<n;i++) scanf("%d%d%d",&x,&y,&z),adde(x,y,(LL)z);
    DFS(1);
    con=6.0*ans/((LL)n*(n-1));
    scanf("%d",&Q);
    for(int i=1;i<=Q;i++)
    {
        scanf("%d%d",&sub,&tar);
        sub<<=1;
        ans-=(LL)size[r[sub]]*(LL)(n-size[r[sub]])*(LL)(w[sub]-tar);
        con=6.0*ans/((LL)n*(n-1));
        w[sub]=tar;
        printf("%.010lf\n",con);
    }
    return 0;
}