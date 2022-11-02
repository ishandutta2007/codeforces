#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);a=0;
    for(i=0;i++<n;)scanf("%d", &b),a+=b;
        if(a<n)puts("1");
        else if(a==n)puts("0");
        else printf("%d\n", a-n);
    }
}