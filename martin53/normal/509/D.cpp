#include<bits/stdc++.h>
using namespace std;
const int nmax=1e2+42;
int n,m;
long long w[nmax][nmax];
long long a[nmax],b[nmax];
int main()
{
scanf("%i%i",&n,&m);
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    scanf("%i",&w[i][j]);
long long k=0,d;
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
        for(int p=1;p<=n;p++)
            for(int q=1;q<=m;q++)
            {
                d=w[i][j]+w[p][q]-w[i][q]-w[p][j];
                d=abs(d);
                k=__gcd(d,k);
            }
for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(w[i][j]>=k&&k)
    {
        printf("NO\n");
        return 0;
    }
if(k==0)k=1e9+1;
//b1=0;
printf("YES\n");
for(int j=1;j<=m;j++)
    a[j]=w[1][j];
for(int i=2;i<=n;i++)
    b[i]=(w[i][1]-a[1]+k)%k;

printf("%lld\n",k);
for(int i=1;i<=n;i++)
    printf("%lld ",b[i]);printf("\n");
for(int i=1;i<=m;i++)
    printf("%lld ",a[i]);printf("\n");
return 0;
}