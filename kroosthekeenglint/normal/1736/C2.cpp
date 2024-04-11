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
int a[200005];
long long sum[200005];
int last_val[200005];
struct query
{
    int p;
    int x;
    int id;
    long long ans;
};
query b[200005];
bool cmp1(const query &a,const query &b)
{
    return a.x<b.x;
}
bool cmp2(const query &a,const query &b)
{
    return a.id<b.id;
}
struct pos
{
    int val;
    int i;
    friend bool operator < (const pos &a, const pos &b)
    {
        return a.val < b.val;
    }
};
pos c[200005];
long long if_sum[200005];
long long v_sum[200005];
int limit[200005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        a[i]--;
        a[i]-=i;
        c[i].val = min(0,a[i]);
        c[i].i = i;
    }
    int val = 0;
    for (i=0;i<n;i++)
    {
        last_val[i] = val;
        val = min(val, a[i]);
        sum[i+1] = val + sum[i];
    }
    for (i=0;i<n;i++)
    {
        if (a[i] >= last_val[i])
        {
            if_sum[i] = sum[n];
            limit[i] = -1;
        }
        else
        {
            int j;
            int val = last_val[i];
            //assume a[i] = 0;
            long long this_sum = sum[i];
            for (j=i+1;j<=n;j++)
            {
                this_sum += val;
                v_sum[j] = this_sum;
                val = min(val, a[j]);
                if ((val < a[i])||(j==n))
                {
                    break;
                }
            }
            if_sum[i] = sum[n] - sum[j] + v_sum[j];
            limit[i] = j;
        }
    }
    int q;
    scanf("%d",&q);
    for (i=0;i<q;i++)
    {
        scanf("%d",&b[i].p);
        scanf("%d",&b[i].x);
        b[i].x-=b[i].p;
        b[i].x=min(b[i].x,0);
        b[i].p--;
        b[i].id=i;
    }
    sort(b,b+q,cmp1);
    sort(c,c+n);
    set<int> s;
    s.insert(n);
    int j = 0;
    for (i=0;i<q;i++)
    {
        for (;j<n;j++)
        {
            if (c[j].val <= b[i].x)
            {
                s.insert(c[j].i);
            }
            else
            {
                break;
            }
        }
        set<int>::iterator ii = s.upper_bound(b[i].p);
        int p = (*ii);
        long long ans = sum[b[i].p] + (long long)(p - b[i].p) * min(last_val[b[i].p], b[i].x);
        if (p > limit[b[i].p])
        {
            ans = ans + sum[n] - sum[p];
        }
        else
        {
            ans = ans + if_sum[b[i].p] - v_sum[p];
        }
        b[i].ans = ans + (long long)n * (n+1) / 2 ;
    }
    sort(b,b+q,cmp2);
    for (i=0;i<q;i++)
    {
        printf("%lld\n",b[i].ans);
    }
    return 0;
}