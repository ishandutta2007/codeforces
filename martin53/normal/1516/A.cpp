#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,k,inp[nmax];

void solve()
{
    scanf("%i%i",&n,&k);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<n;i++)
    {
        while(inp[i]&&k)
        {
            k--;
            inp[i]--;
            inp[n]++;
        }
    }

    for(int i=1;i<=n;i++)printf("%i ",inp[i]);printf("\n");
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