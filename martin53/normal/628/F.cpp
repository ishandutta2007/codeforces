#include<bits/stdc++.h>
using namespace std;
const int nmax=2e4+42;
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

int n,b,q,q_;

pair<int/*to*/,int/*quantity*/> inp[nmax],inp_[nmax];
void print(bool ok)
{
    if(ok)printf("fair");
    else printf("unfair");
    exit(0);
}
void compress()
{
    q_=0;
    for(int i=1;i<=q;i++)
    {
        if(q_>=1&&inp_[q_].first==inp[i].first)continue;
        q_++;
        inp_[q_]=inp[i];
    }

    q=q_;
    for(int i=1;i<=q;i++)
        inp[i]=inp_[i];
}
int sink,MX;
void add(int id,int l,int r,int how)
{
    if(l>r)return;
    if(how<0)print(0);

    for(int i=l;i<=r;i++)
        add_edge(i,id,1);

    add_edge(id,sink,how);
}

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
int dfs(int where,int aim,int flow)
{
    if(been[where])return 0;
    been[where]=1;
    if(where==aim)return flow;
    for(auto &k:graph[where])
        if(dist[k.to]==dist[where]-1&&k.cap)
        {
            int now=dfs(k.to,aim,min(flow,k.cap));

            k.cap-=now;
            graph[k.to][k.id_back].cap+=now;

            if(now)return now;
        }
    return 0;
}

int max_flow(int from,int to)
{
    int ret=0;
    while(bfs(from,to))
    {
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
int main()
{
    scanf("%i%i%i",&n,&b,&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);
    }
    q++;
    inp[q]={b,n};
    sort(inp+1,inp+q+1);

    compress();

    sink=b+q+6;
    MX=sink;

    for(int i=1;i<=5;i++)
        add_edge(0,b+q+i,n/5);

    for(int i=1;i<=5;i++)
        for(int j=1;j<=b;j++)
            if(i%5==j%5)
            {
                add_edge(b+q+i,j,1);
            }


    int prev_pos=0,prev_limit=0;

    for(int i=1;i<=q;i++)
    {
        add(i+b,inp[i-1].first+1,inp[i].first,inp[i].second-inp[i-1].second);
    }


    if(max_flow(0,sink)==n)print(1);
    else print(0);
    return 0;
}