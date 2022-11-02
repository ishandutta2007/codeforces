#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, A[200010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);for(i=0;i++<n;)scanf("%d", &A[i]);
        sort(A+1, A+n+1);
        a=2e9, b=-1;
        for(i=0;++i<n;)
        {
            if(a>A[i+1]-A[i])
            {
                a=A[i+1]-A[i];
                b=i;
            }
        }
        printf("%d ", A[b]);
        for(i=b+2;i<=n;i++)printf("%d ", A[i]);
        for(i=1;i<=b-1;i++)printf("%d ", A[i]);
        printf("%d\n", A[b+1]);
    }
}