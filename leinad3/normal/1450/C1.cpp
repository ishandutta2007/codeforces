#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, B[3];
char A[310][310];
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        for(i=0;i<n;i++)scanf("%s", &A[i]);
        B[0]=B[1]=B[2]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j]=='X')B[(i+j)%3]++;
            }
        }
        if(B[0]<=B[1]&&B[0]<=B[2])
        {
            k=0;
        }
        else if(B[1]<=B[2])
        {
            k=1;
        }
        else
        {
            k=2;
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j]=='X'&&((i+j)%3)==k)A[i][j]='O';
                printf("%c", A[i][j]);
            }
            puts("");
        }
    }
}