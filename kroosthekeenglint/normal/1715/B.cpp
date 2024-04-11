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
long long a[100005];
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
        int n,k,b;
        long long s;
        scanf("%d%d%d%lld",&n,&k,&b,&s);
        long long min_val = (long long)k * b;
        long long max_val = (long long)k * b + (long long)n * (k - 1); 
        if ((s < min_val) || (s > max_val))
        {
            puts("-1");
            continue;
        }
        a[0] = min_val;
        s -= min_val;
        int i;
        for (i=1;i<n;i++)
        {
            a[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            a[i] += min((long long)k-1, s);
            s -= min((long long)k-1, s);
            printf("%lld ",a[i]);
        }
        printf("\n");
    }
    return 0;
}