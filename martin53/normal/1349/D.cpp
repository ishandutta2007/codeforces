#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,mod=998244353;

long long my_pow(long long a,int b)
{
    long long ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }

    return ret;
}
long long inv(long long a)
{
    return my_pow(a,mod-2);
}
int n,inp[nmax];

int sum=0;

long long diff[nmax];//time to make (i, sum-i) -> (i+1, sum-i-1)

long long when[nmax];

int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        sum=sum+inp[i];
    }

    diff[0]=n-1;

    for(int i=1;i<sum;i++)
    {
        long long RHS=1LL*(sum-i)*inv(sum)%mod*1%mod*inv(n-1)%mod;

        long long LHS=(1+1LL*i*inv(sum)%mod*diff[i-1])%mod;

        diff[i]=LHS*inv(RHS)%mod;
    }

    for(int i=sum-1;i>=0;i--)
    {
        when[i]=(when[i+1]+diff[i])%mod;
    }

    /*
    for(int i=0;i<=sum;i++)
        cout<<when[i]<<" ";cout<<endl;
    */

    long long outp=0;
    for(int i=1;i<=n;i++)
        outp=(outp+when[inp[i]])%mod;

    outp=(outp-1LL*(n-1)*when[0])%mod+mod;

    outp=outp*inv(n)%mod;

    printf("%lld\n",outp);
    return 0;
}