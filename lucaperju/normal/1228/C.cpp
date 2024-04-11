#include <bits/stdc++.h>

using namespace std;
const int mod=1000000007;
int mat[1003][1003];
long long rz=1;
long long lgput (long long val, long long put)
{
    long long rz=1;
    while(put)
    {
        if(put&1LL)
        {
            --put;
            rz=(rz*1LL*val)%mod;
        }
        else
        {
            val=(val*1LL*val)%mod;
            put>>=1LL;
        }
    }
    return rz;
}
long long add (long long x, long long y)
{
    long long cur=0;
    while(y)
    {
        y/=x;
        cur+=y;
    }
    rz=(rz*1LL*lgput(x,cur))%mod;
}
int main()
{
    long long i,j,x,y;
    cin>>x>>y;
    for(i=2;i*i<=x;++i)
    {
        if(x%i==0)
        {
            add(i,y);
            while(x%i==0)
                x/=i;
        }
    }
    if(x!=1)
        add(x,y);
    cout<<rz;
    return 0;
}