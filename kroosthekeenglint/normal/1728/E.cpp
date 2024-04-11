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
int a[300005];
long long sum[300005];
int exgcd(int x,int y,long long &a,long long &b)
{
    if (y==0)
    {
        a = 1;
        b = 0;
        return x;
    }
    else
    {
        int ans = exgcd(y,x%y,a,b);
        long long new_a = b;
        long long new_b = a - b * (x/y);
        a = new_a;
        b = new_b;
        return ans;
    }
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    long long ans = 0;
    for (i=0;i<n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        ans+=y;
        a[i] = x - y;
    }
    sort(a,a+n);
    reverse(a,a+n);
    sum[0] = ans;
    int best_ans = -1;
    for (i=1;i<=n;i++)
    {
        if ((a[i] < 0) && (best_ans == -1))
        {
            best_ans = i - 1; 
        }
        sum[i] = sum[i-1] + a[i-1];
    }
    if (best_ans == -1)
    {
        best_ans = n;
    }
    int m;
    scanf("%d",&m);
    for (i=0;i<m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        long long a=1,b=1;
        long long ans = -1;
        int gcd = exgcd(x,y,a,b);
        if (n % gcd != 0)
        {
            puts("-1");
            continue;
        }
        x/=gcd;
        y/=gcd;
        int t_n = n / gcd;
        a *= t_n;
        b *= t_n;
        if (a<0)
        {
            long long t = a/y;
            if (a%y != 0)
            {
                t--;
            }
            t = -t;
            a += t*y;
            b -= t*x;
        }
        if (b<0)
        {
            long long t = b/x;
            if (b%x != 0)
            {
                t--;
            }
            t = -t;
            a -= t*y;
            b += t*x;
        }
        if (a < 0)
        {
            puts("-1");
            continue;
        }
        b = b + a / y * x; 
        a = a % y;
        long long t = best_ans / ((long long)gcd*x);
        t = t - a % y;
        t = t / y;
        a += t * y;
        b -= t * x;
        if (b >= 0)
        {
            ans = max(ans, sum[a * x * gcd]);
        }
        b = b + a / y * x; 
        a = a % y;
        t = best_ans / ((long long)gcd*x) + 1;
        t = t - a % y;
        t = (t - 1) / y + 1;
        a += t * y;
        b -= t * x;
        if (b >= 0)
        {
            ans = max(ans, sum[a * x * gcd]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}