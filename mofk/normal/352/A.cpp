#include<stdio.h>
int main(void)
{
    int i,n,a[1005],zero=0,five=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        if(a[i]==0) zero++;
        else if(a[i]==5) five++;
    }
    if(five>=9&&zero>0) {
    for(i=1;i<=(five/9)*9;i++) printf("5");
    for(i=1;i<=zero;i++) printf("0");
    }
    else if(zero==0) printf("-1");
    else printf("0");
}