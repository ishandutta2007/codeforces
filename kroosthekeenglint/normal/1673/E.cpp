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
int a[1<<20];
int b[1<<20];
int c[1<<20];
map<pair<int,int>, bool> ma;
bool check(int n,int m)
{
    if (n<m)
    {
        m=n;
    }
    if (ma.find(make_pair(n,m))!=ma.end())
    {
        return ma[make_pair(n,m)];
    }
    bool ans=true;
    int i;
    long long sum=0;
    for (i=1;i<=m;i++)
    {
        sum+=c[n-i+1];
        sum-=c[i];
        if (sum==0) ans^=1;
    }
    ma[make_pair(n,m)]=ans;
    return ans;
}
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int i;
    for (i=1;i<(1<<20);i++)
    {
        int j;
        for (j=0;j<20;j++)
        {
            if ((i>>j)&1)
            {
                break;
            }
        }
        c[i]=j;
    }
    int n,k;
    scanf("%d%d",&n,&k);
    for (i=0;i<n;i++)
    {
        scanf("%d",&b[i]);
    }
    for (i=0;i<n;i++)
    {
        int j;
        int current = b[i];
        for (j=0;j<n-k;j++)
        {
            int left_op = max(i-1,0) + max(n-2-(i+j),0);
            int left_pow = n-k-1-j;
            if (check(left_op, left_pow))
            {
                a[current]^=1;
            }
            if (i+j+1>=n)
            {
                break;
            }
            if (b[i+j+1]>=20)
            {
                break;
            }
            if ((long long)current * (1<<b[i+j+1]) >= (1<<20))
            {
                break;
            }
            current = current * (1<<b[i+j+1]);
        }
    }
    for (i=(1<<20)-1;i>0;i--)
    {
        if (a[i]==1) break;
    }
    for (;i>=0;i--)
    {
        printf("%d",a[i]);
    }
    printf("\n");
    return 0;
}