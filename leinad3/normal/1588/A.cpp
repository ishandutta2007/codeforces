#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
main()
{
    for(scanf("%d", &t);t--;)
    {
        vector<int>A, B;
        scanf("%d", &n);
        for(i=0;i++<n;)
        {
            scanf("%d", &a);
            A.push_back(a);
        }
        for(i=0;i++<n;)
        {
            scanf("%d", &a);
            B.push_back(a);
        }
        sort(A.begin(), A.end());sort(B.begin(), B.end());
        for(i=0;i<n;i++)if(B[i]!=A[i]&&B[i]!=A[i]+1)
        {
            puts("NO");
            goto w;
        }
        puts("YES");
        w:;
    }
}