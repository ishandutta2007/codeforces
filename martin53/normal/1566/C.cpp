#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;

char in[2][nmax];

int inp[nmax];

int dp[nmax];

bool used[nmax];

int solve()
{
    cin>>n;

    for(int i=0;i<2;i++)
        for(int j=1;j<=n;j++)cin>>in[i][j];

    for(int j=1;j<=n;j++)
    {
        if(in[0][j]==in[1][j])inp[j]=(in[0][j]-'0');
        else inp[j]=2;
    }

    int outp=0;

    for(int j=1;j<=n;j++)
        if(inp[j]==2)outp+=2;

    for(int j=1;j<=n;j++)used[j]=0;

    for(int j=1;j<n;j++)
        if(inp[j]+inp[j+1]==1)
        {
            outp+=2;
            used[j]=1;
            used[j+1]=1;

            j++;
        }

    for(int j=1;j<=n;j++)
        if(used[j]==0&&inp[j]==0)outp++;

    return outp;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }

    return 0;
}