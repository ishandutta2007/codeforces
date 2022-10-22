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
int b[200005];
int c[200005];
int d[200005];
int vis[200005];
const int modo=998244353;
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
        int n,s;
        scanf("%d%d",&n,&s);
        int i;
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&b[i]);
        }
        for (i=1;i<=n;i++)
        {
            vis[i]=0;
        }
        int sum=0;
        for (i=0;i<n;i++)
        {
            if (b[i]==-1)
            {
                c[sum++]=a[i]-s;
            }
            else
            {
                vis[b[i]]=1;
                if (a[i]-s>b[i])
                {
                    break;
                }
            }
        }
        if (i!=n)
        {
            puts("0");
            continue;
        }
        sort(c,c+sum);
        int sum2=0;
        for (i=1;i<=n;i++)
        {
            if (!vis[i])
            {
                d[sum2++]=i;
            }
        }
        int j=sum;
        int p=1;
        for (i=sum-1;i>=0;i--)
        {
            for (;j!=0;)
            {
                if (d[j-1]>=c[i])
                {
                    j--;
                }
                else
                {
                    break;
                }
            }
            int cnt=(sum-j);
            cnt-=(sum-i-1);
            p=(long long)p*cnt%modo;
        }
        printf("%d\n",p); 
    }
    return 0;
}