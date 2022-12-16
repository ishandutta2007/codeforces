#include<bits/stdc++.h>
using namespace std;
const int nmax=2e3+42,mod=1e9+7;
int n,k,a[nmax];
long long p[nmax],q[nmax];
long long my_pow(long long a,long long b)
{
if(b==0)return 1;
long long c=my_pow(a,b/2);
if(b%2==0)return (c*c)%mod;
return ((c*c)%mod)*a%mod;
}
int inv(int x)
{
return my_pow(x,mod-2);
}
int main()
{
cin>>n>>k;
for(int i=1;i<=n;i++)cin>>a[i];
p[0]=1;
for(int i=k;i<=k+n;i++)p[i-k+1]=p[i-k]*i%mod;
q[0]=1;
for(int i=1;i<=n;i++)q[i]=q[i-1]*inv(i)%mod;

for(int i=1;i<=n;i++)
{
    long long sum=0;
    for(int j=i;j>=1;j--)
    {
        long long now=p[i-j]*q[i-j]%mod;
        now=now*a[j]%mod;
        sum=sum+now;
    }
    cout<<sum%mod<<" ";
}
cout<<endl;
return 0;
}