#include<bits/stdc++.h>
using namespace std;
int R,G,B,i,j,k;
int r[200],g[200],b[200];
int dp[201][201][201];
int main()
{
    cin>>R>>G>>B;
    for(i=0;i<R;i++)
        cin>>r[i];
    for(i=0;i<G;i++)
        cin>>g[i];
    for(i=0;i<B;i++)
        cin>>b[i];
    sort(r,r+R);
    sort(b,b+B);
    sort(g,g+G);
    for(i=0;i<=R;i++)
    {
        for(j=0;j<=G;j++)
        {
            for(k=0;k<=B;k++)
            {
                if(j==0 && i==0)
                    continue;
                else
                {
                    if(i==0)
                    {
                        if(j>0 && k>0)
                            dp[i][j][k] = max(max(dp[i][j-1][k-1]+g[j-1]*b[k-1],dp[i][j][k-1]),dp[i][j-1][k]);
                    }
                    else
                    {
                        if(j==0 && k>0)
                        {
                            dp[i][j][k] = max(max(dp[i-1][j][k-1]+r[i-1]*b[k-1],dp[i][j][k-1]),dp[i-1][j][k]);
                        }
                        else if(k==0 && j>0)
                        {
                            dp[i][j][k] = max(max(dp[i-1][j-1][k]+r[i-1]*g[j-1],dp[i][j-1][k]),dp[i-1][j][k]);
                        }
                        else if(j>0 && k>0)
                        {
                            dp[i][j][k] = max(dp[i-1][j][k-1]+r[i-1]*b[k-1],dp[i][j][k]);
                            dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k-1]+g[j-1]*b[k-1]);
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+r[i-1]*g[j-1]);
                            dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]);
                            dp[i][j][k] = max(dp[i][j][k],dp[i][j-1][k]);
                            dp[i][j][k] = max(dp[i][j][k],dp[i][j][k-1]);
                        }
                    }
                }
            }
        }
    }
    cout<<dp[R][G][B];
}