#include<bits/stdc++.h>
using namespace std;
const int nmax=1<<18;
int n,q;
int id_nodes[nmax];
vector< pair<int/*to*/,int/*cost*/> > front_graph[nmax],back_graph[nmax];
void build_front(int node,int l,int r)
{
    if(l==r)
    {
        id_nodes[l]=node;
        return;
    }
    int av=(l+r)/2;
    front_graph[node].push_back({2*node,0});
    build_front(node*2,l,av);
    front_graph[node].push_back({2*node+1,0});
    build_front(node*2+1,av+1,r);
}

void build_back(int node,int l,int r)
{
    if(l==r)
    {
        id_nodes[l]=node;
        return;
    }
    int av=(l+r)/2;
    back_graph[2*node].push_back({node,0});
    build_back(node*2,l,av);
    back_graph[2*node+1].push_back({node,0});
    build_back(node*2+1,av+1,r);
}

void add_front(int node,int l,int r,int lq,int rq,int from,int cost)
{
    if(l==lq&&r==rq)
    {
        front_graph[from].push_back({node,cost});
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)add_front(node*2,l,av,lq,min(av,rq),from,cost);
    if(av<rq)add_front(node*2+1,av+1,r,max(av+1,lq),rq,from,cost);
}

void add_back(int node,int l,int r,int lq,int rq,int to,int cost)
{
    if(l==lq&&r==rq)
    {
        back_graph[node].push_back({to,cost});
        return;
    }
    int av=(l+r)/2;
    if(lq<=av)add_back(node*2,l,av,lq,min(av,rq),to,cost);
    if(av<rq)add_back(node*2+1,av+1,r,max(av+1,lq),rq,to,cost);
}

long long dist[nmax][2];

priority_queue< pair<long long/*cost*/,pair<int/*node*/,bool/*type*/> > >pq;

bool teleport[nmax];
int main()
{
int s;
cin>>n>>q>>s;
build_front(1,1,n);

build_back(1,1,n);
int t,l,r,v,u,w;
for(int i=1;i<=q;i++)
{
    cin>>t;
    if(t==1)
    {
        cin>>v>>u>>w;
        front_graph[id_nodes[v]].push_back({id_nodes[u],w});
        back_graph[id_nodes[v]].push_back({id_nodes[u],w});
    }
    if(t==2)
    {
        cin>>v>>l>>r>>w;
        add_front(1,1,n,l,r,id_nodes[v],w);
    }
    if(t==3)
    {
        cin>>v>>l>>r>>w;
        add_back(1,1,n,l,r,id_nodes[v],w);
    }
}

for(int i=1;i<=n;i++)
    teleport[id_nodes[i]]=1;

pq.push({0,{id_nodes[s],0}});
memset(dist,-1,sizeof(dist));

while(pq.size())
{
    pair<long long/*cost*/,pair<int/*node*/,bool/*type*/> > now=pq.top();
    long long cost=-now.first;
    int node=now.second.first;
    bool type=now.second.second;
    pq.pop();
    if(dist[node][type]!=-1)continue;
    dist[node][type]=cost;

    if(type==0)
    {
        for(auto k:front_graph[node])
            pq.push({-(cost+k.second),{k.first,0}});
    }

    if(type==1)
    {
        for(auto k:back_graph[node])
            pq.push({-(cost+k.second),{k.first,1}});
    }

    if(teleport[node])pq.push({-cost,{node,!type}});
}

for(int i=1;i<=n;i++)
    cout<<dist[id_nodes[i]][0]<<" ";cout<<endl;
return 0;
}