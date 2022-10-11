#include <bits/stdc++.h>
using namespace std;
main()
{
    long long d,k,a,b,t,ans;
    scanf("%I64d%I64d%I64d%I64d%I64d",&d,&k,&a,&b,&t);
    if ((k*a-k*b+t<=0)&&(d>k))
    {
        ans=(d/k)*k*a+(d/k-1)*t;
        ans+=(t+(d-k*(d/k))*a>(d-k*(d/k))*b)?(d-k*(d/k))*b:t+(d-k*(d/k))*a;
    }
    else if (d>k) ans = k*a+(d-k)*b; else ans=d*a;
    printf("%I64d",ans);
}