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
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long sum=0;
        bool flag=false;
        for (i=0;i<n;i++)
        {
            sum+=a[i];
            if (sum<0) break;
            if ((sum==0)&&(a[i]!=0))
            {
                if (!flag)
                {
                    flag=true;
                }
                else
                {
                    sum=-1;
                    break;
                }
            }
            else if ((sum==0)&&(i==0))
            {
                flag=true;
            }
        }
        if (sum!=0)
        {
            puts("NO"); 
        }
        else
        {
            puts("YES");
        }
    }
    return 0;
}