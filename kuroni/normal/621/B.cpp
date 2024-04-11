#include <bits/stdc++.h>

using namespace std;

main()
{
    long long ans = 0;
    int A[1999], B[1999], a, b, n, i;
    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    cin>>n;
    for (i = 0; i < n; i++)
    {
        cin>>a>>b;
        ans += A[a - b + 999];
        ans += B[a + b - 2];
        A[a - b + 999]++;
        B[a + b - 2]++;
    }
    printf("%I64d",ans);
}