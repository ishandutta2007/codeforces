#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
typedef long long LL;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
int n,m,male,female;
LL dis[1010][1010];
char map[30][30];
inline int Hash(int i,int j)
{
    return i*m+j+1;
}
inline bool valid(int i,int j)
{
    if(i>=n||i<0) return false;
    if(j>=m||j<0) return false;
    if(map[i][j]=='#') return false;
    return true;
}
const int MAXN=100010;
const int MAXM=1000010;
const int INF=1000000000;
const LL INFLL=1000000000000000000LL;
struct Graph
{
    int S,T,N;
    int head[MAXN],to[MAXM],next[MAXM],w[MAXM],cnt;
    inline void init()
    {
        for(int i=1;i<=N;i++)
            head[i]=0;
        cnt=1;
    }
    inline void adde(int f,int t,int ww)
    {
        cnt++,to[cnt]=t,next[cnt]=head[f],head[f]=cnt,w[cnt]=ww;
        cnt++,to[cnt]=f,next[cnt]=head[t],head[t]=cnt,w[cnt]=0;
    }
    int d[MAXN],q[MAXN],l,r;
    bool BFS()
    {
        for(int i=1;i<=N;i++) d[i]=-1;
        q[l=r=1]=S,d[S]=1;
        while(l<=r)
        {
            int x=q[l++];
            for(int i=head[x];i;i=next[i])
                if(w[i]>0&&d[to[i]]==-1) d[to[i]]=d[x]+1,q[++r]=to[i];
        }
        return d[T]!=-1;
    }
    int cur[MAXN];
    int DFS(int x,int a)
    {
        if(x==T) return a;
        int flow=a,f;
        for(int i=cur[x];i;i=next[i])
            if(d[to[i]]==d[x]+1&&w[i]>0)
            {
                f=DFS(to[i],min(w[i],a));
                w[i]-=f,w[i^1]+=f,a-=f;
                if(w[i]>0) cur[x]=i;
                if(a<=0) return flow;
            }
        if(a!=0) d[x]=-1;
        return flow-a;
    }
    int Dinic()
    {
        int flow=0,f;
        while(BFS())
        {
            for(int i=1;i<=N;i++) cur[i]=head[i];
            while((f=DFS(S,INF))!=0)
                flow+=f;
        }
        return flow;
    }
}G;
LL L,R;
struct Node
{
    int x,y,t;
    Node(){}
    Node(int _x,int _y,int _t):x(_x),y(_y),t(_t){}
};
int _x,_y,_t;
vector<Node> males,females;
Node boss;
int main()
{
    scanf("%d%d%d%d",&n,&m,&male,&female);
    for(int i=0;i<n;i++) scanf("%s",map[i]);
    for(int i=1;i<=n*m;i++)
        for(int j=1;j<=n*m;j++)
            if(i!=j) dis[i][j]=INFLL;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            for(int k=0;k<4;k++)
                if(valid(i,j)&&valid(i+dx[k],j+dy[k]))
                    dis[Hash(i,j)][Hash(i+dx[k],j+dy[k])]=dis[Hash(i+dx[k],j+dy[k])][Hash(i,j)]=1;
    for(int k=1;k<=n*m;k++)
        for(int i=1;i<=n*m;i++)
            for(int j=1;j<=n*m;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    scanf("%d%d%d",&_x,&_y,&_t);
    boss=Node(_x-1,_y-1,_t);
    for(int i=1;i<=male;i++)
    {
        scanf("%d%d%d",&_x,&_y,&_t);
        males.push_back(Node(_x-1,_y-1,_t));
    }
    for(int i=1;i<=female;i++)
    {
        scanf("%d%d%d",&_x,&_y,&_t);
        females.push_back(Node(_x-1,_y-1,_t));
    }
    R=10000000000000000LL;
    if(male==female-1) males.push_back(boss),male++;
    else if(female==male-1) females.push_back(boss),female++;
    else {puts("-1");return 0;}
    while(L<R)
    {
        LL mid=(L+R)>>1;
        G.N=n*m+n*m+male+female+1+2;
        G.init();
        G.S=G.N-1,G.T=G.N;
        for(int i=0;i<male;i++)
            for(int x=0;x<n;x++)
                for(int y=0;y<m;y++)
                    if(dis[Hash(males[i].x,males[i].y)][Hash(x,y)]!=INFLL&&(LL)dis[Hash(males[i].x,males[i].y)][Hash(x,y)]*males[i].t<=mid)
                        G.adde(n*m+n*m+i+1,Hash(x,y),1);
        for(int i=0;i<female;i++)
            for(int x=0;x<n;x++)
                for(int y=0;y<m;y++)
                    if(dis[Hash(females[i].x,females[i].y)][Hash(x,y)]!=INFLL&&(LL)dis[Hash(females[i].x,females[i].y)][Hash(x,y)]*females[i].t<=mid)
                        G.adde(n*m+Hash(x,y),n*m+n*m+male+i+1,1);
        for(int i=1;i<=n*m;i++) G.adde(i,n*m+i,1);
        for(int i=0;i<male;i++) G.adde(G.S,n*m+n*m+i+1,1);
        for(int i=0;i<female;i++) G.adde(n*m+n*m+male+i+1,G.T,1);
        int res=G.Dinic();
        if(res==male) R=mid;
        else L=mid+1;
    }
    if(L==10000000000000000LL) puts("-1");
    else printf("%I64d\n",L);
    return 0;
}