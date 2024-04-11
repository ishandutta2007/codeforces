#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, m, A[1010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        for(i=0;i++<n;)scanf("%d", &A[i]);
        printf("%d\n", 3*n);
        for(i=1;i<=n;i+=2)
        {
            printf("1 %d %d\n", i, i+1);
            printf("2 %d %d\n", i, i+1);
            printf("1 %d %d\n", i, i+1);
            printf("2 %d %d\n", i, i+1);
            printf("1 %d %d\n", i, i+1);
            printf("2 %d %d\n", i, i+1);
        }
    }
}