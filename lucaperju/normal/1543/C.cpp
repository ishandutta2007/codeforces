
#include <bits/stdc++.h>
using namespace std;
long double d,ans;
// bruh moment
__float128 getmin (__float128 a, __float128 b)
{
    if(a<b)
        return a;
    else
        return b;
}
void bkt (__float128 a, __float128 b, __float128 c, __float128 p, __float128 coef1, __float128 coef2)
{
    if(a==0 && b==0)
    {
        ans+=coef1*p*coef2*c;
        return;
    }
    if(a==0)
    {
        ans+=coef1*p*coef2*c;
        __float128 ad=getmin(d,b);
        bkt(a,b-ad,c+ad,p+1.0,coef1,coef2*b);
        return;
    }
    if(b==0)
    {
        ans+=coef1*p*coef2*c;
        __float128 ad=getmin(d,a);
        bkt(a-ad,b,c+ad,p+1.0,coef1*a,coef2);
        return;
    }
    ans+=coef1*coef2*c*p;
    __float128 ad=getmin(d,a);
    __float128 adpe2=(__float128)ad/(__float128)2.0;
    bkt(a-ad,b+adpe2,c+adpe2,p+1.0,coef1*a,coef2);
    ad=getmin(d,b);
    adpe2=(__float128)ad/(__float128)2.0;
    bkt(a+adpe2,b-ad,c+adpe2,p+1.0,coef1,coef2*b);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n,l,r,t;
    cin>>t;
    while(t--)
    {
        long double a,b,c;
        cin>>a>>b>>c>>d;
        d=d;
        ans=0;
        bkt(a,b,c,1.0,1.0,1.0);
        cout<<fixed<<setprecision(9)<<ans<<'\n';
    }
    return 0;
}