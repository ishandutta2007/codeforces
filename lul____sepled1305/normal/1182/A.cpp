#include<bits/stdc++.h>
using namespace std;
long long int a,b,n,i;
long long int f[1000000];
int main()
{
    cin>>n;
    f[1]=2;
    if(n%2)
    {
        cout<<"0";
    }
    else
    {
        for(i=2;i<=n/2;i++)
        {
            f[i]=2*f[i-1];
        }
        cout<<f[n/2];
    }
}