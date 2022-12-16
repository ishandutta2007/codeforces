#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<queue>

typedef long long LL;

const int N=100005;
const LL inf=(LL)1e15;

int n,m,r,b,w[N],h[N],sw[N],sh[N],s,t,S,T,ns,nt,last[N*2],dis[N*2],cur[N*2],cnt,num[N],mn[N*2],mx[N*2];
LL deg[N*2];
struct edge{int to,next;LL c;}e[N*30];
std::queue<int> que;
struct data{int x,y;}a[N];

void addedge(int u,int v,LL c)
{
    e[++cnt].to=v;e[cnt].c=c;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].c=0;e[cnt].next=last[v];last[v]=cnt;
}

bool bfs()
{
    for (int i=s;i<=T;i++) dis[i]=0;
    while (!que.empty()) que.pop();
    dis[ns]=1;que.push(ns);
    while (!que.empty())
    {
        int u=que.front();que.pop();
        for (int i=last[u];i;i=e[i].next)
            if (e[i].c&&!dis[e[i].to])
            {
                dis[e[i].to]=dis[u]+1;
                if (e[i].to==nt) return 1;
                que.push(e[i].to);
            }
    }
    return 0;
}

LL dfs(int x,LL maxf)
{
    if (x==nt||!maxf) return maxf;
    int ret=0;
    for (int &i=cur[x];i;i=e[i].next)
        if (e[i].c&&dis[e[i].to]==dis[x]+1)
        {
            LL f=dfs(e[i].to,std::min(e[i].c,maxf-ret));
            e[i].c-=f;
            e[i^1].c+=f;
            ret+=f;
            if (maxf==ret) break;
        }
    return ret;
}

LL dinic()
{
    LL ans=0;
    while (bfs())
    {
        for (int i=s;i<=T;i++) cur[i]=last[i];
        ans+=dfs(ns,inf);
    }
    return ans;
}

int main()
{
    scanf("%d%d",&n,&m);
    scanf("%d%d",&r,&b);cnt=1;
    for (int i=1;i<=n;i++) scanf("%d%d",&a[i].x,&a[i].y),w[i]=a[i].x,h[i]=a[i].y;
    std::sort(w+1,w+n+1);int w1=std::unique(w+1,w+n+1)-w-1;
    std::sort(h+1,h+n+1);int h1=std::unique(h+1,h+n+1)-h-1;
    s=0;t=w1+h1+1;
    for (int i=1;i<=n;i++)
    {
        int x=std::lower_bound(w+1,w+w1+1,a[i].x)-w;
        int y=std::lower_bound(h+1,h+h1+1,a[i].y)-h;
        sw[x]++;sh[y]++;addedge(x,y+w1,1);num[i]=cnt;
    }
    for (int i=1;i<=w1+h1;i++) mn[i]=n,mx[i]=0;
    for (int i=1;i<=m;i++)
    {
        int ty,l,d;scanf("%d%d%d",&ty,&l,&d);
        if (ty==1)
        {
            int p=std::lower_bound(w+1,w+w1+1,l)-w;
            if (w[p]!=l||d>=sw[p]) continue;
            int l1=(sw[p]-d+1)/2,l2=sw[p]-l1;
            if (l1>l2) {puts("-1");return 0;}
            mx[p]=std::max(mx[p],l1);mn[p]=std::min(mn[p],l2);
        }
        else
        {
            int p=std::lower_bound(h+1,h+h1+1,l)-h;
            if (h[p]!=l||d>=sh[p]) continue;
            int l1=(sh[p]-d+1)/2,l2=sh[p]-l1;
            if (l1>l2) {puts("-1");return 0;}
            mx[p+w1]=std::max(mx[p+w1],l1);mn[p+w1]=std::min(mn[p+w1],l2);
        }
    }
    for (int i=1;i<=w1;i++) deg[s]-=mx[i],deg[i]+=mx[i],addedge(s,i,std::min(sw[i],mn[i])-mx[i]);
    for (int i=w1+1;i<=w1+h1;i++) deg[t]+=mx[i],deg[i]-=mx[i],addedge(i,t,std::min(sh[i-w1],mn[i])-mx[i]);
    int tcnt=cnt;S=t+1;T=t+2;
    addedge(t,s,inf);LL sum=0;
    for (int i=s;i<=t;i++)
        if (deg[i]<0) addedge(i,T,-deg[i]);
        else if (deg[i]>0) addedge(S,i,deg[i]),sum+=deg[i];
    ns=S;nt=T;
    if (dinic()!=sum) {puts("-1");return 0;}
    for (int i=tcnt+1;i<=cnt;i++) e[i].c=0;
    ns=s;nt=t;dinic();
    LL ans=0;
    for (int i=1;i<=n;i++) ans+=e[num[i]].c?std::min(b,r):std::max(b,r);
    printf("%I64d\n",ans);
    for (int i=1;i<=n;i++)
        if (e[num[i]].c) putchar(r>b?'b':'r');
        else putchar(r>b?'r':'b');
    return 0;
}