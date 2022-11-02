#include<bits/stdc++.h>
using namespace std;
long long t, n, i, j, k, a, b;
bool f(long long x)
{
    long long y=x;
    while(y)
    {
        k=y%10;
        if(k&&x%k)
        {
            return false;
        }
        y/=10;
    }
    return true;
}
int main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%lld", &n);
        for(i=n;;i++)
        {
            if(f(i)){printf("%lld\n", i);break;}
        }
    }
}