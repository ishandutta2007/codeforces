#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,a[510],f[510][510];
int getf(int l,int r)
{
    if(f[l][r]!=0) return f[l][r];
    if(r==l+1)
    {
        if(a[l]==a[r]) return f[l][r]=1;
        else return f[l][r]=2;
    }
    if(r==l) return f[l][r]=1;
    f[l][r]=1000000000;
    if(a[l]==a[r]) f[l][r]=min(f[l][r],getf(l+1,r-1));
    for(int k=l;k<r;k++)
        f[l][r]=min(f[l][r],getf(l,k)+getf(k+1,r));
    return f[l][r];
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    printf("%d\n",getf(1,n));
    return 0;
}