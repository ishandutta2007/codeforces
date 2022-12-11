#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,q;
    scanf("%lld%lld",&n,&q);
    for(ll i=0; i<q ; i++)
    {
        ll x,y;
        scanf("%lld%lld",&y,&x);
        ll num = x+n*(y-1);
        if((x+y)%2==0) printf("%lld\n",(num+1)/2);
        else printf("%lld\n",(n*n+1)/2+(num+1)/2);
    }
}