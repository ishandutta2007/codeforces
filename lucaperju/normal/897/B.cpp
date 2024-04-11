#include <iostream>

using namespace std;
long long sum (long long a)
{
    long long ca=a,s=a;
    while(ca)
    {
        s=s*10+ca%10;
        ca/=10;
    }
    return s;
}
int main()
{
    long long k,p,s=0,cnt=0;
    cin>>k>>p;
    for(long long i=1;i<=k;++i)
        s=(s+sum(i))%p;
    cout<<s;
    return 0;
}