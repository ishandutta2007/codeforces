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
char a[200005];
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
        scanf("%s",a);
        int n=strlen(a);
        int i;
        int count_0=0;
        int count_1=0;
        for (i=0;i<n;i++)
        {
            if (a[i]=='0')
            {
                count_0++;
            }
            else
            {
                count_1++;
            }
        }
        int left_0=count_0;
        int left_1=count_1;
        int j=n;
        int ans=n+n;
        for (;j>=0;)
        {
            if (left_0==count_1-left_1)
            {
                break;
            }
            j--;
            if (a[j]=='0')
            {
                left_0--;
            }
            else
            {
                left_1--;
            }
        }
        for (i=0;i<=n;i++)
        {
            for (;j<n;)
            {
                if (left_0==count_1-left_1)
                {
                    break;
                }
                if (a[j]=='0')
                {
                    left_0++;
                }
                else
                {
                    left_1++;
                }
                j++;
            }
            if (left_0==count_1-left_1)
            {
                ans=min(ans,left_0);
            }
            if (a[i]=='0')
            {
                left_0--;
            }
            else
            {
                left_1--;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}