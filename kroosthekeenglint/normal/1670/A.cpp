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
        int neg=0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            if (a[i]<0)
            {
                neg++;
                a[i]=-a[i];
            }
        }
        for (i=0;i<neg;i++)
        {
            a[i]=-a[i];
        }
        for (i=1;i<n;i++)
        {
            if (a[i-1]>a[i])
            {
                break;
            }
        }
        if (i==n)
        {
            puts("Yes");
        }
        else
        {
            puts("No");
        }
    }
    return 0;
}