#include<bits/stdc++.h>
using namespace std;
const int nmax=30+5;
int n;
vector<int> adj[nmax];
bool solved[nmax];
pair<long long,long long> outp[nmax];
long long dist[nmax];
int pos;
void dfs(int node,int dir,long long x,long long y)
{
    if(solved[node])return;
    bool blocked[4]={0,0,0,0};
    blocked[3-dir]=1;
    outp[node]={x,y};
    solved[node]=1;
    for(auto k:adj[node])
        if(solved[k]==0)
        {
            if(blocked[0]==0)
            {
            long long mem_x=x;
            x=x+dist[pos];
            pos--;
            dfs(k,0,x,y);
            x=mem_x;
            blocked[0]=1;
            continue;
            }

            if(blocked[3]==0)
            {
            long long mem_x=x;
            x=x-dist[pos];
            pos--;
            dfs(k,3,x,y);
            x=mem_x;
            blocked[3]=1;
            continue;
            }

            if(blocked[1]==0)
            {
            long long mem_y=y;
            y=y+dist[pos];
            pos--;
            dfs(k,1,x,y);
            y=mem_y;
            blocked[1]=1;
            continue;
            }

            if(blocked[2]==0)
            {
            long long mem_y=y;
            y=y-dist[pos];
            pos--;
            dfs(k,2,x,y);
            y=mem_y;
            blocked[2]=1;
            continue;
            }
        }
}
int main()
{
cin>>n;
int x,y;
for(int i=1;i<n;i++)
{
cin>>x>>y;
adj[x].push_back(y);
adj[y].push_back(x);
}
dist[0]=1;
for(int i=1;i<=n;i++)dist[i]=dist[i-1]*3;
pos=n;
for(int i=1;i<=n;i++)
    if(adj[i].size()>4)
    {
    cout<<"NO"<<endl;
    return 0;
    }
for(int i=1;i<=n;i++)
if(adj[i].size()==1)
{
    dfs(i,0,0,0);
    break;
}
cout<<"YES"<<endl;
for(int i=1;i<=n;i++)cout<<outp[i].first<<" "<<outp[i].second<<endl;
return 0;
}