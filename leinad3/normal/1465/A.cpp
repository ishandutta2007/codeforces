#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b;
char A[500010];
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %s", &n, &A);
        a=0;
        for(i=n-1;i>=0;i--)
        {
            if(A[i]!=')')break;
            else a++;
        }
        if(a>n-a)puts("YES");
        else puts("NO");
    }
}