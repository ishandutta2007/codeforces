#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,m;

struct rect
{
    int x1,y1,x2,y2;
};
rect inp[nmax];

struct info
{
    int pos=1,le[nmax],ri[nmax];
};
info tree[2];

void note(int node,int l,int r,int lq,int rq,int id)
{
    if(l==lq&&r==rq)
    {
        //cout<<id<<" "<<node<<" -> "<<l<<" "<<r<<endl;
        return;
    }

    int av=(l+r)/2;

    if(tree[id].le[node]==0)
    {
    tree[id].pos++;
    tree[id].le[node]=tree[id].pos;
    }

    if(tree[id].ri[node]==0)
    {
    tree[id].pos++;
    tree[id].ri[node]=tree[id].pos;
    }

    if(lq<=av)
    {
        note(tree[id].le[node],l,av,lq,min(av,rq),id);
    }

    if(av<rq)
    {
        note(tree[id].ri[node],av+1,r,max(lq,av+1),rq,id);
    }

    //cout<<id<<" "<<node<<" -> "<<l<<" "<<r<<" "<<tree[id].le[node]<<" "<<tree[id].ri[node]<<endl;
}









//https://github.com/radoslav11/Coding-Library/blob/master/graph/maxflow.cpp


const int MAXN = (1 << 20);

template<class FlowT>
struct max_flow
{
    const static FlowT finf = 1e18 + 42 + 17;
    const static FlowT feps = 0;

    struct edge
    {
        FlowT flow, cap;
        int idx, rev, to;
        edge() { flow = 0; cap = 0; rev = 0; idx = 0; to = 0; }
        edge(int _to, int _rev, FlowT _flow, FlowT _cap, int _idx)
        {
            to = _to; rev = _rev;
            flow = _flow; cap = _cap;
            idx = _idx;
        }
    };

    vector<edge> G[MAXN];
    int n, dist[MAXN], po[MAXN];

    bool bfs(int s, int t)
    {
        dist[s] = -1, po[s] = 0;
        dist[t] = -1, po[t] = 0;
        for(int v = 0; v <= n; v++)
            dist[v] = -1, po[v] = 0;

        queue<int> Q;
        Q.push(s);
        dist[s] = 0;

        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();

            for(edge e: G[u])
                if(dist[e.to] == -1 && e.flow < e.cap)
                {
                    dist[e.to] = dist[u] + 1;
                    Q.push(e.to);
                }
        }

        return dist[t] != -1;
    }

    FlowT dfs(int u, int t, FlowT fl = finf)
    {
        if(u == t)
            return fl;

        for(; po[u] < G[u].size(); po[u]++)
        {
            auto &e = G[u][po[u]];
            if(dist[e.to] == dist[u] + 1 && e.flow < e.cap)
            {
                FlowT f = dfs(e.to, t, min(fl, e.cap - e.flow));

                e.flow += f;
                G[e.to][e.rev].flow -= f;

                if(f > 0)
                    return f;
            }
        }

        return 0;
    }

    void init(int _n) { n = _n; for(int i = 0; i <= n; i++) G[i].clear(); }

    void add_edge(int u, int v, FlowT w, int idx = -1)
    {
        //cout<<"add edge "<<u<<" "<<v<<" "<<w<<endl;

        G[u].push_back(edge(v, G[v].size(), 0, w, idx));
        G[v].push_back(edge(u, G[u].size() - 1, 0, 0, -1));
    }

    FlowT flow(int s, int t)
    {
        if(s == t) return finf;

        FlowT ret = 0, to_add;
        while(bfs(s, t))
            while((to_add = dfs(s, t)))
                ret += to_add;

        return ret;
    }
};


max_flow<long long> f;

void build_0(int node,int l,int r)
{
    //cout<<"0 "<<node<<" "<<l<<" "<<r<<endl;
    if(tree[0].le[node]==0||l==r)
    {
        f.add_edge(0,node,r-l+1);
        return;
    }

    int av=(l+r)/2;
    build_0(tree[0].le[node],l,av);
    build_0(tree[0].ri[node],av+1,r);

    f.add_edge(tree[0].le[node],node,(av-l+1));
    f.add_edge(tree[0].ri[node],node,(r-av-1+1));
}

int add=0,sink;
void build_1(int node,int l,int r)
{
    //cout<<"1 "<<node+add<<" "<<l<<" "<<r<<endl;
    if(tree[1].le[node]==0||l==r)
    {
        f.add_edge(node+add,sink,r-l+1);
        return;
    }

    int av=(l+r)/2;
    build_1(tree[1].le[node],l,av);
    build_1(tree[1].ri[node],av+1,r);

    f.add_edge(node+add,tree[1].le[node]+add,(av-l+1));
    f.add_edge(node+add,tree[1].ri[node]+add,(r-av-1+1));
}

map< pair<int,int>,int> seen;
void make_path(int node,int l,int r,int lq,int rq,int other,int sz)
{
    if(l==lq&&r==rq)
    {
        if(seen.count({other,node})==0)
        {
            f.add_edge(other,node+add,sz);
            seen[{other,node}]=1;
        }
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)make_path(tree[1].le[node],l,av,lq,min(av,rq),other,sz);
    if(av<rq)make_path(tree[1].ri[node],av+1,r,max(av+1,lq),rq,other,sz);
}
void update(int node,int l,int r,int lq,int rq,int lq_other,int rq_other)
{
    if(l==lq&&r==rq)
    {
        make_path(1,1,n,lq_other,rq_other,node,r-l+1);
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)update(tree[0].le[node],l,av,lq,min(av,rq),lq_other,rq_other);
    if(av<rq)update(tree[0].ri[node],av+1,r,max(av+1,lq),rq,lq_other,rq_other);
}
int main()
{
    scanf("%i%i",&n,&m);
    int x1,y1,x2,y2;
    for(int i=1;i<=m;i++)
    {
        scanf("%i%i%i%i",&inp[i].x1,&inp[i].y1,&inp[i].x2,&inp[i].y2);
        note(1,1,n,inp[i].x1,inp[i].x2,0);
        note(1,1,n,inp[i].y1,inp[i].y2,1);
    }

    sink=tree[0].pos+tree[1].pos+1;

    f.init(sink+42);

    build_0(1,1,n);

    add=tree[0].pos;

    //cout<<tree[0].pos<<" "<<tree[1].pos<<endl;

    build_1(1,1,n);

    //cout<<"stop"<<endl;
    for(int i=1;i<=m;i++)
    {
        update(1,1,n,inp[i].x1,inp[i].x2,inp[i].y1,inp[i].y2);
        //cout<<"---"<<endl;
    }

    //cout<<"sink= "<<sink<<endl;

    printf("%i\n",f.flow(0,sink));
    return 0;
}