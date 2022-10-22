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
long long sum[200005][15];
int a[200005];
int p[15];
multiset<long long> s;
long long get_max()
{
    multiset<long long>::iterator ii = s.end();
    ii --;
    return (*ii);
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
        int n,q;
        scanf("%d%d",&n,&q);
        int temp_n = n;
        int i;
        int p_cnt = 0;
        for (i=2;i*i<=temp_n;i++)
        {
            if (temp_n%i==0)
            {
                p[p_cnt++] = i;
                for (;temp_n%i==0;)
                {
                    temp_n/=i;
                }
            }
        }
        if (temp_n!=1)
        {
            p[p_cnt++] = temp_n;
        }
        for (i=0;i<n;i++)
        {
            int j;
            for (j=0;j<p_cnt;j++)
            {
                sum[i][j] = 0;
            }
        }
        for (i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            int j;
            for (j=0;j<p_cnt;j++)
            {
                int t = n / p[j];
                sum[i%t][j] += a[i];
            }
        }
        s.clear();
        for (i=0;i<p_cnt;i++)
        {
            int t = n / p[i];
            int j;
            for (j=0;j<t;j++)
            {
                sum[j][i] *= t;
                s.insert(sum[j][i]);
            }
        }
        printf("%lld\n",get_max());
        for (i=0;i<q;i++)
        {
            int k,x;
            scanf("%d%d",&k,&x);
            k--;
            int j;
            for (j=0;j<p_cnt;j++)
            {
                int t = n / p[j];
                s.erase(s.find(sum[k%t][j]));
                sum[k%t][j] -= (long long)t * a[k];
                sum[k%t][j] += (long long)t * x;
                s.insert(sum[k%t][j]);
            }
            a[k] = x;
            printf("%lld\n",get_max());
        }
    }
    return 0;
}