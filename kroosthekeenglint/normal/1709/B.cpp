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
long long l_sum[100005];
long long r_sum[100005];
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
    for (i=1;i<n;i++)
    {
        l_sum[i] = l_sum[i-1] + max(a[i-1]-a[i],0);
    }
    for (i=n-1;i>=1;i--)
    {
        r_sum[i-1] = r_sum[i] + max(a[i]-a[i-1],0);
    }
    for (i=0;i<m;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        s--;
        t--;
        if (s<t)
        {
            printf("%lld\n",l_sum[t]-l_sum[s]);
        }
        else
        {
            printf("%lld\n",r_sum[t]-r_sum[s]);
        }
    }
    return 0;
}