#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+42,mod=1e9+7;

int n,k;

vector<int> adj[nmax];

vector<int> seen[nmax];

int cnt[nmax];

void dfs(int node,int par,int d)
{
    cnt[d]++;

    for(auto w:adj[node])
        if(w!=par)
            dfs(w,node,d+1);
}

vector<int> help;
int SZ;

long long dp[nmax][nmax];

long long rec(int pos,int used)
{
    if(used==k)return 1;

    if(pos==SZ)return 0;

    if(dp[pos][used]!=-1)return dp[pos][used];

    dp[pos][used]=(rec(pos+1,used)+help[pos]*rec(pos+1,used+1))%mod;

    return dp[pos][used];
}
int eval(vector<int> cur)
{
    help=cur;

    SZ=help.size();

    for(int j=0;j<SZ;j++)
        for(int p=0;p<k;p++)
            dp[j][p]=-1;

    return rec(0,0);
}

int solve()
{
    scanf("%i%i",&n,&k);

    for(int i=1;i<=n;i++)adj[i]={},seen[i]={};

    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(k==2)return n*(n-1)/2;

    long long outp=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)seen[j]={};

        for(auto u:adj[i])
        {
            for(int j=1;j<=n;j++)cnt[j]=0;

            dfs(u,i,1);

            for(int j=1;j<=n;j++)
                if(cnt[j])seen[j].push_back(cnt[j]);
        }

        for(int j=1;j<=n;j++)
            if(seen[j].size()>=k)outp=(outp+eval(seen[j]))%mod;
    }

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}