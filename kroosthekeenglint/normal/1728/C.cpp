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
int calc(int x)
{
    int ans = 0;
    for (;x!=0;x=x/10)
    {
        ans ++;
    }
    return ans;
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
        int n;
        scanf("%d",&n);
        int i;
        map<int,int> a;
        int x;
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x]++;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&x);
            a[x]--;
        }
        map<int,int>::iterator ii;
        ii = a.end();
        int ans = 0;
        for (ii--;;ii--)
        {
            if ((*ii).second != 0)
            {
                ans += abs(ii->second);
                a[calc(ii->first)] += ii->second;
                ii->second = 0;
            }
            if (ii == a.begin())
            {
                break;
            }
        }
        printf("%d\n",ans); 
    }
    return 0;
}