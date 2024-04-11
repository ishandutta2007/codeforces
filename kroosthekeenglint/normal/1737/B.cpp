#include<set>
#include<map>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<math.h>
#include<time.h>
#include<vector>
#include<bitset>
#include<memory>
#include<utility>
#include<fstream>
#include<stdio.h>
#include<sstream>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
long long my_sqrt(long long x)
{
    long long l = 0, r = 1000000007;
    for (;l<=r;)
    {
        long long mid = (l+r)/2;
        if (mid * mid <= x)
        {
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return r;
}
long long calc(long long x)
{
    long long t = my_sqrt(x);
    long long ans = t * 3;
    if (x >= t * (t+1))
    {
        ans ++;
    }
    if (x >= t * (t+2))
    {
        ans ++;
    }
    return ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        long long a,b;
        scanf("%lld%lld",&a,&b);
        a--;
        printf("%lld\n",calc(b)-calc(a));
    }
    return 0;
}