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
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("%d\n",n-1);
        if (n==1)
        {
            continue;
        }
        printf("%d %d\n",1,n);
        if ((a[0] + a[n-1])%2 == 1)
        {
            a[n-1] = a[0];
        }
        else
        {
            a[0] = a[n-1];
        }
        for (i=1;i<n-1;i++)
        {
            if ((a[i] + a[0]) % 2 == 1)
            {
                printf("%d %d\n",1,i+1);
            }
            else
            {
                printf("%d %d\n",i+1,n);
            }
        }
    } 
    return 0;
}