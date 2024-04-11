#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
const int MAXN=1000010;
const int MAXM=10000010;
const int INF=1000000000;
int S,T,d[MAXN];
int q[MAXN],l,r;
int head[MAXN],to[MAXM],w[MAXM],next[MAXM],cnt=1;
inline void adde(int f,int t,int ww)
{
    cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
    cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=0;
}
bool BFS()
{
    for(int i=1;i<=T;i++) d[i]=-1;
    q[l=r=1]=S,d[S]=0;
    while(l<=r)
    {
        int x=q[l++];
        for(int i=head[x];i;i=next[i])
            if(w[i]>0&&d[to[i]]==-1) d[to[i]]=d[x]+1,q[++r]=to[i];
    }
    return d[T]!=-1;
}
int DFS(int x,int a)
{
    if(x==T) return a;
    int flow=a,f;
    for(int i=head[x];i;i=next[i])
        if(w[i]>0&&d[to[i]]==d[x]+1)
        {
            f=DFS(to[i],min(w[i],a));
            w[i]-=f,w[i^1]+=f,a-=f;
            if(a<=0) return flow;
        }
    if(a!=0) d[x]=-1;
    return flow-a;
}
int Dinic()
{
    int flow=0,f;
    while(BFS())
        while((f=DFS(S,INF))!=0)
            flow+=f;
    return flow;
}
int n,m,a[MAXN],X[MAXN],Y[MAXN],f[32010][110],p[MAXN],ans;
bool used[MAXN];
void factor(int n,int sub)
{
    int nn=n;
    for(int i=2;i*i<=nn;i++)
        if(n%i==0)
        {
            n/=i,f[i][sub]++;
            while(n%i==0) n/=i,f[i][sub]++;
        }
    if(n>1)
    {
        if(n<=32000) f[n][sub]++;
        else p[sub]=n;
    }
}
bool is_prime(int n)
{
    for(int i=2;i*i<=n;i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    S=n+1,T=S+1;
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    for(int i=1;i<=n;i++) factor(a[i],i);
    for(int i=1;i<=m;i++) scanf("%d%d",&X[i],&Y[i]);
    for(int i=1;i<=m;i++) if(X[i]%2==0) swap(X[i],Y[i]);
    for(int K=2;K<=32000;K++)
        if(is_prime(K))
        {
            for(int i=1;i<=T;i++) head[i]=0;
            cnt=1;
            for(int i=1;i<=n;i++)
                if(i%2==1) adde(S,i,f[K][i]);
                else adde(i,T,f[K][i]);
            for(int i=1;i<=m;i++) adde(X[i],Y[i],INF);
            ans+=Dinic();
        }
    for(int K=1;K<=n;K++)
        if(!used[K]&&p[K])
        {
            for(int i=1;i<=T;i++) head[i]=0;
            cnt=1;
            for(int i=1;i<=n;i++) if(p[i]==p[K]) used[i]=true;
            for(int i=1;i<=n;i++)
                if(p[i]==p[K])
                {
                    if(i%2==1) adde(S,i,1);
                    else adde(i,T,1);
                }
            for(int i=1;i<=m;i++) adde(X[i],Y[i],INF);
            ans+=Dinic();
        }
    printf("%d\n",ans);
    return 0;
}