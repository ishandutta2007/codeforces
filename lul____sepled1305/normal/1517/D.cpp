#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 3e5;
int n,m,k;
int dp[500][500][11];
int val[500][500][4]; //UDLR

int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m-1;j++)
        {
            int a;
            cin>>a;
            //Set RL
            val[i][j][3] = a;
            val[i][j+1][2] = a;
        }
    }
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<m;j++)
        {
            int a;
            cin>>a;
            //Set UD
            val[i][j][1] = a;
            val[i+1][j][0] = a;
        }
    }
    if(k%2 == 1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<"-1 ";
            cout<<endl;
        }
        return 0;
    }

    k/=2;
    for(int l=1;l<=k;l++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mini = 1e9;
                if(i != 0)
                    mini = min(mini,dp[i-1][j][l-1] + 2*val[i][j][0]);
                if(i != n-1)
                    mini = min(mini,dp[i+1][j][l-1] + 2*val[i][j][1]);
                if(j != 0)
                    mini = min(mini,dp[i][j-1][l-1] + 2*val[i][j][2]);
                if(j != m-1)
                    mini = min(mini,dp[i][j+1][l-1] + 2*val[i][j][3]);
                dp[i][j][l] = mini;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<dp[i][j][k]<<' ';
        cout<<endl;
    }
    return 0;
}