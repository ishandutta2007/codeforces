#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=1e9+7;

int n;

long long pwr(long long a,long long b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        b=b/2;
        a=a*a%mod;
    }
    return ret;
}
int go(int bit)
{
    if(bit==0)return 1;

    long long ret=0;

    long long coeff=0;

    //all 1
    if(n%2)coeff=coeff+1;
    else ret=(ret+pwr(2,1LL*n*(bit-1)))%mod;

    //LHS is 0 - 2^(n-1)-(n-even?) for RHS
    coeff=(coeff+pwr(2,n-1))%mod;

    if(n%2==0)coeff=(coeff-1+mod)%mod;

    ret=(ret+1LL*coeff*go(bit-1))%mod;

    return ret;
}
int solve()
{
    int k;

    scanf("%i%i",&n,&k);

    return go(k);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}