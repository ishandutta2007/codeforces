#include<bits/stdc++.h>
using namespace std;
int t, n, i, j, k, sum, kk, B[3][2];
char A[310][310];
int main()
{
    for(scanf("%d", &t);t--;)
    {
        scanf("%d", &n);
        for(i=0;i<n;i++)scanf("%s", &A[i]);
        B[0][0]=B[0][1]=B[1][0]=B[1][1]=B[2][0]=B[2][1]=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j]=='X')B[(i+j)%3][0]++;
                else if(A[i][j]=='O')B[(i+j)%3][1]++;
            }
        }
        sum=0;
        for(i=0;i<3;i++)for(j=0;j<2;j++)sum+=B[i][j];
        for(i=0;i<3;i++)
        {
            for(j=0;j<3;j++)
            {
                if(i!=j)
                {
                    if(B[i][0]+B[j][1]<=sum/3)
                    {
                        k=i;
                        kk=j;
                        goto w;
                    }
                }
            }
        }
        w:;
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(A[i][j]=='X'&&((i+j)%3)==k)A[i][j]='O';
                if(A[i][j]=='O'&&((i+j)%3)==kk)A[i][j]='X';
                printf("%c", A[i][j]);
            }
            puts("");
        }
    }
}