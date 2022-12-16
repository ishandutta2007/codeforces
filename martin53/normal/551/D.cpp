#include <bits/stdc++.h>
#define ull unsigned long long
using namespace std;
ull m;
ull my_pow(ull a,ull b)
{
    ull ret=1;
    while(b)
    {
        if(b%2)ret=ret*a%m;
        b=b/2;
        a=a*a%m;
    }
    return ret;
}
map<ull,ull> mem;
ull fib(ull n_)
{
    if(n_<=2)return 1;
    if(mem.count(n_))return mem[n_];
    ull ans;
    if(n_%2==0)
    {
        ans=fib(n_/2)*(fib(n_/2-1)+fib(n_/2+1));
    }
    else
    {
        ans=fib(n_/2)*fib(n_/2)+fib(n_/2+1)*fib(n_/2+1);
    }
    ans=ans%m;
    mem[n_]=ans;
    return ans;
}
int main()
{
ull n,k,l;
cin>>n>>k>>l>>m;

if(l!=64&&(1ULL<<l)<=k)
{
    cout<<0<<endl;
    return 0;
}
ull ans=1%m;
for(int i=0;i<l;i++)
    if((k&(1ULL<<i))==0)ans=ans*(fib(n+2)%m)%m;
    else ans=ans*((my_pow(2,n)-fib(n+2)+m)%m)%m;
cout<<ans<<endl;
return 0;
}