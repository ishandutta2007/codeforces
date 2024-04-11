#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k;
    scanf("%lld%lld",&n,&k);
    if(n>=k-1) printf("%lld",(k-1)/2);
    else
    {
        if(2*n+2-k>=3) printf("%lld",(2*n+1-k)/2);
        else printf("0");
    }
}