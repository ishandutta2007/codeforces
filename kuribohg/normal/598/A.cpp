#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long LL;
int T;
LL n,sum;
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        sum=n*(n+1)/2LL;
        LL x=1;
        sum-=2;
        while((x<<1)<=n)
        {
            x<<=1;
            sum-=x+x;
        }
        printf("%I64d\n",sum);
    }
    return 0;
}