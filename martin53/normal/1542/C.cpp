#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;

int solve()
{
    long long n;

    scanf("%lld",&n);

    long long ret=0;

    long long g=1;

    for(int i=2;g<=n;i++)
    {
        //g|x, i\x

        long long valid=n/g;

        long long remain=i/__gcd(1LL*i,g);

        valid=valid-valid/remain;

        ret=(ret+1LL*valid%mod*i%mod)%mod;

        //cout<<i<<" -> "<<valid<<" "<<g<<endl;

        g=i/__gcd(g,1LL*i)*g;


        //cout<<i<<" -> "<<g<<endl;
    }

    return ret;
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