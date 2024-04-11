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
int k;
struct card
{
    int a[25];
    int operator [] (const int x) const
    {
        return a[x];
    }
    int & operator [] (const int x)
    {
        return a[x];
    }
    friend card operator + (const card &a, const card &b)
    {
        int i;
        card c;
        for (i=0;i<k;i++)
        {
            c[i] = (6 - a[i] - b[i]) % 3; 
        }
        return c;
    }
    long long code()
    {
        int i;
        long long sum = 0;
        for (i=0;i<k;i++)
        {
            sum = sum * 3 + a[i];
        }
        return sum;
    }
};
card a[1005];
set<long long> s;
int sum[1005];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d%d",&n,&k);
    int i;
    for (i=0;i<n;i++)
    {
        int j;
        for (j=0;j<k;j++)
        {
            scanf("%d",&a[i][j]);
        }
        s.insert(a[i].code());
    }
    for (i=0;i<n;i++)
    {
        int j;
        for (j=i+1;j<n;j++)
        {
            if (s.find((a[i]+a[j]).code()) != s.end())
            {
                sum[i] ++;
                sum[j] ++;
            }
        }
    }
    long long ans = 0;
    for (i=0;i<n;i++)
    {
        sum[i] /= 2;
        ans += sum[i] * (sum[i] - 1) / 2;
    }
    printf("%lld\n",ans); 
    return 0;
}