#include <bits/stdc++.h>

using namespace std;

int cnt[22][22];
int rightmost[1100000], dist[1100000], d[1100000][22];
string s;
int dp[1100000];
int n, m;

int get(int i)
{
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    dp[i]=1000000000;
    for(int j=0; j<m; j++)
    {
        if((i&(1<<j))>0)
        {
            dp[i]=min(dp[i], get(i^(1<<j))+dist[i]);
        }
    }
    return dp[i];
}

signed main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    s='!'+s;
    for(int i=2; i<=n; i++)
    {
        cnt[s[i]-'a'][s[i-1]-'a']++;
        cnt[s[i-1]-'a'][s[i]-'a']++;
    }
    for(int i=1; i<(1<<m); i++)
    {
        for(int j=0; j<m; j++)
        {
            if((i&(1<<j))>0)
            {
                rightmost[i]=j;
                break;
            }
        }
    }
    for(int i=1; i<(1<<m); i++)
    {
        for(int j=0; j<m; j++)
        {
            if((i&(1<<j))==0)
            {
                d[i][j]=d[i^(1<<rightmost[i])][j]+cnt[rightmost[i]][j];
                dist[i]+=d[i][j];
            }
        }
    }
    memset(dp, -1, sizeof(dp));
    cout<<get((1<<m)-1)<<endl;
}