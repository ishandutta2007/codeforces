#include<bits/stdc++.h>
using namespace std;
long long f(long long a,long long b)
{
    if(b==0)return 0;
    if(a==1)return b;
    long long c=__gcd(a,b);
    if(c!=1)return f(a/c,b/c);
    vector<long long> d={};
    d.push_back(a);
    for(long long i=2;i*i<=a;i++)
        if(a%i==0)d.push_back(i),d.push_back(a/i);
    long long mini=b;
    for(auto k:d)
        mini=min(mini,b%k);
    return mini+f(a,b-mini);
}
int main()
{
long long a,b;
scanf("%lld%lld",&a,&b);
printf("%lld\n",f(a,b));
return 0;
}