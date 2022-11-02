#include<bits/stdc++.h>
using namespace std;
const int N = 110;
using pii = pair<int,int>;
int n,m;
int dp[N][N];
int qleft[N][N];
int qright[N][N];

int cost(int l, int r, int i)
{
    int j;
    int doub = 0;
    for(j=0; j<n; j++)
    {
        if(qleft[j][i]>=l && qright[j][i] <=r)
            doub++;
    }
    doub = doub*doub;
    return doub;

}

int main()
{
    int i,j,k,pointer;
    cin>>n>>m;
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            if(j>=i)
                dp[i][j] = -1;
            else
                dp[i][j] = 0;
        }
    }
    for(i=0; i<n; i++)
    {
        int a;
        pointer  = 1;
        cin>>a;
        for(j=0; j<a; j++)
        {
            int l,r;
            cin>>l>>r;
            while(pointer<=r)
            {
                qleft[i][pointer] = l;
                qright[i][pointer] = r;
                pointer++;
            }
        }
    }

    for(i=m;i>=1;i--)
    {
        for(j=i;j<=m;j++)
        {
            for(k=i;k<=j;k++)
            {
                dp[i][j] = max(dp[i][k-1]+dp[k+1][j]+cost(i,j,k),dp[i][j]);
            }
        }
    }
    cout<<dp[1][m]<<endl;
}