#include<bits/stdc++.h>
using namespace std;
const int nmax=2e4+42,mmax=1e5+42;
struct edge
{
    int to,cap,id_back;
};
vector< edge > graph[nmax];

void add_edge(int from,int to,int cap)
{
    //cout<<from<<" "<<to<<" "<<cap<<endl;

    edge now,back_;
    now.to=to;
    now.cap=cap;
    now.id_back=graph[to].size();

    back_.to=from;
    back_.cap=0;
    back_.id_back=graph[from].size();

    graph[from].push_back(now);
    graph[to].push_back(back_);
}

int n,m;

pair< int/*from*/,pair<int/*to*/,int/*cost*/> > inp[mmax];

int sink,MX;

int dist[nmax];

queue< pair<int/*where*/,int/*dist*/> > qqq;
bool bfs(int from,int to)
{
    for(int i=0;i<=MX;i++)
        dist[i]=-1;

    qqq.push({to,0});

    while(qqq.size())
    {
        pair<int/*where*/,int/*dist*/> now=qqq.front();
        qqq.pop();

        if(dist[now.first]!=-1)continue;
        dist[now.first]=now.second;

        for(auto k:graph[now.first])
        {
            edge back_=graph[k.to][k.id_back];

            //cout<<back_.to<<" "<<back_.cap<<" "<<back_.id_back<<endl;

            if(back_.cap)
            qqq.push({k.to,now.second+1});
        }
    }

    //for(int i=0;i<=MX;i++)cout<<dist[i]<<" ";cout<<endl;

    return dist[from]!=-1;
}

bool been[nmax];

int id[nmax];

int dfs(int where,int aim,int flow)
{
    if(been[where])return 0;
    been[where]=1;
    if(where==aim)return flow;
    for(;id[where]<graph[where].size();id[where]++)
    {
        auto &k=graph[where][id[where]];
        if(dist[k.to]==dist[where]-1&&k.cap)
        {
            int now=dfs(k.to,aim,min(flow,k.cap));

            k.cap-=now;
            graph[k.to][k.id_back].cap+=now;

            if(now)return now;
        }
    }
    return 0;
}

int max_flow(int from,int to)
{
    int ret=0;

    while(bfs(from,to))
    {
        memset(id,0,sizeof(id));

        memset(been,0,sizeof(been));
        int now=dfs(from,to,1e9);
        while(now)
        {
            ret=ret+now;
            //cout<<"now= "<<now<<endl;
            memset(been,0,sizeof(been));
            now=dfs(from,to,1e9);
        }
        //cout<<"ret= "<<ret<<endl;
    }
    return ret;
}

bool test(int mx)
{
    for(int i=0;i<=2*n+1;i++)
        graph[i]={};

    for(int i=1;i<=n;i++)
    {
        add_edge(0,i,1);
        add_edge(i+n,2*n+1,1);
    }

    int source=0;
    int sink=2*n+1;

    MX=sink;

    for(int i=1;i<=m;i++)
        if(inp[mx].second.second>=inp[i].second.second)
        {
            add_edge(inp[i].first,n+inp[i].second.first,1);
        }

    int mem=max_flow(source,sink);

    //cout<<mx<<" "<<mem<<endl;

    if(mem==n)return 1;
    return 0;
}
bool cmp(pair< int/*from*/,pair<int/*to*/,int/*cost*/> > a,pair< int/*from*/,pair<int/*to*/,int/*cost*/> > b)
{
    return a.second.second<b.second.second;
}

int main()
{
    /*
    n=1e4;
    m=n;
    */
    scanf("%i%i",&n,&m);

    for(int i=1;i<=m;i++)
    {
        /*
        inp[i].first=i;
        inp[i].second.first=i;
        inp[i].second.second=1;
        */
        //cout<<inp[i].first<<" "<<inp[i].second.first<<" "<<inp[i].second.second<<endl;

        scanf("%i%i%i",&inp[i].first,&inp[i].second.first,&inp[i].second.second);
    }

    sort(inp+1,inp+m+1,cmp);

    int ok=m+1,not_ok=0;

    if(test(m)==0)
    {
        printf("-1\n");
        return 0;
    }

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;

        if(test(av))ok=av;
        else not_ok=av;
    }

    if(ok>m)printf("-1\n");
    else printf("%i\n",inp[ok].second.second);
    return 0;
}