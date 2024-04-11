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
int b_1,b_d,b_n;
int c_1,c_d,c_n;
int ans=0;
const int modo=1000000007;
int gcd(int x,int y)
{
    if (y==0)
    {
        return x;
    }
    return gcd(y,x%y);
}
void check(int d)
{
    if ((long long)d*b_d/gcd(d,b_d)!=c_d)
    {
        return;
    }
    int t=c_d/d;
    ans = (ans + (long long)t*t)%modo;
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
        scanf("%d%d%d",&b_1,&b_d,&b_n);
        scanf("%d%d%d",&c_1,&c_d,&c_n);
        long long b_max,c_max;
        b_max=b_1+(long long)(b_n-1)*b_d;
        c_max=c_1+(long long)(c_n-1)*c_d;
        if ((c_1 < b_1) || (c_max > b_max))
        {
            puts("0");
            continue;
        }
        if (c_d % b_d != 0)
        {
            puts("0");
            continue;
        }
        if ((b_1 - c_1)% b_d != 0)
        {
            puts("0");
            continue;
        }
        if ((c_1 - c_d < b_1) || (c_max + c_d > b_max))
        {
            puts("-1");
            continue;
        }
        int i;
        ans=0;
        for (i=1;i*i<=c_d;i++)
        {
            if (c_d%i==0)
            {
                check(i);
                if (i*i!=c_d)
                {
                    check(c_d/i);
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}