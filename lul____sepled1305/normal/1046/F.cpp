#include<stdio.h>
#include<string>
long int i,k,x,f,n,j,l,mm;
int c[50];
int m[50];
void summation()
{
    for(j=1;j<=49;j++)
    {
        c[j]=c[j]+m[j];
        if(c[j]>=10)
        {
            c[j]=c[j]%10;
            m[j+1]=m[j+1]+1;
            m[j]=0;
        }
    }
}
void convert(int k)
{
    for(l=1;l<=49;l++)
    {
        m[l]=k%10;
        k=k/10;
    }
}
void print()
{
    mm=0;
    for(i=49;i>=1;i--)
    {
        if(c[i] != 0)
        {
            mm=i;
            break;
        }
    }
    if(mm>0)
    {
        for(i=mm;i>=1;i--)
            printf("%d",c[i]);
    }
    else printf("0");
}
int main(){
    scanf("%ld",&n);
    long int a[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&a[i]);
    }
    scanf("%ld",&x);
    scanf("%ld",&f);
    f=x+f;
    for(i=1;i<=n;i++)
    {
        if(a[i]%f==0)
        {
            a[i]=a[i]/f;
        }
        else
        {
            if(a[i]%f>x)
            {
                a[i]=a[i]/f + 1;
            }
            else
            {
                a[i]=a[i]/f;
            }
        }
    }
    f=f-x;
    for(i=1;i<=n;i++)
    {
        convert(a[i]*f);
        summation();
    }
    print();
}