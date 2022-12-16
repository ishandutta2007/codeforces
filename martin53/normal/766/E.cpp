#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42;
int n;
int a[nmax];
vector<int> adj[nmax];

int SZ[nmax],ones[nmax];

long long sum=0;
bool add[nmax];
int bit;
void dfs(int node,int parent)
{
    for(auto k:adj[node])
        if(k!=parent)dfs(k,node);

    SZ[node]=1;
    for(auto k:adj[node])
        if(k!=parent)SZ[node]=SZ[node]+SZ[k];

    for(auto k:adj[node])
        if(k!=parent)ones[node]+=ones[k];
    if(((a[node]>>bit)&1)==1)ones[node]=SZ[node]-ones[node];
}

void dfs_2(int was,int parent)
{
    if(add[was]==0)
    {
        sum=sum+ones[was];
        add[was]=1;
    }

    for(auto now:adj[was])//root moves to now
        if(now!=parent)
        {
            int mem_SZ_was=SZ[was],mem_ones_was=ones[was];
            int mem_SZ_now=SZ[now],mem_ones_now=ones[now];

            SZ[was]=SZ[was]-SZ[now];
            if(((a[was]>>bit)&1)==0)ones[was]=ones[was]-ones[now];
            else ones[was]=ones[was]-SZ[now]+ones[now];

            SZ[now]=SZ[now]+SZ[was];
            if(((a[now]>>bit)&1)==0)ones[now]=ones[now]+ones[was];
            else ones[now]=ones[now]+SZ[was]-ones[was];

            dfs_2(now,was);

            SZ[was]=mem_SZ_was,ones[was]=mem_ones_was;
            SZ[now]=mem_SZ_now,ones[now]=mem_ones_now;
        }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    int x,y;
    for(int i=1;i<n;i++)
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long outp=0;
    for(bit=0;bit<20;bit++)
    {
    sum=0;
    /*
        for(int j=1;j<=n;j++)
        {
        memset(SZ,0,sizeof(SZ));
        memset(ones,0,sizeof(ones));
        memset(add,0,sizeof(add));
        dfs(j,0);
        sum=sum+ones[j];
        cout<<bit<<" "<<j<<" "<<ones[j]<<endl;
        }
    */
    memset(SZ,0,sizeof(SZ));
    memset(ones,0,sizeof(ones));
    memset(add,0,sizeof(add));
    dfs(1,0);
    dfs_2(1,0);
    outp=outp+(sum<<bit);
    }

    for(int i=1;i<=n;i++)outp=outp+a[i];

    cout<<outp/2<<endl;
    return 0;
}