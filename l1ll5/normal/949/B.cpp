#include <cmath>
#include <queue>
#include <cstdio>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define N 100000
#define ll long long
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
ll n,q;
int main()
{
    scanf("%lld %lld",&n,&q);
    while(q--)
    {
        ll x;
        scanf("%lld",&x);
        while(1)
        {
            if(x&1)
            {
                printf("%lld\n",x/2+1);
                break ;
            }
            x=x+n-x/2;
        }
    }
}