#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 2e5+10;
vector<pii> G[N];
int n,m,k,i,j,l;
long long hashed[11][11];
long long cor_hash;
long long ran[N];
int ans;

void genCheck(int a[], int pl)
{
    if(pl == k+1)
    {
        bool pass = true;
        int i,j;
        long long here = 0;
        for(i=0;i<k;i++)
        {
            here+=hashed[i+1][a[i]];
        }
        if(here == cor_hash)
        {
            ans++;
        }
    }
    else
    {
        int t;
        for(t=1;t<=pl;t++)
        {
            a[pl-1] = t;
            genCheck(a,pl+1);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long seed = 7;
    for(i=0;i<N;i++)
    {
        ran[i] = seed;
        seed*=1543;
        seed+=29;
    }
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        cor_hash+=ran[i];
    for(i=0;i<m;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--,b--;
        G[a].push_back({c,b});
    }
    for(i=0;i<n;i++)
        sort(G[i].begin(),G[i].end());
    for(i=0;i<n;i++)
    {
        for(j=0;j<G[i].size();j++)
        {
            pii cur = G[i][j];
            hashed[G[i].size()][j+1]+=ran[cur.second];
        }
    }
    int a[n];
    genCheck(a,1);
    cout<<ans;
}