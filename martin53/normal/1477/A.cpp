#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

long long n,k,inp[nmax];

void solve()
{
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+n+1);

    long long g=0;
    for(int i=1;i<n;i++)
        g=__gcd(g,inp[i+1]-inp[i]);

    if(abs(inp[1]-k)%g)
    {
        printf("NO\n");
    }
    else
    {
        printf("YES\n");
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