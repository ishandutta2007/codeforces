#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int kcz=998244353;
inline ll qpow(ll a,ll k)
{
    ll res=1;
    while(k)
    {
        if(k&1) res=res*a%kcz;
        if(k>>=1) a=a*a%kcz;
    }
    return res;
}
int main()
{
    int w,h;
    scanf("%d%d",&w,&h);
    printf("%lld\n",qpow(2,w+h));
    return 0;
}