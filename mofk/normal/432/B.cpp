#include<stdio.h>
int main(void)
{
    long int n,x[100005],y[100005],i,j,k,count[100005]={0};
    scanf("%ld",&n);
    for(i=1;i<=n;i++) scanf("%ld%ld",&x[i],&y[i]);
    for(j=1;j<=n;j++) count[x[j]]++;
    for(k=1;k<=n;k++)
    {
        printf("%ld %ld\n",n-1+count[y[k]],n-1-count[y[k]]);
    }
}