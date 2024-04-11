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
        int cnt = 0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            if (a[i] == 0)
            {
                continue;
            }
            if (cnt >= a[i])
            {
                printf("-1\n");
                break;
            }
            cnt += a[i];
        }
        if (i!=n)
        {
            continue;
        }
        for (i=0;i<n;i++)
        {
            printf("%d ",a[i]);
            a[i+1] += a[i];
        }
        printf("\n");
    }
    return 0;
}