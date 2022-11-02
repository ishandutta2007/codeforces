#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
long long ask(int a, int b)
{
    printf("? %d %d\n", a, b);
    fflush(stdout);
    long long c;
    scanf("%lld", &c);
    return c;
}
long long get(long long x)
{
    long long a=0, b=1e9;
    while(a<b)
    {
        long long m=a+b>>1;
        if((m*(m-1))/2<x)a=m+1;
        else b=m;
    }
    return a;
}
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        a=0;b=n;
        long long x=ask(1, n);
        while(a<b)
        {
            int m=a+b>>1;
            if(x!=ask(1, m))a=m+1;
            else b=m;
        }
        long long y=ask(1, a-1);
        long long z=x-y;
        z++;
        long long w=get(x-(z*(z-1))/2);
        printf("! %lld %lld %d\n", a-z-w+1, a-z+1, a);
        fflush(stdout);
    }
}