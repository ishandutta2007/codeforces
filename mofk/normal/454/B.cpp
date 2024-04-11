#include<stdio.h>
int main(void)
{
    long int n,a[100005],i,flag=0,p;
    scanf("%ld",&n);
    for(i=1;i<=n;i++)
    { 
        scanf("%ld",&a[i]);
    }
    for(i=1;i<n;i++) if(a[i]>a[i+1]){
        flag++;
        p=i;
        break;
    }
    for(i++;i<n;i++) if(a[i]>a[i+1]){
        flag++;
        break;
    }
    if(flag==0) printf("0");
    else if(flag==2||a[n]>a[1]) printf("-1");
    else printf("%ld",n-p);
}