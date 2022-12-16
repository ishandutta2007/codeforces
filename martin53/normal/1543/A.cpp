#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long a,b;

    scanf("%lld%lld",&a,&b);

    if(a==b)
    {
        printf("0 0\n");
        return;
    }

    long long g=abs(a-b);

    printf("%lld %lld\n",g,min(a%g,g-a%g));
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