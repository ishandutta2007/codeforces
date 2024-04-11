#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+42,kmax=35;
int n,f[nmax],w[nmax];
long long k;
int where[nmax][kmax];
long long sum[nmax][kmax];
int mini[nmax][kmax];
int main()
{
scanf("%i%lld",&n,&k);
for(int i=0;i<n;i++)scanf("%i",&f[i]);
for(int i=0;i<n;i++)scanf("%i",&w[i]);

for(int i=0;i<n;i++)where[i][0]=f[i];
for(int j=1;j<kmax;j++)
    for(int i=0;i<n;i++)
    where[i][j]=where[where[i][j-1]][j-1];

for(int i=0;i<n;i++)sum[i][0]=w[i];
for(int j=1;j<kmax;j++)
    for(int i=0;i<n;i++)
    sum[i][j]=sum[i][j-1]+sum[where[i][j-1]][j-1];

for(int i=0;i<n;i++)mini[i][0]=w[i];
for(int j=1;j<kmax;j++)
    for(int i=0;i<n;i++)
    mini[i][j]=min(mini[i][j-1],mini[where[i][j-1]][j-1]);

for(int i=0;i<n;i++)
{
    int pos=i;
    long long k_now=k;
    long long sum_now=0;
    int min_now=1e9;
    for(int j=kmax-1;j>=0;j--)
        if(((1LL<<j)&k_now))
        {
            k_now=k_now-(1LL<<j);
            sum_now=sum_now+sum[pos][j];
            min_now=min(min_now,mini[pos][j]);
            pos=where[pos][j];
        }
    printf("%lld %i\n",sum_now,min_now);
}
return 0;
}