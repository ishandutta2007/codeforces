#include<bits/stdc++.h>
using namespace std;
const int nmax=5e5+42;
int n,q;
vector<int> adj[nmax];
int order[nmax*2],pos=0,in[nmax],out[nmax],parent[nmax];
void dfs(int node,int par)
{
    parent[node]=par;
    pos++;
    order[pos]=node;
    in[node]=pos;
    for(auto k:adj[node])
        if(k!=par)
        {
        dfs(k,node);
        pos++;
        order[pos]=node;
        }
    out[node]=pos;
}
set<int> active;
int main()
{
scanf("%i",&n);
int x,y;
for(int i=1;i<n;i++)
{
    scanf("%i%i",&x,&y);
    adj[x].push_back(y);
    adj[y].push_back(x);
}
scanf("%i",&q);
dfs(1,0);

//for(int i=1;i<=n;i++)cout<<in[i]<<" "<<out[i]<<endl;

int type;
for(int i=1;i<=n;i++)active.insert(in[i]);
for(int i=1;i<=q;i++)
{
    scanf("%i%i",&type,&x);
    if(type==1)
    {
        bool add=0;
        while(1)
        {
        std::set<int>::iterator v=active.lower_bound(in[x]);
        if(v==active.end())break;
        if(*v<=out[x]){active.erase(*v);add=1;}
        else break;
        }
        if(add&&parent[x])active.insert(in[parent[x]]);
    }
    else if(type==2)
    {
        active.insert(in[x]);
    }
    else
    {
        std::set<int>::iterator v=active.lower_bound(in[x]);
        //cout<<*v<<" "<<out[x]<<endl;
        if(v==active.end())printf("1\n");
        else if(*v>out[x])printf("1\n");
        else printf("0\n");
    }
    //cout<<"active: ";for(auto k:active)cout<<k<<" ";cout<<endl;
}

return 0;
}