#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
using piii = pair<pii,int>;
int dp[100][100];
int par[100][100];
const int INF = 1e9;

void clear()
{
    for(int i=0;i<100;i++)
        for(int j=0;j<100;j++)
            dp[i][j] = -INF,par[i][j]=-1;
}

void solve()
{
    int n,k,i,j,a,b,sum=0;
    cin>>n>>k;
    vector<piii> v;
    dp[0][0] = 0;
    for(i=0;i<n;i++)
    {
        cin>>a>>b;
        sum+=(k-1)*b;
        v.push_back({{b,a},i});
    }
    sort(v.begin(),v.end());
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
            dp[i][j] = dp[i-1][j], par[i][j] = par[i-1][j];
        for(j=1;j<=k;j++)
        {
            if(dp[i-1][j-1]!=-INF && dp[i-1][j-1] + v[i-1].first.second - (k - j)*v[i-1].first.first > dp[i][j])
                dp[i][j] = dp[i-1][j-1] + v[i-1].first.second - (k - j)*v[i-1].first.first, par[i][j] = i-1;
        }
    }
    vector<int> ans;
    set<int> del;
    int runner = par[n][k];
    int val = k;
    while(runner != -1)
    {
        ans.push_back(runner);
        del.insert(runner);
        runner = par[runner][val-1];
        val--;
    }
    cout<<2*n-k<<endl;
    for(i=0;i<k-1;i++)
    {
        cout<<v[ans.back()].second+1<<' ';
        ans.pop_back();
    }
    for(i=0;i<n;i++)
    {
        if(del.count(i) == 0)
            cout<<v[i].second+1<<' '<<-v[i].second-1<<' ';
    }
    cout<<v[ans[0]].second+1<<endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        clear();
        solve();
    }
}