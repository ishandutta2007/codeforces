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
int a[105];
long long fib[105];
long long sum_fib[105];
const int fib_len = 55;
int n;
bool dfs(int x, bool tag = false)
{
    if ((tag) && (a[n-1] > a[n-2]))
    {
        return false;
    }
    sort(a, a+n);
    a[n-1] -= fib[x];
    if (a[n-1] < 0)
    {
        return false;
    }
    if (x==0)
    {
        return true;
    }
    return dfs(x-1, true);
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    fib[0] = 1;
    fib[1] = 1;
    for (i=2;i<=54;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }
    sum_fib[0] = 1;
    for (i=1;i<=54;i++)
    {
        sum_fib[i] = sum_fib[i-1] + fib[i];
    }
    int zu,t;
    scanf("%d",&t);
    for (zu=0;zu<t;zu++)
    {
        scanf("%d",&n);
        int i;
        long long sum = 0;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            sum += a[i];
        }
        int k = lower_bound(sum_fib, sum_fib+fib_len, sum) - sum_fib;
        if (sum_fib[k] != sum)
        {
            puts("NO");
            continue;
        }
        if (dfs(k))
        {
            puts("YES");
        }
        else
        {
            puts("NO");
        }
    }
    return 0;
}