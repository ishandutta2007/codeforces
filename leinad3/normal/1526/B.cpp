#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        for(i=0;i<=n;i+=11)
        {
            if((n-i)%111==0)
            {
                puts("YES");
                goto w;
            }
        }
        puts("NO");
        w:;
    }
}