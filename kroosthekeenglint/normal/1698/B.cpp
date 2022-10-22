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
        int n,k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        if (k==1)
        {
            printf("%d\n",(n-1)/2); 
        }
        else
        {
            int sum=0;
            for (i=1;i<n-1;i++)
            {
                if (a[i]>a[i-1]+a[i+1])
                {
                    sum++; 
                }
            }
            printf("%d\n",sum); 
        }
    }
    return 0;
}