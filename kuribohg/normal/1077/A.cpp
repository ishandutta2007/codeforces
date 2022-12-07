#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T,n,a,b;
LL ans;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&n);
        if(n%2==0) ans=(LL)(n/2)*(a-b);
        else ans=(LL)(n/2)*(a-b)+a;
        printf("%lld\n",ans);
    }
    return 0;
}