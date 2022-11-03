#include <bits/stdc++.h>
using namespace std;
long long a1,a2,k1,k2,n,minn,maxx;
int main()
{
    int i;
    scanf("%lld%lld%lld%lld%lld",&a1,&a2,&k1,&k2,&n);
    maxx=-1e18,minn=1e18;
    for(i=0;i<=a1;i++)
        if(n-i*k1>=0 && n-i*k1-(a1-i)*(k1-1)<=k2*a2)
        {
            minn=min(minn,i+max(0ll,n-i*k1-(a1-i)*(k1-1)-(k2-1)*a2));
            maxx=max(maxx,i+min((n-i*k1)/k2,a2));
        }
    printf("%lld %lld\n",minn,maxx);
    return 0;
}