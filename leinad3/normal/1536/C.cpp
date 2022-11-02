#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c, A[500010], dp[500010];
char S[500010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);scanf("%s", &S);
        for(i=0;i++<n;)
        {
            if(S[i-1]=='D')A[i]=A[i-1]+1;
            else A[i]=A[i-1];
        }
        for(i=0;i++<n;)
        {
            a=A[i];b=i-A[i];c=__gcd(a, b);a=i/c;
            for(j=i-a;j>=0;j-=a)
            {
                if(1LL*A[j]*i==1LL*A[i]*j)
                {
                    dp[i]=dp[j]+1;break;
                }
            }printf("%d ", dp[i]);
        }puts("");
    }
}