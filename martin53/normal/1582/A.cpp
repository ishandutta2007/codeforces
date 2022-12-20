#include<bits/stdc++.h>
using namespace std;

int solve()
{
    long long a,b,c;

    scanf("%lld%lld%lld",&a,&b,&c);

    return (a+2*b+3*c)%2;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}