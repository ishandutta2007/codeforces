#include <bits/stdc++.h>
using namespace std;
vector <int> v[500005];
vector <int> w[500005];
long long dp[500005][2],k;
struct ura
{
    long long d1,d0;
};
bool cmp (ura a, ura b)
{
    return a.d1-a.d0>b.d1-b.d0;
}
void dfs (int pz, int t)
{
    vector <ura> vc;
    int cnt=0;
    for(int i=0;i<v[pz].size();++i)
    {
        if(v[pz][i]==t)
            continue;
        dfs(v[pz][i],pz);
        vc.push_back({dp[v[pz][i]][1]+w[pz][i],dp[v[pz][i]][0]});
        ++cnt;
    }
    sort(vc.begin(),vc.end(),cmp);
    /// dp[pz][0]; -> k
    int cat=k;
    for(int i=0;i<cnt;++i)
    {
        if(cat && vc[i].d1>vc[i].d0)
        {
            --cat;
            dp[pz][0]+=vc[i].d1;
        }
        else
            dp[pz][0]+=vc[i].d0;
    }
    cat=k-1;
    for(int i=0;i<cnt;++i)
    {
        if(cat && vc[i].d1>vc[i].d0)
        {
            --cat;
            dp[pz][1]+=vc[i].d1;
        }
        else
            dp[pz][1]+=vc[i].d0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long m,i,j,n,t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=1;i<=n;++i)
        {
            v[i].clear();
            w[i].clear();
            dp[i][0]=dp[i][1]=0;
        }
        for(i=1;i<n;++i)
        {
            int a,b,c;
            cin>>a>>b>>c;
            v[a].push_back(b);
            v[b].push_back(a);
            w[a].push_back(c);
            w[b].push_back(c);
        }
        dfs(1,-1);
        cout<<dp[1][0]<<'\n';
    }
    return 0;
}