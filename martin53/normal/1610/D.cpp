#include<bits/stdc++.h>
using namespace std;

const int BITS=32,nmax=1e6+42,mod=1e9+7;

int cnt[BITS];

int pwr[nmax];

int main()
{
    pwr[0]=1;
    for(int i=1;i<nmax;i++)pwr[i]=2*pwr[i-1]%mod;

    int n;
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        int v2=0;
        while(cur%2==0)
        {
            v2++;
            cur=cur/2;
        }

        cnt[v2]++;
    }

    long long outp=pwr[n]-1;

    int wrong=0;
    for(int i=1;i<BITS;i++)
        if(cnt[i]>0)
        {
            long long now=pwr[cnt[i]-1];

            for(int j=i+1;j<BITS;j++)
                now=now*pwr[cnt[j]]%mod;

            outp=(outp-now)%mod;
            outp=(outp+mod)%mod;
        }

    printf("%lld\n",outp);

    return 0;
}