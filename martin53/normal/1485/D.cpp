#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,G=720720;

int n,m,inp[nmax][nmax];

int main()
{
    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf("%i",&inp[i][j]);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if((i+j)%2==0)printf("%i ",G);
            else printf("%i ",G-inp[i][j]*inp[i][j]*inp[i][j]*inp[i][j]);
        }

        printf("\n");
    }

    return 0;
}