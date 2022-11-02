#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N][2];
int pointer[N];
int a[N];
vector<int> pos[N];

int main()
{
    int n,i,j;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    vector<int> comp;
    for(i=0;i<n-1;i++)
        if(a[i] != a[i+1])
            comp.push_back(a[i]);
    comp.push_back(a[n-1]);
    n = comp.size();
    for(i=0;i<n;i++)
        pos[comp[i]].push_back(i), pointer[comp[i]]++;
    for(i=n-1;i>=0;i--)
    {
        //Compute dp[i][1]
        a[i] = comp[i];
        pointer[a[i]]--;
        if(pointer[a[i]] == pos[a[i]].size()-1)
            dp[i][1] = n-i;
        else
        {
            dp[i][1] = min(dp[pos[a[i]][pointer[a[i]]+1] - 1][1] -1,dp[pos[a[i]][pointer[a[i]]+1]][0]) + pos[a[i]][pointer[a[i]]+1] - i -1;
        }
        //Compute dp[i][0]
        if(i != n-1)
            dp[i][0] = min(dp[i][1],dp[i+1][0]+1);
        else
            dp[i][0] = dp[i][1];
        //cout<<i<<' '<<dp[i][1]<<' '<<dp[i][0]<<endl;
    }
    cout<<dp[0][0];
    return 0;
}