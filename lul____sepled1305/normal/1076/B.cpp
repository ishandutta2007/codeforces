#include<stdio.h>
#include<iostream>
using namespace std;
long long int i,n;

int main(){
    cin>>n;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            break;
        }
    }
    if(n==2)
        n=1;
    else if(i==2)
        n=n/2;
    else if(n%i ==0)
        n=((n-i)/2)+1;
    else
        n=1;
    cout<<n;
}