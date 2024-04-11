#include<bits/stdc++.h>
using namespace std;
int n,i;
vector<long long> v;
long long sum = 0;
long long mod = 998244353;
long long binom;
 
long long mul(long long a, long long b)
{
    return (a*b)%mod;
}
 
long long power(long long base, long long powe)
{
    if(powe == 0)
        return 1LL;
    if(powe == 1)
        return base;
 
    long long get = power(base,powe/2);
    get = mul(get,get);
    if(powe%2 == 1)
        get = mul(get,base);
    return get;
}
 
long long inverse(long long base)
{
    return power(base, mod-2);
}
 
long long factorial(long long n)
{
    if(n==0 || n==1)
        return 1LL;
    else
    {
        return mul(n,factorial(n-1));
    }
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin>>n;
    n*=2;
 
    binom = mul(mul(factorial(n),inverse(factorial(n/2))), inverse(factorial(n/2)));
    binom%=mod;
    for(i=0;i<n;i++)
    {
        long long a;
        cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end(),greater<int>());
    for(i=0;i<n;i++)
    {
        if(i<n/2)
            sum+=v[i];
        else
            sum-=v[i];
    }
    sum%=mod;
    sum = mul(sum,binom);
    cout<<sum<<endl;
    return 0;
}