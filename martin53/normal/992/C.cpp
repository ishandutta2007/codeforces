#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
long long x,k;
long long my_pow(long long a,long long b)
{
if(b==0)return 1;
long long c=my_pow(a,b/2);
if(b%2==0)return (c*c)%mod;
return ((c*c)%mod*a)%mod;
}
int main()
{
cin>>x>>k;
if(x==0)
{
cout<<0<<endl;
return 0;
}

long long p=my_pow(2,k+1);
p=(p*(x%mod))%mod;
long long q=my_pow(2,k)-1;
long long outp=p-q+2LL*mod;
outp=outp%mod;
cout<<outp<<endl;
return 0;
}