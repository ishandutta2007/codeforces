#include <bits/stdc++.h>
using namespace std;
long long cmmdc (long long a, long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(0);
    long long n,i,j,s=0,k,l,t;
    cin>>n;
    long long rz=0;
    for(i=1; i<=n; ++i)
    {
        long long a;
        cin>>a;
        rz=cmmdc(rz,a);
    }
    for(i=1; i*1LL*i<=rz; ++i)
    {
        if(rz%i==0)
        {
            ++s;
            if(rz/i!=i)
                ++s;
        }
    }
    cout<<s;
    return 0;
}