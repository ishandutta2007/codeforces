#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    for(int i=2;i<=n/2+1;i++)printf("%i %i\n",inp[i],inp[1]);
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