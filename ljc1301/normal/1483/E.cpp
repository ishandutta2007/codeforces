#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const double k=(-1+sqrt(17))/8; // sqrt((1-k)/4)=k
const double k=(3-sqrt(5))/2; // (1-k)**2=k
ll l,r,mid,s;
inline bool check(ll k)
{
    char res[50];
    if(k>100000000000000) return 0;
#ifdef DEBUG
    printf("%lld ",s);
#endif
    printf("? %lld\n",k),fflush(stdout);
    scanf("%s",res);
    assert(res[1]!='i');
    if(res[0]=='L') { s+=k; return 1; }
    s-=k; return 0;
}
int main()
{
    int T;
    ll mid,t;
    double x;
    scanf("%d",&T);
    while(T--)
    {
        s=1;
        for(l=1;check(l);l<<=1);
        r=l-1,l>>=1;
        r=min(r,100000000000000ll);
        while(l<r)
        {
            // mid=(l+r+1)>>1;
            // if(s<mid)
            // {
            //    mid=min(l+1+(ll)((r-l)*k),(l+r+1)>>1);
            //    while(s<mid) check(l);
            // }
            // mid=l+1+(ll)((r-l)*k);
            while(s</*mid*/r)
                if(!check(max(l,t=s)))
                    break;
            if(s</*mid*/r) { r=t-1; continue; }
            x=1.*s/l;
            mid=min(l+1+(ll)(pow(.5,1+1/x)*(r-l)),(l+r+1)>>1);
            if(check(mid)) l=mid;
            else r=mid-1;
        }
        printf("! %lld\n",l),fflush(stdout);
    }
    return 0;
}