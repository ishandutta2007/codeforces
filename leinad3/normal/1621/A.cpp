#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &k);
        if((n+1)/2<k)
        {
            puts("-1");
            continue;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(i<2*k&&i%2==0&&i==j)printf("R");
                else printf(".");
            }
            puts("");
        }
    }
}