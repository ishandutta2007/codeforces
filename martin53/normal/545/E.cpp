#include<bits/stdc++.h>
using namespace std;
const int nmax=3*1e5+42,inf=1e9+42;
int n,m;
struct edge
{
int v,c,index;
};
vector< edge > adj[nmax];
edge make_edge(int v,int c,int index)
{
edge now;
now.v=v;
now.c=c;
now.index=index;
return now;
}
priority_queue< pair<long long/*cost*/,int/*node*/> > pq;
long long mem[nmax];
vector<int> outp;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cout.tie();
cin>>n>>m;
int u,v,c;
for(int i=1;i<=m;i++)
{
cin>>u>>v>>c;
adj[u].push_back(make_edge(v,c,i));
adj[v].push_back(make_edge(u,c,i));
}
cin>>v;
pq.push({0,v});
memset(mem,-1,sizeof(mem));
long long ans=0;
while(pq.size())
{
    pair<long long/*cost*/,int/*node*/>now=pq.top();
    pq.pop();
    now.first=-now.first;
    if(mem[now.second]!=-1)continue;
    mem[now.second]=now.first;

    if(now.second!=v)
    {
    pair<int/*cost*/,int/*index*/> best={inf,inf};
    for(auto k:adj[now.second])
        if(mem[k.v]!=-1&&mem[k.v]+k.c==now.first)
        {
            if(best.first>k.c)
            {
            best.first=k.c;
            best.second=k.index;
            }
        }
    outp.push_back(best.second);
    ans=ans+best.first;
    }

    for(auto k:adj[now.second])
    {
        pq.push({-(now.first+k.c),k.v});
    }
}

cout<<ans<<endl;
for(auto k:outp)cout<<k<<" ";cout<<endl;

return 0;
}