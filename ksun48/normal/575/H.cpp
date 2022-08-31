#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int fact[3000001];
int ifact[3000001];

int powmod(int a, int b)
{
    int ret=1;
    while(b)
    {
        if(b&1)
            ret=1LL*ret*a%MOD;
        a=1LL*a*a%MOD;
        b/=2;
    }
    return ret;
}
int main()
{
    fact[0]=1;
    for(int i=1; i<=3000000; i++)
        fact[i]=1LL*fact[i-1]*i%MOD;
    ifact[3000000]=powmod(fact[3000000], MOD-2);
    for(int i=3000000-1; i>=0; i--)
        ifact[i]=1LL*ifact[i+1]*(i+1)%MOD;
    int N;
    scanf("%d", &N);
    int n=2*N+1, k=N;
    int tmp=1LL*fact[n]*ifact[k]%MOD*ifact[n-k]%MOD;
    printf("%lld\n", ((2LL*tmp-1)%MOD+MOD)%MOD);
    return 0;
}