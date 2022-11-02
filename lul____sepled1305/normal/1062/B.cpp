#include<iostream>
#include<stdio.h>
using namespace std;
long int n,k,f,h,mul,m,r,y,i,mini,fuck;
int a[21];
int main(){
    mul=1;
    r=1;
    cin>>n;
    y=n;
    for(k=1;k<=n;k++)
    {
        if(k*k>=n)
        {
            break;
        }
    }
    for(i=1;i<=20;i++)
    {
        a[i]=0;
    }
    for(i=2;i<=n;i++)
    {
        if(n%i==0)
        {
            h=i;
            for(m=1;m<=k;m++)
            {
                if(n%h==0)
                {
                    h=h*i;
                }
                else
                {
                    break;
                }
            }
            n=i*n/h;
            a[r]=m-1;
            r++;
            mul=mul*i;
        }
        if(i==k && n==y)
        {
            a[1]=1;
        }
    }
    printf("%ld ",mul);
    a[0]=a[1];
    mini=a[1];
    for(i=1;i<=20;i++)
    {
        if(a[i]>0 && a[i]>a[0])
        {
            a[0]=a[i];
        }
        if(a[i]>0 && mini>a[i])
        {
            mini=a[i];
        }
    }
    fuck=2;
    if(y==1)
    {
        printf("0");
    }
    else if(mini==1 && a[0]==2)
    {
        printf("2");
    }
    else if(mini==1 && a[0]==1)
    {
        printf("0");
    }
    else if(mini==a[0])
    {
        for(m=1;m<=20;m++)
        {
            if(a[0]<fuck)
            {
                m++;
                break;
            }
            else if (a[0]==fuck)
            {
                break;
            }
            else
            {
                fuck=fuck*2;
            }
        }
        printf("%ld",m);
    }
    else
    {
        for(m=1;m<=20;m++)
        {
            if(a[0]<=fuck)
            {
                m++;
                break;
            }
            else
            {
                fuck=fuck*2;
            }
        }
        printf("%ld",m);
    }
}