#include<stdio.h>
#include<iostream>
using namespace std;
unsigned long long int n,m,k,l,f;
int main(){
    cin>>n>>m>>k>>l;
    if(m>n)
    {
        printf("-1");
    }
    else if(k+l>n)
    {
        printf("-1");
    }
    else
    {
        f=n-n%m;
        if(f<k+l)
        {
            printf("-1");
        }
        else
        {
            k=k+l;
            if(k%m==0)
            {
                f=k/m;
            }
            else
            {
                f=k/m+1;
            }
            cout<<f;
        }
    }
    return 0;
}