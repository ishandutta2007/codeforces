#include<iostream>
#include<stdio.h>
using namespace std;
int n,i,k=0,f=0;
int main(){
    scanf("%d",&n);
    int a[n+1],b[n+1];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[a[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&f);
        if(k<b[f])
        {
            printf("%d ",b[f]-k);
            k=b[f];
        }
        else
        {
            printf("0 ");
        }
    }
}