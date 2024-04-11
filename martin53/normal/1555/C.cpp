#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[2][nmax];

int solve()
{
    scanf("%i",&n);

    for(int i=0;i<2;i++)
    {
        for(int j=1;j<=n;j++)
            scanf("%i",&inp[i][j]);

        inp[i][n+1]=0;
    }
    for(int j=1;j<=n;j++)
        inp[1][j]+=inp[1][j-1];

    for(int j=n;j>=1;j--)
        inp[0][j]+=inp[0][j+1];

    int outp=inp[0][1];

    for(int i=1;i<=n;i++)
        outp=min(outp,max(inp[0][i+1],inp[1][i-1]));

    return outp;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}