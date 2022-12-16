#include<bits/stdc++.h>
using namespace std;
const int nmax=1e3+42;
int n;
vector<int> adj[nmax];

int ask(int u,int v)
{
    cout<<"? "<<u<<" "<<v<<endl;
    int ret;
    cin>>ret;
    return ret;
}

int dfs(int node,int parent,int to_igone)
{
    vector<int> to_check={};
    for(auto k:adj[node])
        if(k!=parent&&k!=to_igone)to_check.push_back(k);

    if(to_check.size()==0)return node;

    int SZ=to_check.size();
    for(int i=1;i<SZ;i=i+2)
    {
        int u=to_check[i-1];
        int v=to_check[i];

        int mem=ask(u,v);
        if(mem==u)return dfs(u,node,0);
        if(mem==v)return dfs(v,node,0);
    }

    if(to_check.size()%2==0)return node;
    int lst=to_check[to_check.size()-1];

    if(adj[lst].size()==1)return ask(node,lst);
    for(auto k:adj[lst])
        if(k!=node)
        {
            int mem=ask(node,k);
            if(mem==node)return node;
            if(mem==lst)return dfs(lst,node,k);
            if(mem==k)return dfs(k,lst,0);
        }
    assert(0==1);
}
int main()
{
    scanf("%i",&n);
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int ret=dfs(1,0,0);

    printf("! %i\n",ret);

    return 0;
}