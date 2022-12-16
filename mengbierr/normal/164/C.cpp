#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
const int MAXM = 100000;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int to, next, cap, flow, cost;
    int id;
    int x, y;
} edge[MAXM],HH[MAXN],MM[MAXN];
int head[MAXN],tol;
int pre[MAXN],dis[MAXN];
bool vis[MAXN];
int N, M;
void init()
{
    N = MAXN;
    tol = 0;
    memset(head, -1, sizeof(head));
}
int addedge(int u, int v, int cap, int cost, int id)//
{
    edge[tol]. to = v;
    edge[tol]. cap = cap;
    edge[tol]. cost = cost;
    edge[tol]. flow = 0;
    edge[tol]. next = head[u];
    edge[tol]. id = id;
    int t = tol;
    head[u] = tol++;
    edge[tol]. to = u;
    edge[tol]. cap = 0;
    edge[tol]. cost = -cost;
    edge[tol]. flow = 0;
    edge[tol]. next = head[v];
    edge[tol]. id = id;
    head[v] = tol++;
    return tol;
}
bool spfa(int s, int t)
{
    queue<int>q;
    for(int i = 0; i < N; i++)
    {
        dis[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    dis[s] = 0;
    vis[s] = true;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = false;
        for(int i = head[u]; i != -1; i = edge[i]. next)
        {
            int v = edge[i]. to;
            if(edge[i]. cap > edge[i]. flow &&
                    dis[v] > dis[u] + edge[i]. cost )
            {
                dis[v] = dis[u] + edge[i]. cost;
                pre[v] = i;
                if(!vis[v])
                {
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    if(pre[t] == -1) return false;
    else return true;
}
// cost
int minCostMaxflow(int s, int t, int &cost)
{
    int flow = 0;
    cost = 0;
    while(spfa(s,t))
    {
        int Min = INF;
        for(int i = pre[t]; i != -1; i = pre[edge[i^1]. to])
        {
            if(Min > edge[i]. cap - edge[i]. flow)
                Min = edge[i]. cap - edge[i]. flow;
        }
        for(int i = pre[t]; i != -1; i = pre[edge[i^1]. to])
        {
            edge[i]. flow += Min;
            edge[i^1]. flow -= Min;
            cost += edge[i]. cost * Min;
        }
        flow += Min;
    }
    return flow;
}
struct node
{
    int st,et,ct;
    int id;
}task[MAXN];
bool cmp(node A,node B)
{
    if(A.st==B.st)return A.et<B.et;
    return A.st<B.st;
}
map<int,int> H;
vector<int> V;
int id[3000];
int main()
{
    int n, m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=1;i<=n;i++)
    {
        scanf("%d%d%d",&task[i].st,&task[i].et,&task[i].ct);
        task[i].et+=task[i].st-1;
        task[i].id=i;
        V.push_back(task[i].st);
        V.push_back(task[i].et);
    }

    sort(V.begin(),V.end());
    V.erase(unique(V.begin(),V.end()),V.end());

    for(int i=0;i<V.size();i++)
        H[V[i]]=i+1;
    for(int i=1;i<=V.size();i++)
        addedge(i-1,i,m,0,0);
    addedge(V.size(),V.size()+1,m,0,0);
    addedge(V.size()+1,V.size()+2,m,0,0);
    for(int i=1;i<=n;i++)
        id[i]=addedge(H[task[i].st],H[task[i].et]+1,1,-task[i].ct,i);
    int ans1=0,ans2=0;
    ans1=minCostMaxflow(0,V.size()+2,ans2);
    //printf("%d\n",ans2);
    for(int i=1;i<=n;i++)
        printf("%d ",edge[id[i]-2].flow);
    return 0;
}