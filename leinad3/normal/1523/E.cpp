#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, a, b, ans, fact[200010], A[200010], mod=1e9+7;
int f(int a, int b)
{
    if(b==0)return 1;
    int p=f(a, b/2);
    if(b%2==0)return (p*p)%mod;
    else return ((p*p)%mod*a)%mod;
}
main()
{
    for(scanf("%lld", &t);t--;)
    {
        scanf("%lld %lld", &n, &k);
        for(i=0;i++<n;)fact[i]=A[i]=0;
        fact[0]=1;ans=0;
        for(i=0;i++<n;)fact[i]=fact[i-1]*i,fact[i]%=mod;
        for(i=1;;i++)
        {
            if(i+(i-1)*(k-1)>n)break;
            A[i]=(fact[n-(i-1)*(k-1)]*f(fact[n-(i-1)*(k-1)-i], mod-2))%mod;
        }
        for(i=1;;i++)
        {
            if(i+(i-1)*(k-1)>n)break;
            a=(n-i)*A[i]-A[i+1];a%=mod;a+=mod;a%=mod;
            ans+=((fact[n-i-1]*a)%mod*(i+1));ans%=mod;
        }
        printf("%lld\n", (ans*f(fact[n], mod-2))%mod);
    }
}