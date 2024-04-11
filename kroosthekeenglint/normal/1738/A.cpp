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
int b[100005];
int c[100005];
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
        int cnt1 = 0, cnt2 = 0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (a[i] == 0)
            {
                b[cnt1++] = x;
            }
            else
            {
                c[cnt2++] = x;
            }
        }
        sort(b,b+cnt1);
        sort(c,c+cnt2);
        long long sum = 0;
        if (cnt1 == cnt2)
        {
            sum = -min(b[0], c[0]);
            for (i=0;i<cnt1;i++)
            {
                sum += b[i] * 2; 
            }
            for (i=0;i<cnt2;i++)
            {
                sum += c[i] * 2;
            }
        }
        else if (cnt1 > cnt2)
        {
            for (i=0;i<cnt2;i++)
            {
                sum += c[i] * 2;
                sum += b[cnt1 - i - 1] * 2;
            }
            for (i=0;i<cnt1-cnt2;i++)
            {
                sum += b[i]; 
            }
        }
        else if (cnt1 < cnt2)
        {
            for (i=0;i<cnt1;i++)
            {
                sum += b[i] * 2;
                sum += c[cnt2 - i - 1] * 2;
            }
            for (i=0;i<cnt2-cnt1;i++)
            {
                sum += c[i]; 
            }
        }
        printf("%lld\n",sum);
    } 
    return 0;
}