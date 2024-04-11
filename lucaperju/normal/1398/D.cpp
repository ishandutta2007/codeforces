#include <bits/stdc++.h>
using namespace std;
long long a[203],b[203],c[203];
bool cmp (long long a, long long b)
{
    return a>b;
}
long long dp[203][203][203];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,d,i,j,t;
    int A,B,C;
    cin>>A>>B>>C;
    for(i=1;i<=A;++i)
        cin>>a[i];
    for(i=1;i<=B;++i)
        cin>>b[i];
    for(i=1;i<=C;++i)
        cin>>c[i];
    sort(a+1,a+A+1,cmp);
    sort(b+1,b+B+1,cmp);
    sort(c+1,c+C+1,cmp);
    long long mx=0;
    for(int ca=0;ca<=A;++ca)
        for(int cb=0;cb<=B;++cb)
            for(int cc=0;cc<=C;++cc)
            {
                dp[ca][cb][cc]=0;
                if(ca*cb)
                    dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca-1][cb-1][cc]+a[ca]*b[cb]);
                if(ca*cc)
                    dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca-1][cb][cc-1]+a[ca]*c[cc]);
                if(cb*cc)
                    dp[ca][cb][cc]=max(dp[ca][cb][cc],dp[ca][cb-1][cc-1]+b[cb]*c[cc]);
                mx=max(mx,dp[ca][cb][cc]);
            }
    cout<<mx;
    return 0;
}