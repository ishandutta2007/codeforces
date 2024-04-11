#include<bits/stdc++.h>
using namespace std;
const int nmax=1e5+4,mod=1e9+7;
int n,k;
string s;
long long pw[nmax];//power of 10
long long fact[nmax],inv[nmax];
long long my_pow(long long a,long long b)
{
    if(b==0)return 1;
    long long c=my_pow(a,b/2);
    if(b%2==0)return c*c%mod;
    return c*c%mod*a%mod;
}
long long inverse(long long x)
{
return my_pow(x,mod-2);
}
long long seen[nmax];
long long C(long long a,long long b)
{
if(a<0||a<b)return 0;
return fact[a]*inv[b]%mod*inv[a-b]%mod;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie();

cin>>n>>k;
cin>>s;

if(k==0)
{
long long ans=0;
for(auto p:s)
    ans=(ans*10+p-'0')%mod;
cout<<ans<<endl;
exit(0);
}

pw[0]=1;
for(int i=1;i<=n;i++)pw[i]=(pw[i-1]*10)%mod;

fact[0]=1;
inv[0]=1;
for(int i=1;i<=n;i++)
{
fact[i]=(fact[i-1]*i)%mod;
inv[i]=inverse(fact[i]);
}

for(int i=0;i<=n;i++)seen[i]=C(n-i-2,k-1);
long long sum=0;
for(int i=0;i<=n;i++)
{
sum=(sum+pw[i]*seen[i])%mod;
}

//cout<<"seen: ";for(int i=0;i<=n;i++)cout<<seen[i]<<" ";cout<<endl;

long long ans=0;

for(int i=1;i<=n;i++)
{
    //cout<<i<<" -> "<<sum<<endl;
    ans=(ans+sum*(s[i-1]-'0'))%mod;

    sum=(sum-pw[n-i]*seen[n-i])%mod;
    sum=(sum+mod)%mod;
        if(i!=n)
        {
        seen[n-i-1]=(seen[n-i-1]+seen[n-i])%mod;
        sum=(sum+pw[n-i-1]*seen[n-i])%mod;
        seen[n-i]=0;
        }
}

cout<<ans<<endl;
return 0;
}