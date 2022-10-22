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
long long sum_l[100005],sum_r[100005];
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
        int n;
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        sum_l[1]=0;
        for (i=1;i<n-1;i+=2)
        {
            sum_l[i+2] = sum_l[i] + max(0, max(a[i-1],a[i+1])-a[i]+1);
        }
        sum_r[n]=0;
        for (i=n-2;i>=1;i-=2)
        {
            sum_r[i] = sum_r[i+2] + max(0, max(a[i-1],a[i+1])-a[i]+1);
        }
        if (n%2==1)
        {
            printf("%lld\n",sum_r[1]);
        }
        else
        {
            long long min_ans = 12345678901234567ll;
            for (i=1;i<n;i+=2)
            {
                min_ans=min(min_ans,sum_l[i]+sum_r[i+1]);
            }
            printf("%lld\n",min_ans);
        }
    }
    return 0;
}