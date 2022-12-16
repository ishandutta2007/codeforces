#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=1e9+7;

int n;

long long inp[nmax];

int seen[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    for(int i=0;i<60;i++)
    {
        seen[i]=0;

        for(int j=1;j<=n;j++)
            if((inp[j]&(1LL<<i)))seen[i]++;
    }

    long long outp=0;

    for(int j=1;j<=n;j++)
    {
        long long LHS=0,RHS=0;

        for(int bit=0;bit<60;bit++)
        {
            if((inp[j]&(1LL<<bit)))
            {
                long long cur=(1LL<<bit)%mod;

                cur=cur*(seen[bit])%mod;

                LHS=(LHS+cur)%mod;
            }

            if((inp[j]&(1LL<<bit)))
            {
                long long cur=(1LL<<bit)%mod;

                cur=cur*(n)%mod;

                RHS=(RHS+cur)%mod;
            }
            else
            {
                long long cur=(1LL<<bit)%mod;

                cur=cur*(seen[bit])%mod;

                RHS=(RHS+cur)%mod;
            }
        }

        //cout<<j<<" -> "<<LHS<<" "<<RHS<<endl;

        outp=(outp+LHS*RHS)%mod;
    }

    printf("%lld\n",outp);
}

int main()
{
    int t;
    scanf("%i",&t);
    while(t)
    {
        t--;
        solve();
    }

    return 0;
}