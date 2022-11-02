#include<stdio.h>
long long int i,a,b,k,n;
int main(){
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&k);
        if(k==0)
        {
            printf("0\n");
        }
        else if (k%2==0)
        {
            printf("%lld\n",(k/2)*(a-b));
        }
        else
        {
            printf("%lld\n",(k/2)*(a-b)+a);
        }
    }
    return 0;
}