#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,k;
vector< pair<int/*to*/,int/*cost*/> > adj[nmax];

long long dp[nmax][2];

bool cmp(long long u,long long v)
{
    return u>v;
}
long long rec(int node,int parent,bool is_parent_taken)
{
    //cout<<"rec "<<node<<" "<<parent<<" "<<is_parent_taken<<endl;
    if(dp[node][is_parent_taken]!=-1)return dp[node][is_parent_taken];

    long long ret=0;
    vector<long long> gains={};
    for(auto w:adj[node])
        if(w.first!=parent)
        {
            ret=ret+rec(w.first,node,0);
            gains.push_back(rec(w.first,node,1)+w.second-rec(w.first,node,0));
        }
    if(gains.size())sort(gains.begin(),gains.end(),cmp);

    int take=gains.size();
    take=min(take,k-is_parent_taken);

    //cout<<node<<" "<<parent<<" "<<is_parent_taken<<" "<<gains.size()<<" "<<take<<endl;
    for(int i=0;i<take;i++)
        if(gains[i]>0)ret=ret+gains[i];

    //cout<<"dp "<<node<<" "<<is_parent_taken<<" = "<<ret<<endl;
    dp[node][is_parent_taken]=ret;
    return ret;
}

long long solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)adj[i]={},dp[i][0]=-1,dp[i][1]=-1;

    int u,v,c;
    for(int i=1;i<n;i++)
    {
        scanf("%i%i%i",&u,&v,&c);
        adj[u].push_back({v,c});
        adj[v].push_back({u,c});
    }

    return rec(1,0,0);
}
int main()
{
    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
        printf("%lld\n",solve());

    return 0;
}