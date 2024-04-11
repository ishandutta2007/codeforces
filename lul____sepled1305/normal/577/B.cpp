#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 1e3+10;
int n,m,i,j;
int a[N];
bool dp[M][M];

int main()
{
    cin>>n>>m;
    dp[0][0] = true;
    if(n>=m)
        cout<<"YES";
    else
    {
        for(i=0;i<n;i++)
            cin>>a[i];
        for(i=1;i<=n;i++)
        {
            if(a[i-1]==0)
                dp[m][n] =true;
            for(j=0;j<=m;j++)
            {
                if(dp[j][i-1]==true)
                {
                    dp[j][i] = true;
                    dp[((j+a[i-1])-1)%m+1][i] = true;
                }
            }
        }
        if(dp[m][n])
            cout<<"YES";
        else
            cout<<"NO";
    }
}