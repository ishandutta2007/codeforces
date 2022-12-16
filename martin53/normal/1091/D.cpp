#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n;
long long ask()
{
    long long now=0;
    for(int n_=1;n_<=n;n_++)
    {
        now=now*n_+1LL*(n_-1)*(n_-1);
        now=now%mod;
    }
    return now;
}
int main()
{
cin>>n;

long long ans=n;
for(int i=1;i<=n;i++)ans=ans*i%mod;

ans=ans-(n-1);

ans=(ans+mod)%mod;

ans=ans-ask();

ans=ans+mod;

ans=ans%mod;

cout<<ans<<endl;
return 0;
}