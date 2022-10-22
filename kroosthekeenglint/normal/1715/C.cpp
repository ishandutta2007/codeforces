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
int a[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    long long ans = 0;
    for (i=1;i<n;i++)
    {
        if (a[i] != a[i-1])
        {
            ans += (long long)i * (n-i);
        }
    }
    ans += (long long)n * (n+1) / 2;
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        if ((x!=0)&&(a[x] != a[x-1]))
        {
            ans -= (long long)x * (n-x);
        }
        if ((x!=n-1)&&(a[x] != a[x+1]))
        {
            ans -= (long long)(x+1) * (n-x-1);
        }
        a[x] = y;
        if ((x!=0)&&(a[x] != a[x-1]))
        {
            ans += (long long)x * (n-x);
        }
        if ((x!=n-1)&&(a[x] != a[x+1]))
        {
            ans += (long long)(x+1) * (n-x-1);
        }
        printf("%lld\n",ans);
    }
    return 0;
}