#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n;
long long inp[nmax];

bool type(long long val)
{
    if(val==0)return 0;
    return 1;
}

bool test(long long g)
{
    for(int i=2;i<=n;i++)
        if(type(inp[i]%g)==type(inp[i-1]%g))return 0;
    return 1;
}

long long solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    long long g[2]={0,0};
    for(int i=1;i<=n;i++)
        g[i%2]=__gcd(g[i%2],inp[i]);

    for(int i=0;i<2;i++)
        if(test(g[i]))return g[i];

    return 0;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}