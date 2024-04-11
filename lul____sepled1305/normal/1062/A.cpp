#include<iostream>
#include<stdio.h>
using namespace std;
int n,i,coun,f,g;
int main(){
    cin>>n;
    int a[101];
    int b[101];
    coun=0;
    g=0;
    f=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=100;i++)
    {
        b[i]=0;
    }
    for(i=1;i<=n;i++)
    {
        if(f==0)
        {
            g++;
        }
        if(i==1 && a[2]==2)
        {
            b[g]++;
            f=1;
        }
        else if(i==n && a[n-1]==999)
        {
            b[g]++;
            f=1;
        }
        else if(a[i-1]==a[i]-1 && a[i+1]==a[i]+1)
        {
            b[g]++;
            f=1;
        }
        else
        {
            f=0;
        }
    }
    b[0]=0;
    for(i=1;i<=100;i++)
    {
        if(b[i]>b[0])
        {
            b[0]=b[i];
        }
    }
    cout<<b[0];
}