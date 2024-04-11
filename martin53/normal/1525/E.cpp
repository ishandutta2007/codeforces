#include<bits/stdc++.h>
using namespace std;

const int nmax=25,mmax=5e4+42,mod=998244353;

int n,m;

int inp[nmax][mmax],cnt[nmax];

long long inv(long long a)
{
    long long b=mod-2,ret=1;

    while(b)
    {
        if(b%2)ret=ret*a%mod;
        a=a*a%mod;
        b=b/2;
    }

    return ret;
}

int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)scanf("%i",&inp[i][j]);

    long long INV=1;
    for(int i=1;i<=n;i++)INV=INV*inv(i)%mod;

    long long outp=0;
    for(int j=1;j<=m;j++)
    {
        memset(cnt,0,sizeof(cnt));
        for(int i=1;i<=n;i++)cnt[inp[i][j]]++;

        long long prod=1,cur=0;
        for(int i=n;i>=1;i--)
        {
            cur+=cnt[i+1];
            prod=prod*cur%mod;
            cur--;
        }

        outp=(outp+1-prod*INV)%mod;
        outp=(outp+mod)%mod;
    }

    printf("%lld\n",outp);

    return 0;
}