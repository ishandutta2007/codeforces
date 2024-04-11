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
int n;
int sum[1005];
bool check(int x)
{
    int i;
    for (i=0;i<x;i++)
    {
        if (sum[i] < x + i)
        {
            return false;
        }
    }
    return true;
}
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
        scanf("%d",&n);
        int i;
        for (i=0;i<n;i++)
        {
            sum[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            sum[x-1]++;
        }
        for (i=1;i<n;i++)
        {
            sum[i] += sum[i-1];
        }
        int l=0,r=n;
        for (;l<=r;)
        {
            int mid = (l+r)/2;
            if (check(mid))
            {
                l = mid+1;
            }
            else
            {
                r = mid-1;
            }
        }
        printf("%d\n",r);
    }
    return 0;
}