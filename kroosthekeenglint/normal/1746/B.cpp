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
        int l=0,r=n-1;
        int cnt = 0;
        for (;l<=r;)
        {
            if (a[l] == 0)
            {
                l++;
                continue;
            }
            if (a[r] == 1)
            {
                r--;
                continue;
            }
            swap(a[l],a[r]);
            cnt++;
        }
        printf("%d\n",cnt);
    }
    return 0;
}