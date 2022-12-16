#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int inp[nmax];

int solve()
{
    int n;
    scanf("%i",&n);

    for(int i=1;i<=n;i++)inp[i]=i;

    printf("%i\n",n);

    for(int i=1;i<=n;i++)
    {
        swap(inp[i],inp[1]);

        for(int j=1;j<=n;j++)printf("%i ",inp[j]);
        printf("\n");
    }
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