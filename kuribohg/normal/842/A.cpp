#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
LL l,r,x,y,k;
int main()
{
    scanf("%lld%lld%lld%lld%lld",&l,&r,&x,&y,&k);
    for(LL i=x;i<=y;i++)
    {
        LL o=k*i;
        if(o>=l&&o<=r) {puts("YES");return 0;}
    }
    puts("NO");
    return 0;
}