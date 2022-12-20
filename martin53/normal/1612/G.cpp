#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n,inp[nmax];

int COEFF[nmax*2],fact[nmax];

void add(int l,int r)
{
    COEFF[l+nmax]++;
    COEFF[r+nmax+2]--;
}

long long ask_sum(long long l,long long r)
{
    long long p=l+r;
    long long q=r-l+1;

    if(p%2==0)p=p/2;
    else q=q/2;

    return (p%mod)*(q%mod)%mod;
}

int main()
{
    fact[0]=1;
    for(int i=1;i<nmax;i++)fact[i]=1LL*i*fact[i-1]%mod;

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        add(-inp[i]+1,inp[i]-1);
    }

    for(int i=2;i<2*nmax;i++)
        COEFF[i]+=COEFF[i-2];

    long long sum=0,ways=1;

    long long added=0;

    for(int i=0;i<2*nmax;i++)
        if(COEFF[i])
        {
            int cur=COEFF[i];

            //+(added+1)+...(added+cur)

            sum=(sum+ask_sum(added+1,added+cur)*(i-nmax)%mod)%mod;
            sum=(sum+mod)%mod;

            added+=cur;

            ways=ways*fact[cur]%mod;
        }

    printf("%lld %lld\n",sum,ways);

    return 0;
}