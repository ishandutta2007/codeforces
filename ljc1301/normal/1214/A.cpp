#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n,d,e,ans=1e18;
    int i;
    scanf("%lld%lld%lld",&n,&d,&e),e*=5;
    for(i=0;i<=d;i++)
        if(n>=i*e)
            ans=min(ans,n-(i*e)-(n-i*e)/d*d);
    printf("%lld\n",ans);
    return 0;
}