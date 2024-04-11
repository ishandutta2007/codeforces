#include<bits/stdc++.h>
using namespace std;

const int nmax=200+42;

int n,p,q;

int mx;

unsigned int mem[nmax],bin[nmax];

unsigned int solve(int days)
{
    unsigned int ret=0,prod=1;
    for(int i=0;i<=mx;i++)//sum: (days^i)*C(n,i)
    {
        ret=ret+bin[i]*prod;
        prod=prod*days;
    }
    return ret;
}
int main()
{
    scanf("%i%i%i",&n,&p,&q);
    mx=min(n-1,p);

    bin[0]=1;
    for(int i=1;i<=mx;i++)
    {
        mem[i]=n+1-i;
        unsigned int current=i;
        for(int j=1;j<=i;j++)
        {
            unsigned int g=__gcd(current,mem[j]);
            mem[j]=mem[j]/g;
            current=current/g;
        }


        bin[i]=1;
        for(int j=1;j<=i;j++)bin[i]=bin[i]*mem[j];
    }

    unsigned int output=0;
    for(int d=1;d<=q;d++)
    {
        unsigned int current=solve(d)*d;
        output=output^current;
    }

    long long out=output;
    printf("%lld\n",out);
    return 0;
}