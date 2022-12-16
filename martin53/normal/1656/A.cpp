#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int mini=1,maxi=1;

    for(int i=2;i<=n;i++)
    {
        if(inp[mini]>inp[i])mini=i;

        if(inp[maxi]<inp[i])maxi=i;
    }

    printf("%i %i\n",mini,maxi);
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