#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long u,v;

    scanf("%lld%lld",&u,&v);

    printf("%lld %lld\n",u*u,-v*v);
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