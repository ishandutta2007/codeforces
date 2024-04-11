#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long n,i,a[100000],sum[100000],cnt = 0,ans = 0;
    scanf("%I64d",&n);
    for (i=0;i<n;i++)
    {
        scanf("%I64d",&a[i]);
        sum[i]= sum[i-1] + a[i];
    }
    if ((sum[n-1] % 3 != 0) || (n < 3))
    {
        ans = 0;
    }
    else
    {
        int temp = sum[n-1]/3;
        for (i=n-2;i>0;i--)
        {
            if (sum[i]==2*temp) {cnt = cnt + 1;}
            if (sum[i-1]==temp) {ans = ans + cnt;}
        }
    }
    printf("%I64d",ans);
    return 0;
}