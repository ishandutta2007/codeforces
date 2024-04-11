#include<bits/stdc++.h>
using namespace std;

set<long long> all;

bool solve()
{
    long long n;
    scanf("%lld",&n);

    for(long long a=1;2*a*a*a<=n;a++)
    {
        if(all.count(n-a*a*a))return 1;
    }

    return 0;
}

int main()
{
    for(long long i=1;i<=10000;i++)
        all.insert(i*i*i);

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}