#include<bits/stdc++.h>
using namespace std;
const int nmax=2000,inf=1e9,MX=25;

struct edge
{
    int from,to,flow;
};

vector<int> adj[nmax];
vector<edge> all;

void add_edge(int from,int to,int flow)
{
    edge current;current.from=from;current.to=to;current.flow=flow;
    adj[from].push_back(all.size());
    all.push_back(current);

    swap(current.from,current.to);
    current.flow=0;
    adj[to].push_back(all.size());
    all.push_back(current);
}

int source,sink;

int bfs_dist[nmax];

queue< pair<int/*node*/,int/*cost*/> > active,idle;
void bfs()
{
    for(int i=source;i<=sink;i++)bfs_dist[i]=inf;

    active=idle;
    active.push({source,0});

    while(active.size())
    {
        pair<int/*node*/,int/*cost*/> current=active.front();
        active.pop();

        if(bfs_dist[current.first]!=inf)continue;

        bfs_dist[current.first]=current.second;

        if(current.first==sink)return;

        for(auto k:adj[current.first])
            if(all[k].flow&&bfs_dist[all[k].to]==inf)active.push({all[k].to,current.second+1});
    }
}

bool been[nmax];

int dfs(int node)
{
    if(node==sink)return 1;
    if(been[node])return 0;
    been[node]=1;
    for(auto k:adj[node])
    {
        if(bfs_dist[node]<bfs_dist[all[k].to]&&all[k].flow&&dfs(all[k].to))
        {
            been[node]=0;
            all[k].flow--;
            all[k^1].flow++;
            return 1;
        }
    }
    return 0;
}
int max_flow()
{
    int total_flow=0;


    while(1)
    {
        bfs();

        if(bfs_dist[sink]==inf)break;

        int in=0;

        memset(been,0,sizeof(been));
        while(1)
        {
            int current=dfs(source);
            if(current==0)break;
            in++;
            total_flow+=current;
        }
    }
    return total_flow;
}

int n,m,mal,femal;

struct person
{
    int x,y,t;
};

void no()
{
    printf("-1\n");
    exit(0);
}

person males[MX*MX],females[MX*MX];

person other;

long long dist[MX][MX][MX][MX];

int hsh(int x,int y)
{
    return (x-1)*m+y;
}

int test(long long current)
{
    all={};
    for(int i=source;i<=sink;i++)
        adj[i]={};

    for(int i=1;i<=mal;i++)
        add_edge(source,i,1);

    for(int i=1;i<=mal;i++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=m;y++)
                if(dist[males[i].x][males[i].y][x][y]<=current/males[i].t)
                    add_edge(i,mal+hsh(x,y),1);

    for(int x=1;x<=n;x++)
        for(int y=1;y<=m;y++)
            add_edge(mal+hsh(x,y),mal+n*m+hsh(x,y),1);

    for(int j=1;j<=femal;j++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=m;y++)
                if(dist[females[j].x][females[j].y][x][y]<=current/females[j].t)
                    add_edge(mal+n*m+hsh(x,y),mal+n*m+n*m+j,1);

    for(int j=1;j<=femal;j++)
        add_edge(mal+n*m+n*m+j,sink,1);

    return max_flow();
}

char inp[MX][MX];
int main()
{
    scanf("%i%i%i%i",&n,&m,&mal,&femal);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>inp[i][j];

    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=m;y1++)
            for(int x2=1;x2<=n;x2++)
                for(int y2=1;y2<=m;y2++)
                {
                    dist[x1][y1][x2][y2]=1e18;
                    if(inp[x1][y1]=='.'&&inp[x2][y2]=='.')
                    {
                        if(abs(x1-x2)+abs(y1-y2)==0)dist[x1][y1][x2][y2]=0;
                        else if(abs(x1-x2)+abs(y1-y2)==1)dist[x1][y1][x2][y2]=1;
                    }
                }
    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=m;y1++)
            for(int x2=1;x2<=n;x2++)
                for(int y2=1;y2<=m;y2++)
                    for(int x3=1;x3<=n;x3++)
                        for(int y3=1;y3<=m;y3++)
                            dist[x2][y2][x3][y3]=min(dist[x2][y2][x3][y3],dist[x2][y2][x1][y1]+dist[x1][y1][x3][y3]);

    scanf("%i%i%i",&other.x,&other.y,&other.t);

    person current;
    for(int i=1;i<=mal;i++)
    {
        scanf("%i%i%i",&current.x,&current.y,&current.t);
        males[i]=current;
    }

    for(int j=1;j<=femal;j++)
    {
        scanf("%i%i%i",&current.x,&current.y,&current.t);
        females[j]=current;
    }

    if(mal<femal)
    {
        mal++;
        males[mal]=other;
    }
    else
    {
        femal++;
        females[femal]=other;
    }

    if(mal!=femal)no();

    source=0;
    sink=mal+n*m+n*m+femal+1;

    if(test(1e12)<mal)no();

    long long not_ok=-1,ok=1e12;

    while(ok-not_ok>1)
    {
        long long av=(ok+not_ok)/2;
        if(test(av)==mal)ok=av;
        else not_ok=av;
    }

    printf("%lld\n",ok);
    return 0;
}