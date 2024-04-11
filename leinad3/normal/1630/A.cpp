#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &k);
        if(k<n-1)
        {
            printf("0 %d\n", n-1-k);
            for(i=1;i<n/2;i++)
            {
                if(i==k||n-1-i==k)printf("%d %d\n", k, n-1);
                else printf("%d %d\n", i, n-1-i);
            }
        }
        else
        {
            if(n==4)puts("-1");
            else
            {
                for(i=2;i<=n/2-3;i++)printf("%d %d\n", i, n-1-i);
                printf("0 %d\n1 %d\n", n/2-2, n/2);
                printf("%d %d\n%d %d\n", n/2-1, n/2+1, n-2, n-1);
            }
        }
    }
}