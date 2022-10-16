#include<stdio.h>
int main(void)
{
    long int i,n,a=0,b=0,sum=0,suma=0,sumb=0;
    int t[100005];
    scanf("%ld",&n);
    for(i=1;i<=n;i++) 
    {
        scanf("%d",&t[i]);
        sum+=t[i];
    }
    for(i=1;i<=n;i++)
    {
        suma+=t[i];
        a++;
        if(2*suma>=sum)
        {
            suma-=t[i];
            a--;
            break;
        }
    }
    for(i++;i<=n;i++)
    {
        sumb+=t[i];
        b++;
    }
    if(suma>sumb) b++;
    else a++;
    printf("%ld %ld",a,b);
}