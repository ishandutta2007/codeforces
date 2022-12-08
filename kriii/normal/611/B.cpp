#include <stdio.h>

long long count(long long lim)
{
    long long res = 0;
    for (int l=1;l<=62;l++){
        long long u = (1ll << l)-1;
        for (int j=0;j<l-1;j++){
            long long v = u - (1ll << j);
            if (v <= lim) res++;
        }
    }
    return res;
}

int main()
{
    long long l,r;
    scanf ("%lld %lld",&l,&r);
    printf ("%lld\n",count(r)-count(l-1));

    return 0;
}