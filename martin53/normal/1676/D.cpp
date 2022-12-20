#include<bits/stdc++.h>
using namespace std;

const int nmax=2e2+42;

int n,m,inp[nmax][nmax];

int solve()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%i",&inp[i][j]);

    int outp=0;

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            int cur=0;

            for(int p=1;i+p<=n&&j+p<=m;p++)
                cur+=inp[i+p][j+p];

            for(int p=1;i-p>=1&&j+p<=m;p++)
                cur+=inp[i-p][j+p];

            for(int p=1;i-p>=1&&j-p>=1;p++)
                cur+=inp[i-p][j-p];

            for(int p=1;i+p<=n&&j-p>=1;p++)
                cur+=inp[i+p][j-p];

            cur+=inp[i][j];

            outp=max(outp,cur);
        }

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