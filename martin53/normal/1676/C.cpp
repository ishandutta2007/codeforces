#include<bits/stdc++.h>
using namespace std;

const int nmax=1e2+42;

int n,m;

char inp[nmax][nmax];

int solve()
{
    cin>>n>>m;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)cin>>inp[i][j];

    int outp=1e9;

    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
        {
            int cur=0;

            for(int k=1;k<=m;k++)
                cur+=abs(inp[i][k]-inp[j][k]);

            outp=min(outp,cur);
        }

    return outp;
}

int main()
{
    int t;
    cin>>t;

    while(t)
    {
        t--;

        cout<<solve()<<"\n";
    }


    return 0;
}