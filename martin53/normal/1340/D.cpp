#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
vector<int> adj[nmax];

vector< pair<int,int> > outp;

int MX;

void dfs(int node,int par,int t)
{
    outp.push_back({node,t});

    vector<int> children={};
    for(auto k:adj[node])
        if(k!=par)children.push_back(k);

    int cur_t=t;

    int remain=children.size();

    for(auto k:children)
    {
        if(cur_t==MX)
        {
            cur_t=t-remain-1;
            outp.push_back({node,cur_t});
        }

        dfs(k,node,cur_t+1);

        remain--;

        cur_t++;

        outp.push_back({node,cur_t});
    }


    if(cur_t+1!=t&&node!=1)
    {
        outp.push_back({node,t-1});
    }


}

int main()
{
    scanf("%i",&n);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for(int i=1;i<=n;i++)
        if(adj[i].size()>MX)MX=adj[i].size();

    //cout<<"MX= "<<MX<<endl;

    dfs(1,0,0);

    printf("%i\n",outp.size());

    for(auto k:outp)
        printf("%i %i\n",k.first,k.second);

    return 0;
}