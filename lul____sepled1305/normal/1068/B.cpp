#include<stdio.h>
#include<iostream>
using namespace std;
int catholly[1000001];
long long int i,n,co=0,k,j,l,f,c=0;
int devicer(int c)
{
    c=0;
    for(k=1;k<=n;k++)
    {
        if(n<=k*k)
            break;
    }
    for(i=2;i<=k;i++)
    {
        catholly[i]=0;
        if(n%i==0)
        {
            l=i*i;
            catholly[i]=1;
            c=1;
            for(j=1;j<=k;j++)
            {
                if(n%l==0)
                {
                    catholly[i]++;
                    l=i*l;
                    c++;
                }
                else
                {
                    n=n*i/l;
                    catholly[0]= devicer(n);
                    catholly[0]= catholly[0]*(c+1);
                    break;
                }
            }
            break;
        }
        else if(i==k)
        {
            catholly[0]=2*catholly[0];
        }
    }
    return catholly[0];
}
int main(){
    catholly[0]=1;
    cin>>n;
    devicer(n);
    cout<<catholly[0];
    return 0;
}