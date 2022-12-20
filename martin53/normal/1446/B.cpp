#include<bits/stdc++.h>
using namespace std;

const int nmax=5e3+42;

int sz[2];

string inp[2];

int dp[nmax][nmax];

int main()
{
    cin>>sz[0]>>sz[1];

    cin>>inp[0]>>inp[1];

    int outp=0;

    for(int i=sz[0]-1;i>=0;i--)
        for(int j=sz[1]-1;j>=0;j--)
        {
            if(inp[0][i]==inp[1][j])dp[i][j]=max(dp[i][j],dp[i+1][j+1]+2);
            dp[i][j]=max(dp[i][j],dp[i+1][j]-1);
            dp[i][j]=max(dp[i][j],dp[i][j+1]-1);

            outp=max(outp,dp[i][j]);
        }

    printf("%i\n",outp);
    return 0;
}