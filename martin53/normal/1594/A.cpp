#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        long long n;
        scanf("%lld",&n);
        printf("%lld %lld\n",1-n,n);
    }

    return 0;
}