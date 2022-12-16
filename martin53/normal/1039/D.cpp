#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
vector<int> adj[nmax];

int outp[nmax];

pair<int/*number of paths*/,int/*longest in this node*/> dp[nmax];

int cur_SZ;

void dfs(int node,int par)
{
    int best_1=0,best_2=0;

    int sum=0;

    for(auto k:adj[node])
        if(k!=par)
        {
            dfs(k,node);

            sum+=dp[k].first;

            if(dp[k].second>=best_1)
            {
                best_2=best_1;
                best_1=dp[k].second;
            }

            else if(dp[k].second>=best_2)
            {
                best_2=dp[k].second;
            }
        }

    if(best_1+best_2+1>=cur_SZ)dp[node]={sum+1,0};
    else
    {
        dp[node]={sum,best_1+1};
        if(dp[node].second>=cur_SZ)dp[node]={sum+1,0};
    }

    //cout<<node<<" -> "<<dp[node].first<<" "<<dp[node].second<<" "<<cur_SZ<<" "<<best_1<<" "<<best_2<<endl;
}
void solve(int SZ)
{
    for(int i=1;i<=n;i++)
        dp[i]={0,0};

    cur_SZ=SZ;

    dfs(1,0);

    //cout<<SZ<<" -> "<<dp[1].first<<" "<<dp[1].second<<endl;

    outp[SZ]=dp[1].first;
}

void rec(int l,int r)
{
    if(r-l<=1||outp[l]==outp[r])
    {
        for(int j=l+1;j<r;j++)
            outp[j]=outp[l];
        return;
    }

    int av=(l+r)/2;

    solve(av);

    rec(l,av);
    rec(av,r);
}
int main()
{
    scanf("%i",&n);

    for(int i=2;i<=n;i++)
    {
        int u,v;
        scanf("%i%i",&u,&v);

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    solve(1);
    solve(n);

    rec(1,n);

    for(int i=1;i<=n;i++)
        printf("%i\n",outp[i]);

    return 0;
}