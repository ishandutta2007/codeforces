#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,i,j,t;
    cin>>n;
    long long rz=1;
    for(i=1;i<=n;++i)
        rz=(rz*1LL*i)%mod;
    long long rz1=1;
    for(i=1;i<n;++i)
    {
        rz1=(rz1*2LL)%mod;
    }
    cout<<(rz-rz1+mod)%mod;
    return 0;
}