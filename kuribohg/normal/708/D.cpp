#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define next next2
using namespace std;
const int MAXN=100010;
const int MAXM=1000010;
const int INF=1000000000;
int n,m,ans,d[MAXN],S,T,N;
int head[MAXN],from[MAXN],to[MAXM],next[MAXM],w[MAXM],c[MAXM],cnt=1;
inline void adde(int f,int t,int ww,int cc)
{
    cnt++,to[cnt]=t,from[cnt]=f,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww,c[cnt]=cc;
    cnt++,to[cnt]=f,from[cnt]=t,next[cnt]=head[t],head[t]=cnt,w[cnt]=0,c[cnt]=-cc;
}
struct Edge
{
    int x,y,f,c;
}E[MAXM];
int flow,cost;
int dis[MAXN],p[MAXN];
int q[MAXN],l,r;
bool used[MAXN];
bool SPFA()
{
    for(int i=1;i<=N;i++) dis[i]=INF;
    q[l=0]=S,r=1,dis[S]=0,used[S]=true;
    while(l!=r)
    {
        int x=q[l++];if(l==MAXN) l=0;
        used[x]=false;
        for(int i=head[x];i;i=next[i])
            if(w[i]>0&&dis[to[i]]>dis[x]+c[i])
            {
                dis[to[i]]=dis[x]+c[i];
                p[to[i]]=i;
                if(!used[to[i]])
                {
                    used[to[i]]=true;
                    q[r++]=to[i];
                    if(r==MAXN) r=0;
                }
            }
    }
    return dis[T]!=INF;
}
void Augment()
{
    int f=INF;
    for(int i=p[T];i;i=p[from[i]])
        f=min(f,w[i]);
    flow+=f;
    for(int i=p[T];i;i=p[from[i]])
        w[i]-=f,w[i^1]+=f,cost+=c[i]*f;
}
void MCMF()
{
    while(SPFA())
        Augment();
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++) scanf("%d%d%d%d",&E[i].x,&E[i].y,&E[i].c,&E[i].f);
    for(int i=1;i<=m;i++)
    {
        d[E[i].x]-=E[i].f,d[E[i].y]+=E[i].f;
        if(E[i].f<=E[i].c)
        {
            adde(E[i].x,E[i].y,E[i].c-E[i].f,1);
            adde(E[i].x,E[i].y,INF,2);
            adde(E[i].y,E[i].x,E[i].f,1);
        }
        else
        {
            ans+=E[i].f-E[i].c;
            adde(E[i].x,E[i].y,INF,2);
            adde(E[i].y,E[i].x,E[i].f-E[i].c,0);
            adde(E[i].y,E[i].x,E[i].c,1);
        }
    }
    adde(n,1,INF,0);
    S=n+1,T=S+1,N=T;
    for(int i=1;i<=n;i++)
        if(d[i]<0) adde(i,T,-d[i],0);
        else adde(S,i,d[i],0);
    MCMF();
    printf("%d\n",ans+cost);
    return 0;
}