#include<stdio.h>
int main(void)
{
    long int n,i,a[100005],b[100005],happy=0;
    scanf("%ld",&n);
    for(i=1;i<=n;i++) {
        scanf("%ld%ld",&a[i],&b[i]);
        if(a[i]!=b[i]) happy=1;
    }
    if(happy==1) printf("Happy Alex");
    else printf("Poor Alex");
}