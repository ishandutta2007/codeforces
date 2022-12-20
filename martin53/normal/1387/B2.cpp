#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;

int n;

vector<int> adj[nmax];

long long score=0;
int outp[nmax];

int SZ[nmax];

void dfs(int node,int par)
{
    SZ[node]=1;

    for(auto k:adj[node])
        if(k!=par)
        {
            dfs(k,node);
            SZ[node]+=SZ[k];
        }
}
int centroid()
{
    dfs(1,1);

    int node=1;

    while(1)
    {
        bool stop=1;

        for(auto k:adj[node])
            if(SZ[k]<SZ[node]&&SZ[k]>=(n+1)/2)
        {
            node=k;
            stop=0;
        }

        if(stop)break;
    }
    return node;
}

bool is_edge(int u,int v)
{
    for(auto k:adj[u])
        if(k==v)return 1;
    return 0;
}

int height[nmax];

vector<int> path={};

vector< pair<int/*node*/,int/*h*/> > group[nmax];

bool cmp(pair<int/*node*/,int/*h*/> a,pair<int/*node*/,int/*h*/> b)
{
    return a.second<b.second;
}
void dfs_h(int node,int par,int h)
{
    path.push_back(node);
    height[node]=h;

    if(path.size()>=2)
    {
        group[path[1]].push_back({node,h});
    }

    for(auto k:adj[node])
        if(k!=par)
            dfs_h(k,node,h+1);

    path.pop_back();
}

set< pair<int/*size*/,int/*id*/> > active;

void my_merge(int group_1,int group_2)
{
    active.erase({group[group_1].size(),group_1});
    active.erase({group[group_2].size(),group_2});

    score+=2*group[group_1].back().second;
    score+=2*group[group_2].back().second;

    int u=group[group_1].back().first;
    int v=group[group_2].back().first;

    outp[u]=v;
    outp[v]=u;

    group[group_1].pop_back();
    group[group_2].pop_back();

    if(group[group_1].size())active.insert({group[group_1].size(),group_1});
    if(group[group_2].size())active.insert({group[group_2].size(),group_2});
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

    int root=centroid();

    //cout<<root<<endl;

    dfs_h(root,0,0);

    for(int i=1;i<=n;i++)
        if(group[i].size())
        {
            sort(group[i].begin(),group[i].end(),cmp);
            active.insert({group[i].size(),i});
        }
    int remain=n;

    while(remain>3)
    {
        assert(active.size()>=2);

        set< pair<int/*size*/,int/*id*/> >::iterator it=active.end();
        it--;

        int g1=(*it).second;

        it--;

        int g2=(*it).second;

        my_merge(g1,g2);

        remain=remain-2;
    }

    vector<int> rem={};
    for(int i=1;i<=n;i++)
        if(outp[i]==0)rem.push_back(i);

    if(rem.size()==2)
    {
        outp[rem[0]]=rem[1];
        outp[rem[1]]=rem[0];
        score+=2;
    }
    else
    {
        int zero,one,two;

        if(is_edge(rem[0],rem[1])==0)zero=rem[0],one=rem[1],two=rem[2];
        else if(is_edge(rem[1],rem[2])==0)zero=rem[1],one=rem[2],two=rem[0];
        else zero=rem[2],one=rem[0],two=rem[1];

        outp[zero]=one;
        outp[two]=zero;
        outp[one]=two;

        score+=4;
    }

    printf("%lld\n",score);
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);

    return 0;
}