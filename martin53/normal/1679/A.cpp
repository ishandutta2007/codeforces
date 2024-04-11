#include<bits/stdc++.h>
using namespace std;

void solve()
{
    long long n;
    scanf("%lld",&n);

    if(n%2||n==2)
    {
        printf("-1\n");
        return;
    }

    long long high=n/4;
    long long low=n/6;

    if(n%6)low++;

    printf("%lld %lld\n",low,high);
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