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
    int t;
    scanf("%d",&t);
    int zu;
    for (zu=0;zu<t;zu++)
    {
        int n;
        scanf("%d",&n);
        int i;
        int last_not_zero = 0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]==0)
            {
                last_not_zero++;
            }
        }
        last_not_zero = max(last_not_zero, 1);
        for (i=0;i<n;i++)
        {
            int j;
            for (j=last_not_zero;j<n-i;j++)
            {
                a[j-1] = a[j] - a[j-1];
            }
            sort(a+last_not_zero - 1, a+n-i-1);
            last_not_zero --;
            for (;;)
            {
                if (last_not_zero == n-i-1)
                {
                    break;
                }
                if (a[last_not_zero]==0)
                {
                    last_not_zero ++;
                }
                else if (last_not_zero == 0)
                {
                    last_not_zero ++;
                }
                else
                {
                    break;
                }
            }
        }
        printf("%d\n",a[0]);
    }
    return 0;
}