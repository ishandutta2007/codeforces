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
int b[100005];
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
        int n,k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            b[i] = a[i];
        }
        a[n] = 1000000000;
        a[n+1] = 1000000000;
        sort(a,a+n);
        int ans = 0;
        if (k > 1)
        {
            ans = a[k-1] * 2;
        }
        int t = a[k-1];
        int cnt = 1;
        if ((k>=1)&&(a[k-2] == t))
        {
            cnt ++;
        }
        for (i=0;i<n;i++)
        {
            if (b[i] < t)
            {
                if ((i!=0) && (b[i-1] <= t))
                {
                    ans = a[k] * 2;
                }
                else if (i!=0)
                {
                    ans = max(ans, min(b[i-1], 2 * a[k]));
                }
                if ((i!=n-1) && (b[i+1] <= t))
                {
                    ans = a[k] * 2;
                }
                else if (i!=n-1)
                {
                    ans = max(ans, min(b[i+1], 2 * a[k]));
                }
            }
            else if (b[i] == t)
            {
                if ((i!=0) && ((b[i-1] < t) || ((b[i-1] == t) && (cnt == 2))))
                {
                    ans = a[k] * 2;
                }
                else if (i!=0)
                {
                    ans = max(ans, min(b[i-1], 2 * a[k]));
                }
                if ((i!=n-1) && ((b[i+1] < t) || ((b[i+1] == t) && (cnt == 2))))
                {
                    ans = a[k] * 2;
                }
                else if (i!=n-1)
                {
                    ans = max(ans, min(b[i+1], 2 * a[k]));
                }
            }
            else
            {
                if (i!=0)
                {
                    ans = max(ans, min(b[i-1], 2 * a[k-1]));
                    ans = max(ans, min(min(b[i],b[i-1]), 2 * a[k]));
                }
                if (i!=n-1)
                {
                    ans = max(ans, min(b[i+1], 2 * a[k-1]));
                    ans = max(ans, min(min(b[i],b[i+1]), 2 * a[k]));
                }
            }
        }
        if (ans >= 1000000000)
        {
            ans = 1000000000;
        }
        printf("%d\n",ans);
    }
    return 0;
}