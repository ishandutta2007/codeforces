#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
long long lgput (long long a, long long exp)
{
    long long rz=1;
    while(exp)
    {
        if(exp&1)
        {
            exp^=1;
            rz=(rz*1LL*a)%mod;
        }
        else
        {
            exp>>=1;
            a=(a*1LL*a)%mod;
        }
    }
    return rz;
}
long long sp[100005]; /// sp peste sp peste 1/(m-i+1)
long long v[2505];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long m=0,i,j,n;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        m=m+v[i];
    }
    for(i=1;i<=100000;++i)
        sp[i]=lgput(m-i+1,mod-2);
    for(i=1;i<=100000;++i)
        sp[i]=(sp[i]+sp[i-1])%mod;
    for(i=1;i<=100000;++i)
        sp[i]=(sp[i]+sp[i-1])%mod;
    long long rz=0;
    for(i=1;i<=n;++i)
    {
        rz=(rz+(m-1LL)*1LL*(v[i]-sp[v[i]]+mod)%mod)%mod;
    }
    cout<<rz;
    return 0;
}