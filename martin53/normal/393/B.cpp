#include<bits/stdc++.h>
using namespace std;
const int nmax=170+42;
int n,w[nmax][nmax];
double a[nmax][nmax],b[nmax][nmax];
int main()
{
scanf("%i",&n);
for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)scanf("%i",&w[i][j]);
for(int i=1;i<=n;i++)
    b[i][i]=0,a[i][i]=w[i][i];
for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        double x=1.0*(w[i][j]+w[j][i])/2;
        double p=w[i][j]-x;
        a[i][j]=x;
        a[j][i]=x;
        b[i][j]=p;
        b[j][i]=-p;
    }
for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)printf("%.9f ",a[i][j]);
    printf("\n");
}

for(int i=1;i<=n;i++)
{
    for(int j=1;j<=n;j++)printf("%.9f ",b[i][j]);
    printf("\n");
}

return 0;
}