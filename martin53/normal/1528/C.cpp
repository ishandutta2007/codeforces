#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;

vector<int> adj_a[nmax],adj_b[nmax];

vector< pair<int/*is*/,int/*was*/> > updates;

int outp;

int t=0;

int in[nmax],out[nmax];

bool is_parent(int u,int v)
{
    return in[u]<=in[v]&&out[v]<=out[u];
}
set< pair<int,int> > active;

void upd(int node,int type)
{
    if(type==-1)
    {
        pair<int,int> help=updates.back();
        updates.pop_back();

        if(help.first<0)return;

        active.erase({in[help.first],help.first});

        if(help.second>0)active.insert({in[help.second],help.second});

        return;
    }

    pair<int,int> update={-1,-1};

    if(active.size()==0)
    {
        active.insert({in[node],node});

        update={node,-1};

        updates.push_back(update);

        return;
    }

    set< pair<int,int> >::iterator it=active.lower_bound({in[node],0});

    if(it!=active.end())
    {
        if(is_parent(node,(*it).second))//wrong
        {
            updates.push_back(update);
            return;
        }
    }

    update.first=node;

    if(it!=active.begin())
    {
        it--;

        if(is_parent((*it).second,node))
        {
            update.second=(*it).second;
        }
    }

    updates.push_back(update);

    active.insert({in[node],node});
    if(update.second>0)active.erase({in[update.second],update.second});
}

int ask()
{
    return active.size();
}

void dfs(int node)
{
    upd(node,1);

    outp=max(outp,ask());

    for(auto w:adj_a[node])
    {
        dfs(w);
    }

    upd(node,-1);
}

void dfs_b(int node)
{
    t++;

    in[node]=t;

    for(auto w:adj_b[node])
    {
        dfs_b(w);
    }

    out[node]=t;
}
void solve()
{
    updates={};

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        adj_a[i]={};
        adj_b[i]={};
    }

    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%i",&p);
        adj_a[p].push_back(i);
    }

    for(int i=2;i<=n;i++)
    {
        int p;
        scanf("%i",&p);
        adj_b[p].push_back(i);
    }

    t=0;
    dfs_b(1);

    outp=0;

    dfs(1);

    printf("%i\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}