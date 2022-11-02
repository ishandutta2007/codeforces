#include<stdio.h>
long int n,i,h,c;
int main(){
    scanf("%ld",&n);
    h=n/2;
    c=1;
    for(i=1;i<=n;i++)
    {
        if(n-i>=h)
        {
            printf("%d ",c);
        }
        else
        {
            if(h/2>0)
            {
                h=h/2;
                c=2*c;
                i--;
            }
            else if(3*c<=n)
            {
                printf("%d",3*c);
                break;
            }
            else
            {
                printf("%d",2*c);
                break;
            }
        }
    }
    return 0;
}