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
int a[1<<18];
long long sum[1<<9];
long long l_max[1<<9][1<<9];
long long r_max[1<<9][1<<9];
long long max_sum[1<<9][1<<9];
int temp[1<<9];
int main()
{
    #ifdef absi2011
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n;
    scanf("%d",&n);
    int i;
    for (i=0;i<(1<<n);i++)
    {
        scanf("%d",&a[i]);
    }
    int block_n = n/2;
    int block_num = n - block_n;
    for (i=0;i<(1<<block_n);i++)
    {
        int j;
        for (j=0;j<(1<<block_num);j++)
        {
            int l;
            for (l=0;l<(1<<block_n);l++)
            {
                temp[l] = a[(j<<block_n)^l^i];
            }
            l_max[j][i] = 0;
            long long sums = 0;
            for (l=0;l<(1<<block_n);l++)
            {
                sums += temp[l];
                l_max[j][i] = max(l_max[j][i], sums);
            }
            sum[j] = sums;
            sums = 0;
            r_max[j][i] = 0;
            for (l=(1<<block_n)-1; l>=0;l--)
            {
                sums += temp[l];
                r_max[j][i] = max(r_max[j][i], sums);
            }
            sums = 0;
            max_sum[j][i] = 0;
            for (l=(1<<block_n)-1; l>=0;l--)
            {
                sums += temp[l];
                if (sums < 0)
                {
                    sums = 0;
                }
                max_sum[j][i] = max(max_sum[j][i], sums);
            }
        }
    }
    int q;
    scanf("%d",&q);
    int small_xor = 0, block_xor = 0;
    for (i=0;i<q;i++)
    {
        int x;
        scanf("%d",&x);
        if (x < block_n)
        {
            small_xor ^= (1<<x);
        }
        else
        {
            block_xor ^= (1<<(x - block_n));
        }
        int j;
        long long max_ans = 0;
        long long sums = 0;
        for (j=0;j<(1<<block_num);j++)
        {
            int cur = j^block_xor;
            max_ans = max(max_ans, max_sum[cur][small_xor]);
            max_ans = max(max_ans, sums + l_max[cur][small_xor]);
            sums = max(sums + sum[cur], r_max[cur][small_xor]);
        }
        printf("%lld\n",max_ans);
    }
    return 0;
}