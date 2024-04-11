/*How can I solve problem his hard T^T*/
#include<bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int w;
int dp[2005][2005];
string s,t;
int quick_s[2005][30],quick_ts[2005][30];
 
int solve(int i,int j)
{
    if(i==0)
        return 0;
    else
    {
        int cur;
        if(dp[i-1][j]==INF)
            cur = solve(i-1,j)+1;
        else
            cur = dp[i-1][j]+1;
        if(s.at(i)==t.at(j))
        {
            if(dp[i-1][j-1]==INF)
                dp[i][j] = solve(i-1,j-1);
            else
                dp[i][j] = dp[i-1][j-1];
                
            return dp[i][j];
        }
        else if(j>=i)
        {
            int prob = t.at(j)-'a';
            if(quick_ts[j][prob] > quick_s[i][prob])
            {
                if(dp[i][j-1]==INF)
                    dp[i][j] = solve(i,j-1);
                else
                    dp[i][j] = dp[i][j-1];
            }
            else
            {
                if(dp[i-1][j]==INF)
                    dp[i][j] = solve(i-1,j)+1;
                else
                    dp[i][j] = dp[i-1][j]+1;
            }
 
            dp[i][j] = min(cur,dp[i][j]);
            return dp[i][j];
        }
        else
        {
            return 0;
        }
    }
}
 
int main()
{
    cin>>w;
    while(w--)
    {
        int n,i,j;
        cin>>n>>s>>t;
        for(i=0;i<=n;i++)
        {
            dp[0][i] = 0;
        }
        for(i=0;i<30;i++)
        {
            quick_s[0][i] = 0;
            quick_ts[0][i] = 0;
        }
        quick_s[0][s.at(0)-'a'] = 1;
        quick_ts[0][t.at(0)-'a'] = 1;
        for(i=1;i<n;i++)
        {
            for(j=0;j<30;j++)
            {
                if(j==s.at(i)-'a')
                    quick_s[i][j] = quick_s[i-1][j]+1;
                else
                    quick_s[i][j] = quick_s[i-1][j];
                if(j==t.at(i)-'a')
                    quick_ts[i][j] = quick_ts[i-1][j]+1;
                else
                    quick_ts[i][j] = quick_ts[i-1][j];
            }
        }
        bool pass = true;
        for(i=0;i<30;i++)
        {
            if(quick_s[n-1][i]!=quick_ts[n-1][i])
            {
                pass = false;
            }
        }
        for(i=1;i<n;i++)
        {
            for(j=i;j<n;j++)
            {
                dp[i][j] = INF;
            }
        }
        if(pass)
            cout<<solve(n-1,n-1)<<"\n";
        else
            cout<<-1<<"\n";
    }
    return 0;
}