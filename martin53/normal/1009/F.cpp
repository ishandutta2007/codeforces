#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
struct mem
{
    map<int,int> seen;
    int maxi;
    int where;
};
mem inp[nmax];
int ask(int node)
{
    return inp[node].where;
}
int n;
vector<int> adj[nmax];
int ans[nmax];
void my_move(int big,int small)
{
    for(auto k:inp[small].seen)
    {
        inp[big].seen[k.first]+=k.second;
        int p=inp[big].seen[k.first];
        int q=inp[big].seen[inp[big].maxi];
        if(p>q)inp[big].maxi=k.first;
        else if(p==q&&inp[big].maxi>k.first)inp[big].maxi=k.first;
    }
}
void solve(int node,int parent,int depth)
{
    inp[node].seen[depth]++;
    inp[node].maxi=depth;

    for(auto k:adj[node])
        if(k!=parent)
        solve(k,node,depth+1);

    int where=node;
    for(auto k:adj[node])
        if(k!=parent)
        {
            if(inp[ask(where)].seen.size()<inp[ask(k)].seen.size())where=k;
        }
    inp[node].where=ask(where);
    for(auto k:adj[node])
        if(k!=parent&&k!=where)
        {
            my_move(inp[node].where,inp[k].where);
        }
    if(where!=node)my_move(inp[node].where,node);
    ans[node]=inp[ask(node)].maxi-depth;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();
cin>>n;
for(int i=1;i<=n;i++)inp[i].where=i;
int x,y;
for(int i=1;i<n;i++)
{
    cin>>x>>y;
    adj[x].push_back(y);
    adj[y].push_back(x);
}
solve(1,1,0);
for(int i=1;i<=n;i++)cout<<ans[i]<<'\n';cout<<endl;
return 0;
}