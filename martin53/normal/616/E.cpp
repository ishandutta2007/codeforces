#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int main()
{
long long n,m;
scanf("%lld%lld",&n,&m);
long long ans=0;
if(m>n)
{
    ans=ans+1LL*((m-n)%mod)*(n%mod)%mod;
    m=n;
}
long long k=sqrt(n);

for(int i=1;i<=m&&n/i>k;i++)
    ans=(ans+n%i)%mod;

for(int c=k;c>=1;c--)
{
    long long k=n/c,j=n/(c+1)+1;
    k=min(k,m);
    if(j>m)break;
    /*
    for(int p=k;p>=j;p--)
        ans=(ans+n-c*p)%mod;
    */

    long long add=1LL*(n%mod)*((k-j+1)%mod)%mod;
    long long rem=(c%mod)*((k-j+1)%mod)%mod*((k+j)%mod)%mod*(((mod+1)/2)%mod)%mod;
    ans=ans+add-rem+mod;
    ans=ans%mod;

}
printf("%i\n",ans);
return 0;
}