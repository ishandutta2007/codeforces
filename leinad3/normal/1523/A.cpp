#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, a, b, m, A[1010], B[1010];
char S[1010];
main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d %d %s", &n, &m, &S);
        for(i=0;i++<n;)A[i]=S[i-1]-'0';A[0]=A[n+1]=0;
        m=min(m, n);
        while(m--)
        {
            for(i=0;i++<n;)B[i]=0;
            for(i=0;i++<n;)
            {
                int a=A[i-1]+A[i+1];
                if(a==1)B[i]=1;
                else B[i]=A[i];
            }
            for(i=0;i++<n;)A[i]=B[i];
        }
        for(i=0;i++<n;)printf("%d", A[i]);
        puts("");
    }
}