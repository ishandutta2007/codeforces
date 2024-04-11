#include<bits/stdc++.h>
using namespace std;
long long i,j,k,n,m,maxi=0,hmax,counti,imax;
long long a[1010];
long long b[1010];

int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(i=1;i<=n;i++)
    {
        hmax=a[i];
        counti=0;
        for(j=i-1;j>=1;j--)
        {
            hmax=min(hmax,a[j]);
            counti+=hmax;
        }
        hmax=a[i];
        for(j=i;j<=n;j++)
        {
            hmax=min(hmax,a[j]);
            counti+=hmax;
        }
        if(counti>maxi)
        {
            maxi=counti;
            imax=i;
        }
    }
    hmax=a[imax];
    b[imax]=a[imax];
    for(i=imax-1;i>=1;i--)
    {
        hmax=min(hmax,a[i]);
        b[i]=hmax;
    }
    hmax=a[imax];
    for(i=imax+1;i<=n;i++)
    {
        hmax=min(hmax,a[i]);
        b[i]=hmax;
    }
    for(i=1;i<=n;i++)
    {
        printf("%d ",b[i]);
    }
}