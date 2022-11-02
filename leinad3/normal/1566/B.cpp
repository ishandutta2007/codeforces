#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, s;
char A[100010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%s", &A);a=0;
        n=strlen(A);
        for(i=0;i<n;i++)
        {
            if(A[i]=='0'&&(i==0||A[i-1]=='1'))a++;
        }
        if(a>=2)a=2;
        printf("%d\n", a);
    }
}