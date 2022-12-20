#include<bits/stdc++.h>
using namespace std;

const int inf=1e9;

void solve()
{
    long long a,b,c;

    scanf("%lld%lld%lld",&a,&b,&c);

    printf("%lld %lld %lld\n",inf*b+a,b,c);
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