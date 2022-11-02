#include<stdio.h>
#include <iostream>
using namespace std;
int n,i;

int main(){
    int coun=0;
    cin>>n;
    char a[n+2],b[n+2];
    a[1]='a';
    for(i=2;i<=n+1;i++)
    {
        cin>>a[i];
        b[i]=a[i];
        if(a[i-1]>a[i] && coun==0)
        {
            coun++;
            b[i-1]=a[i];
        }
        else if(coun==1)
        {
            b[i-1]=a[i];
        }
    }
    for(i=2;i<=n;i++)
    {
        cout<<b[i];
    }
    return 0;
}