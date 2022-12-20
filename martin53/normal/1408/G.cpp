#include<bits/stdc++.h>

//#define int long long

using namespace std;

const int nmax=1500+42,mod=998244353;

int n,inp[nmax][nmax];

pair<int,int> where[nmax*nmax];

int parent[nmax*nmax],SZ[nmax*nmax];

int in[nmax];

int root(int node)
{
    while(parent[node]!=node)node=parent[node];
    return node;
}
void print(vector<int> v)
{
    for(auto k:v)cout<<k<<" ";;
}
vector<int> my_mult(vector<int> a,vector<int> b)
{
    vector<int> ret(a.size()+b.size()-1,0);

    for(int i=0;i<a.size();i++)
        for(int j=0;j<b.size();j++)
        {
            long long cur=a[i];
            cur=(cur*b[j])%mod;
            ret[i+j]=(ret[i+j]+cur)%mod;
        }
    /*
    print(a);
    cout<<" * ";print(b);
    cout<<" = ";print(ret);
    cout<<endl;
    */

    return ret;
}

vector<int> dp[nmax];

signed main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%i",&inp[i][j]);
            if(i<j)where[inp[i][j]]={i,j};
        }

    for(int i=1;i<=n;i++)
        parent[i]=i,SZ[i]=1,dp[i]={0,1};

    int out=n*(n-1)/2,pointer=n;

    for(int i=1;i<=n*(n-1)/2;i++)
    {
        int u=root(where[i].first),v=root(where[i].second);

        if(u!=v)
        {
            out=out-SZ[u]*SZ[v];

            if(SZ[u]<SZ[v])swap(u,v);

            parent[v]=u;
            SZ[u]+=SZ[v];

            in[u]++;
            in[u]+=in[v];

            dp[u]=my_mult(dp[u],dp[v]);
        }
        else in[u]++;

        if(in[u]==SZ[u]*(SZ[u]-1)/2)
        {
            dp[u][1]++;
        }
        /*
        cout<<"u= "<<u<<" i= "<<i<<endl;
        for(auto k:dp[u])cout<<k<<" ";cout<<endl;
        */
    }
    /*
    for(int i=n+1;i<=pointer;i++)
    {
        cout<<"adj "<<i<<" -> ";for(auto k:adj[i])cout<<k<<" ";cout<<endl;
    }
    */

    vector<int> mem=dp[root(1)];

    assert(mem.size()==n+1);

    for(int i=1;i<=n;i++)printf("%i ",mem[i]);printf("\n");
    return 0;
}