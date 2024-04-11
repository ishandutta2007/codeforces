#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42,mod=998244353;

int n,m;

int inp[nmax];

int cnt[nmax];

int fenwick[nmax];

long long inv[nmax];

void update(int pos,int val)
{
    while(pos<nmax)
    {
        fenwick[pos]+=val;
        pos=pos+(pos&(-pos));
    }
}

int query(int pos)
{
    int ret=0;

    while(pos)
    {
        ret+=fenwick[pos];
        pos=pos-(pos&(-pos));
    }

    return ret;
}

int main()
{
    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<nmax;i++)inv[i]=(mod-mod/i)*inv[mod%i]%mod;

    scanf("%i%i",&n,&m);

    long long coeff=1;
    for(int i=2;i<=n;i++)coeff=coeff*i%mod;

    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        cnt[cur]++;

        coeff=coeff*inv[cnt[cur]]%mod;
    }

    for(int i=1;i<=m;i++)
    {
        scanf("%i",&inp[i]);
    }

    for(int i=1;i<nmax;i++)
        update(i,cnt[i]);

    long long outp=0;

    int i;
    for(i=1;i<=n&&i<=m;i++)
    {
        long long sum=query(inp[i]-1);

        outp=outp+coeff*sum%mod*inv[n+1-i]%mod;

        if(cnt[inp[i]]==0)break;

        coeff=coeff*inv[n+1-i]%mod*cnt[inp[i]]%mod;

        cnt[inp[i]]--;

        update(inp[i],-1);
    }

    if(i>n&&i<=m)outp=(outp+1)%mod;

    outp=outp%mod;

    printf("%lld\n",outp);

    return 0;
}