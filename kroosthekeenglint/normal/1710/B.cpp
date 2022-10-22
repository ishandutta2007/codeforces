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
int d[600005];
long long sum1[600005];
long long sum2[600005];
int x[200005],p[200005];
int m;
bool check(int x,int p,int i)
{
    long long left_rain = sum2[i] - max(0, p - abs(x - d[i]));
    return left_rain <= m;
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
        scanf("%d%d",&n,&m);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d%d",&x[i],&p[i]);
            d[i*3] = x[i];
            d[i*3+1] = x[i] - p[i];
            d[i*3+2] = x[i] + p[i];
        }
        sort(d,d+n*3);
        int new_id = unique(d,d+n*3) - d;
        for (i=0;i<new_id;i++)
        {
            sum1[i] = 0;
            sum2[i] = 0;
        }
        for (i=0;i<n;i++)
        {
            sum1[lower_bound(d,d+new_id,x[i]-p[i])-d] ++;
            sum1[lower_bound(d,d+new_id,x[i]+p[i])-d] ++;
            sum1[lower_bound(d,d+new_id,x[i])-d] -= 2;
        }
        int cnt = 0;
        long long sum = 0;
        int max_id = 0;
        for (i=0;i<new_id;i++)
        {
            if (cnt != 0)
            {
                sum = sum + (d[i] - d[i-1]) * (long long)cnt;
            }
            cnt += sum1[i];
            sum2[i] = sum;
            if (sum2[i] > sum2[max_id])
            {
                max_id = i;
            }
        }
        int l_max = max_id;
        for (i=max_id ; i>=0; i--)
        {
            if ((sum2[i] > m) && (sum2[i] - d[i] > sum2[l_max] - d[l_max]))
            {
                l_max = i;
            }
        }
        int r_max = max_id;
        for (i=max_id ; i<new_id; i++)
        {
            if ((sum2[i] > m) && (sum2[i] + d[i] > sum2[r_max] + d[r_max]))
            {
                r_max = i;
            }
        }
        for (i=0;i<n;i++)
        {
            if ((check(x[i],p[i],l_max)) && (check(x[i],p[i],r_max)) && (check(x[i],p[i],max_id)))
            {
                printf("1");
            }
            else
            {
                printf("0");
            }
        }
        printf("\n");
    }
    return 0;
}