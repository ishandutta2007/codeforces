#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,k;

vector<int> adj[nmax];

int dist[nmax];

void dfs(int node,int par,int d)
{
    dist[node]=d;

    for(auto k:adj[node])
        if(k!=par)dfs(k,node,d+1);
}
int far(int start)
{
    memset(dist,-1,sizeof(dist));

    dfs(start,start,0);

    int ret=1;
    for(int i=1;i<=n;i++)
        if(dist[ret]<dist[i])ret=i;

    return ret;
}

vector<int> path,cur_path;

void get_diameter(int node,int par,int aim)
{
    cur_path.push_back(node);

    if(node==aim)
    {
        path=cur_path;
        return;
    }

    for(auto k:adj[node])
        if(k!=par)
            get_diameter(k,node,aim);

    cur_path.pop_back();
}

int outp[nmax];

int dfs_down(int node,int par)
{
    //cout<<"dfs_down "<<node<<" "<<par<<endl;

    int cur=outp[par]+1;
    if(cur>k)cur=cur-k;

    int ret=0;

    outp[node]=cur;
    for(auto p:adj[node])
        if(p!=par)ret=max(ret,dfs_down(p,node));

    ret++;
    return ret;
}

int dfs_up(int node,int par)
{
    //cout<<"dfs_up "<<node<<" "<<par<<endl;

    int cur=outp[par]-1;
    if(cur==0)cur=cur+k;

    int ret=0;

    outp[node]=cur;
    for(auto p:adj[node])
        if(p!=par)ret=max(ret,dfs_up(p,node));

    ret++;
    return ret;
}

void solve()
{
    int u=far(1);
    int v=far(u);

    get_diameter(u,u,v);

    if(path.size()<k)
    {
        printf("Yes\n");
        for(int i=1;i<=n;i++)printf("1 ");
        printf("\n");
        exit(0);
    }

    int cur=1;

    for(int i=0;i<path.size();i++)
    {
        outp[path[i]]=cur;

        cur++;
        if(cur>k)cur=cur-k;
    }

    for(int i=0;i<path.size();i++)
    {
        int SZ[3]={i,path.size()-1-i,0};

        int node=path[i];

        //cout<<u<<" "<<v<<" "<<node<<endl;

        if(i<path.size()/2)
        {
            for(auto p:adj[node])
                if(outp[p]==0)SZ[2]=max(SZ[2],dfs_up(p,node));
        }
        else
        {
            for(auto p:adj[node])
                if(outp[p]==0)SZ[2]=max(SZ[2],dfs_down(p,node));
        }

        if(k>=3&&SZ[0]+SZ[1]>=k-1&&SZ[1]+SZ[2]>=k-1&&SZ[2]+SZ[0]>=k-1&&SZ[0]&&SZ[1]&&SZ[2])
        {
            printf("No\n");
            exit(0);
        }
    }

    printf("Yes\n");
    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
    printf("\n");
    exit(0);
}

mt19937 rng(42);

int main()
{
    scanf("%i%i",&n,&k);
    /*
    n=2e5;
    k=20;
    */

    for(int i=1;i<n;i++)
    {
        int u,v;

        u=i+1;
        v=rng()%i+1;

        //assert(v<u);
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve();

    return 0;
}