#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=2*n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+2*n+1);

    for(int d=0;d<n;d++)
        printf("%i %i ",inp[n-d],inp[n+1+d]);

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