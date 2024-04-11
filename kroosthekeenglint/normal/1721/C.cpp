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
int b[200005];
int ans1[200005];
int ans2[200005];
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
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        int now = 0;
        for (i=0;i<n;i++)
        {
            for (;b[now]<a[i];now++) ;
            printf("%d ", b[now] - a[i]);
            if ((i!=n-1) && (a[i] > b[i+1]))
            {
                now = i+1;
            }
        }
        printf("\n");
        now = n-1;
        for (i=n-1;i>=0;i--)
        {
            ans2[i] = b[now] - a[i];
            if ((i!=0) && (a[i] > b[i-1]))
            {
                now = i-1;
            }
        }
        for (i=0;i<n;i++)
        {
            printf("%d ",ans2[i]);
        }
        printf("\n");
    }
    return 0;
}