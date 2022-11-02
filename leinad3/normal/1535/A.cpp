#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, c, d;
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if(max(a, b)>min(c, d)&&max(c, d)>min(a,b))puts("YES");else puts("NO");
    }
}