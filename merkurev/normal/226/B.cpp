#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;


long long q[100500],sum[100500];

long long my_min(long long a,long long b)
{
    if (a<b)
        return a;
    return b;
}

long long ANS[100500];

void main()
{
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%I64d",&q[i]);
    sort(q,q+n);
    reverse(q,q+n);

    sum[0] = q[0];
    for (int i=1;i<n;i++)
        sum[i] = sum[i-1] + q[i];

    int m;
    scanf("%d",&m);
    for (int j=0;j<m;j++)
    {
        long long k;
        scanf("%I64d",&k);

        if (ANS[k])
        {
            printf("%I64d ",ANS[k]);
            continue;
        }

        long long ans = 0;
        long long cur = 1;
        long long K = k;
        long long ke = 1;
        while (cur<n)
        {
            ans += ke * (sum[my_min(cur+K-1,n-1)] - sum[cur - 1]);
            cur += K;
            K *= k;
            ke++;
        }
        
        ANS[k] = ans;
        printf("%I64d ",ans);
    }

    


}