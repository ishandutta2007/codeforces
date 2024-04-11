#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    ll n,l,r,mid,p;
    ll res,res2;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld",&n);
        l=1,r=n-3;
        while(l<r)
        {
            mid=(l+r)>>1;
            printf("? 1 %lld\n",mid+1),fflush(stdout);
            scanf("%lld",&res);
            if(res>0) r=mid;
            else l=mid+1;
        }
        printf("? %lld %lld\n",l,n),fflush(stdout);
        scanf("%lld",&res);
        printf("? %lld %lld\n",l+1,n),fflush(stdout);
        scanf("%lld",&res2);
        mid=res-res2+l;
        res-=(mid-l+1ll)*(mid-l)/2;
        // x(x-1)=t
        // (x-1/2)**2=t+.25
        r=mid+(int)sqrtl(res*2+(long double).25)+1;
        printf("! %lld %lld %lld\n",l,mid+1,r),fflush(stdout);
    }
    return 0;
}