#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, A[55];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);n*=2;
        for(i=0;i++<n;)scanf("%d", &A[i]);
        sort(A+1, A+n+1);
        for(i=1;i<=n/2;i++)printf("%d %d ", A[i], A[n/2+i]);puts("");
    }
}