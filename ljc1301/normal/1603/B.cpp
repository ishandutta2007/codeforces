#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int T;
    ll x,y;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld",&x,&y);
        if(x==y) printf("%lld\n",x);
        else if(x>y) printf("%lld\n",x+y);
        else if(y%x==0) printf("%lld\n",x);
        else
        {
            x=y/x*x;
            printf("%lld\n",(x+y)/2);
        }
    }
    return 0;
}