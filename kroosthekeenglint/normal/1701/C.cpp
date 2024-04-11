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
int n,m;
int jobs[200005];
bool check(int mid)
{
    int i;
    long long sum = 0;
    for (i=0;i<n;i++)
    {
        if (jobs[i] > mid)
        {
            sum += (jobs[i] - mid);
        }
        else
        {
            sum -= (mid - jobs[i]) / 2;
        }
    }
    return sum<=0;
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
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            jobs[i] = 0;
        }
        for (i=0;i<m;i++)
        {
            int x;
            scanf("%d",&x);
            x--;
            jobs[x]++;
        }
        int l=0,r=2*m;
        for (;l<=r;)
        {
            int mid = (l+r)/2;
            if (check(mid))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        printf("%d\n",l);
    }
    return 0;
}