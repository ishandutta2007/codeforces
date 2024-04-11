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
int n;
long long val;
long long final_sum = 0;
int calc_l(int i)
{
    if (i < 0)
    {
        val = 0;
        final_sum = 0;
        return i;
    }
    long long sum = a[i];
    long long min_val = min(0ll, sum);
    for (;;)
    {
        if ((sum > 0) || (i < 0))
        {
            val = -min_val;
            final_sum = sum;
            return i;
        }
        i--;
        if (i < 0)
        {
            continue;
        }
        sum += a[i];
        min_val = min(min_val, sum);
    }
}
int calc_r(int i)
{
    if (i >= n)
    {
        val = 0;
        final_sum = 0;
        return i;
    }
    long long sum = a[i];
    long long min_val = min(0ll, sum);
    for (;;)
    {
        if ((sum > 0) || (i >= n))
        {
            val = -min_val;
            final_sum = sum;
            return i;
        }
        i++;
        if (i >= n)
        {
            continue;
        }
        sum += a[i];
        min_val = min(min_val, sum);
    }
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
        int k;
        scanf("%d%d",&n,&k);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        long long now_hp = a[k-1];
        int l=k-1, r=k-1;
        int l_min = calc_l(l-1);
        long long l_val = val;
        long long l_rew = final_sum;
        int r_min = calc_r(r+1);
        long long r_val = val;
        long long r_rew = final_sum;
        for (;;)
        {
            if ((l < 0) || (r > n))
            {
                puts("YES");
                break;
            }
            if (now_hp >= l_val)
            {
                now_hp += l_rew;
                l = l_min;
                l_min = calc_l(l-1);
                l_val = val;
                l_rew = final_sum;
                continue;
            }
            if (now_hp >= r_val)
            {
                now_hp += r_rew;
                r = r_min;
                r_min = calc_r(r+1);
                r_val = val;
                r_rew = final_sum;
                continue;
            }
            puts("NO");
            break;
        }
    }
    return 0;
}