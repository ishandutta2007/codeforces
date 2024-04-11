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
int a[2005];
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
        int max_val = 0, min_val = 1000;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            max_val = max(max_val, a[i]);
            min_val = min(min_val, a[i]);
        }
        int ans = max(max_val - a[0], a[n-1] - min_val);
        for (i=0;i<n;i++)
        {
            ans = max(ans, a[(i + n - 1)%n] - a[i]);
        }
        printf("%d\n",ans);
    } 
    return 0;
}