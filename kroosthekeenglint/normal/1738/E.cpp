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
const int modo = 998244353;
int fact[100005];
int anti_fact[100005];
int power(int x,int y)
{
    if (y == 0)
    {
        return 1;
    }
    int t = power(x, y/2);
    t = (long long)t * t % modo;
    if (y % 2 == 1)
    {
        t = (long long)t * x % modo; 
    }
    return t;
}
int c(int n,int m)
{
    if ((m > n) || (m < 0))
    {
        return 0;
    }
    return (long long)fact[n] * anti_fact[m] % modo * anti_fact[n-m] % modo;
}
int calc(int l,int r)
{
    int i;
    int ans = 0;
    for (i=0;i<=min(l,r);i++)
    {
        ans = (ans + (long long)c(l,i) * c(r,i))%modo;
    }
    return ans;
}
int a[100005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    fact[0] = 1;
    anti_fact[0] = 1;
    for (i=1;i<=100000;i++)
    {
        fact[i] = (long long)fact[i-1] * i % modo;
        anti_fact[i] = power(fact[i], modo-2);
    }
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
        long long l_sum = 0;
        long long r_sum = 0;
        int l = 0;
        int r = n-1;
        int ans = 1;
        int tag = 0;
        for (i=0;;i++)
        {
            int cnt1 = 0, cnt2 = 0;
            for (;l<=r;)
            {
                if (a[l] == 0)
                {
                    l++;
                    cnt1 ++;
                }
                else if (a[r] == 0)
                {
                    r--;
                    cnt2++;
                }
                else
                {
                    break;
                }
            }
            if (l > r)
            {
                ans = ((long long)ans * power(2,(cnt1+cnt2+tag*2)-1)) % modo;
                break;
            }
            ans = (long long)ans * calc(cnt1+tag,cnt2+tag) % modo;
            tag = 1;
            l_sum = a[l];
            r_sum = 0;
            l++;
            for (;l<=r;)
            {
                if (l_sum == r_sum)
                {
                    break;
                }
                if (l_sum > r_sum)
                {
                    r_sum += a[r];
                    r--;
                }
                else
                {
                    l_sum += a[l];
                    l++;
                }
            }
            if (l_sum == r_sum)
            {
                continue;
            }
            else if (l > r)
            {
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}