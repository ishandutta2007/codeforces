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
int a[200005];
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
        int sum=0;
        int cnt_0=0;
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            if (x!=0)
            {
                a[sum++]=x;
            }
            else
            {
                cnt_0++;
            }
        }
        cnt_0=min(cnt_0,2);
        if (sum>=5)
        {
            puts("NO");
            continue;
        }
        for (i=0;i<cnt_0;i++)
        {
            a[sum++]=0;
        }
        int j,k,l;
        bool tag=true;
        for (i=0;i<sum;i++)
        {
            for (j=i+1;j<sum;j++)
            {
                for (k=j+1;k<sum;k++)
                {
                    int val=a[i]+a[j]+a[k];
                    for (l=0;l<sum;l++)
                    {
                        if (val==a[l])
                        {
                            break;
                        }
                    }
                    if (l==sum)
                    {
                        tag=false;
                    }
                }
            }
        }
        if (tag)
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}