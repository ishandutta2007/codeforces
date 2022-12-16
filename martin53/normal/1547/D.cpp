#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int prv=0;

    for(int i=1;i<=n;i++)
    {
        int outp=0;

        for(int j=0;j<30;j++)
            if((prv&(1<<j))&&(inp[i]&(1<<j))==0)outp+=(1<<j);

        printf("%i ",outp);

        prv=outp^inp[i];
    }

    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        solve();
    }

    return 0;
}