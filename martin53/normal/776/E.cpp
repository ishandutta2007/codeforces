#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long phi(long long n)
{
    long long ans=n;
    for(long long i=2;i*i<=n;i++)
        if(n%i==0)
        {
        ans=ans/i*(i-1);
        while(n%i==0)n=n/i;
        }
    if(n!=1)ans=ans/n*(n-1);
    return ans;
}
long long n,k;
int main()
{
cin>>n>>k;
if(k%2==0)k--;
for(long long i=1;i<=(k+1)/2;i++)
{
n=phi(n);
if(n==1)break;
}
cout<<n%mod<<endl;
return 0;
}