#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[1000010], m;
long long B[1000010];
int C[1000010], D[1000010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &m);
        for(i=0;i++<n;)scanf("%d", &A[i]);
        for(i=0;i<n;i++)B[i]=0,C[i]=2e9,D[i]=0;
        a=0;
        for(i=0;i++<m;)
        {
            scanf("%d", &b);
            if(a==0)a=b;
            else a=__gcd(a, b);
        }
        long long ans=0;
        if(a==1)
        {
            for(i=0;i++<n;)ans+=abs(A[i]);
            printf("%lld\n", ans);
            continue;
        }
        for(i=0;i++<n;)
        {
            b=i%a;
            if(A[i]>0)
            {
                B[b]+=A[i];
                C[b]=min(C[b], A[i]);
                continue;
            }
            B[b]+=(-A[i]);
            C[b]=min(C[b], -A[i]);
            D[b]++;
        }
        for(i=0;i<a;i++)
        {
            if(D[i]%2==0)ans+=B[i];
            else ans+=(B[i]-2*C[i]);
        }
        long long ans2=0;
        for(i=0;i<a;i++)
        {
            if(D[i]%2==1)ans2+=B[i];
            else ans2+=(B[i]-2*C[i]);
        }
        printf("%lld\n", max(ans, ans2));
    }
}