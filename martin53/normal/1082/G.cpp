#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=2*1e3+42,inf=1e18;
struct edge
{
    int from,to,flow;
};
vector< edge > all;
vector<int> adj[nmax];
void add_edge(int from,int to,int flow)
{
    int id=all.size();
    edge my;
    my.from=from;my.to=to;my.flow=flow;all.push_back(my);
    adj[from].push_back(id);
    id++;
    my.to=from;my.from=to;my.flow=0;all.push_back(my);
    adj[to].push_back(id);
}
int n,m;
int arr[nmax];
int s,t;
int level[nmax];
queue< pair<int/*node*/,int/*distance*/> > que;
bool bfs()
{
    memset(level,-1,sizeof(level));
    que.push({s,0});
    while(que.size())
    {
        pair<int/*node*/,int/*distance*/> now=que.front();
        que.pop();
        int node=now.first;
        int dist=now.second;
        if(level[node]!=-1)continue;
        level[node]=dist;
        for(auto k:adj[node])
            if(all[k].flow)
            {
                que.push({all[k].to,dist+1});
            }
    }
    return (level[t]!=-1);
}
int in[nmax];
int dfs(int node,int flow)
{
    if(node==t)return flow;
    long long now;
    for(auto k:adj[node])
        if(level[node]+1==level[all[k].to]&&all[k].flow)
        {
            now=dfs(all[k].to,min(flow,all[k].flow));
            if(now)
            {
                all[k].flow-=now;
                all[k^1].flow+=now;
                return now;
            }
        }
    return 0;
}
long long dinitz()
{
    long long flow=0;
    while(bfs())
    {
        memset(in,0,sizeof(in));
        long long add=dfs(0,inf);
        if(add==0)break;
        flow=flow+add;
    }
    return flow;
}
signed main()
{
cin>>n>>m;
s=0;
t=m+n+1;
for(int i=1;i<=n;i++)cin>>arr[i];
for(int i=1;i<=n;i++)
    add_edge(m+i,t,arr[i]);
long long sum=0;
int v,u,w;
for(int i=1;i<=m;i++)
{
    cin>>v>>u>>w;
    sum=sum+w;
    add_edge(i,v+m,inf);
    add_edge(i,u+m,inf);
    add_edge(s,i,w);
}
cout<<sum-dinitz()<<endl;
return 0;
}