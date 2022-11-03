#include<bits/stdc++.h>
using namespace std;
long long T,l,r,i;
int main()
{
    scanf("%lld",&T);
    while (T--)
    {
        scanf("%lld%lld",&l,&r);
        for (i=1;(l|i)<=r;i<<=1) l|=i;
        printf("%lld\n",l);
    }
    return 0;
}