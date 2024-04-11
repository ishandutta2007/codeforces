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
int a[100005],b[100005];
int ans = 0;
bool cmp(int x,int y)
{
    return (x&ans) < (y&ans);
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
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]); 
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]); 
        }
        ans = 0;
        for (i=30;i>=0;i--)
        {
            ans ^= (1<<i);
            sort(a,a+n,cmp);
            sort(b,b+n,cmp);
            int j;
            for (j=0;j<n;j++)
            {
                if (((a[j] ^ b[n-j-1]) & ans) != ans)
                {
                    ans ^= (1<<i);
                    break;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}