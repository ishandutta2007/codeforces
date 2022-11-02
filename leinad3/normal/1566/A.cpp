#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, s;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d", &n, &s);
        a=n-((n+1)/2)+1;
        printf("%d\n", s/a);
    }
}