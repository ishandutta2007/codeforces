#include<stdio.h>
int main(void)
{
    int n,a[105],max=0,min=100,i,b=0,c=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        if(a[i]>max){
            max=a[i];
            b=i;
        }
        if(a[i]<=min){
            min=a[i];
            c=i;
        }
    }
    if(b<c) printf("%d",b-1+n-c);
    else printf("%d",b-2+n-c);
}