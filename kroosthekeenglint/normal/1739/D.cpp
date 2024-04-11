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
int n,k;
int p[200005];
int depth[200005];
bool check(int x)
{
    int i;
    for (i=n-1;i>=0;i--)
    {
        depth[i] = 0;
    }
    int ans = 0;
    for (i=n-1;i>=0;i--)
    {
        if (depth[i] == x - 1)
        {
            if (p[i] == 0)
            {
                continue;
            }
            ans++;
            depth[i] = -1;
        }
        depth[p[i]] = max(depth[p[i]], depth[i] + 1);
    }
    return ans <= k;
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
        scanf("%d",&k);
        int i;
        for (i=1;i<n;i++)
        {
            scanf("%d",&p[i]);
            p[i]--;
        }
        int l=1,r=n;
        for (;l<=r;)
        {
            int mid = (l+r)/2;
            if (check(mid))
            {
                r = mid-1;
            }
            else
            {
                l = mid+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}