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
long long l[200005],r[200005];
int req_l[200005],req_r[200005];
int p[200005];
int ans[200005];
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
        for (i=1;i<n;i++)
        {
            scanf("%d",&p[i]);
            p[i]--;
        }
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&req_l[i],&req_r[i]);
            l[i]=0;
            r[i]=0;
            ans[i]=0;
        }
        for (i=n-1;i>=0;i--)
        {
            if ((req_l[i]<=r[i])&&(l[i]<=req_r[i]))
            {
                l[i]=0;
                r[i]=min(r[i],(long long)req_r[i]);
            }
            else
            {
                ans[i]++;
                l[i]=0;
                r[i]=req_r[i];
            }
            if (i!=0)
            {
                ans[p[i]]+=ans[i];
                l[p[i]]+=l[i];
                r[p[i]]+=r[i];
            }
        }
        printf("%d\n",ans[0]);
    }
    return 0;
}