#include<bits/stdc++.h>
#define int long long
using namespace std;
int t, n, i, j, k, mod=998244353, A[200010], B[200010], fact[200010];
int f(int a, int b)
{
    if(b==0)return 1;
    int p=f(a, b/2);
    if(b%2)return ((p*p)%mod*a)%mod;
    else return (p*p)%mod;
}
int nck(int a, int b)
{
    return ((fact[a]*f(fact[b], mod-2)%mod)*f(fact[a-b], mod-2))%mod;
}
main()
{
    for(scanf("%lld %lld", &n, &k);i++<n;)scanf("%lld", &A[i]),A[i]++;
    for(i=0;i++<n;)
    {
        B[A[i]]=i;
    }
    for(i=0;i++<n;)swap(A[i], B[i]);
    for(i=0;++i<n;)
    {
        int a=B[i];
        int b=B[i+1];
        if(A[a+1]>A[b+1])k--;
    }
    if(k<=0)
    {
        puts("0");
        return 0;
    }
    fact[0]=1;
    for(i=0;i++<n+k;)fact[i]=fact[i-1]*i,fact[i]%=mod;
    cout<<nck(n+k-1, n);
}