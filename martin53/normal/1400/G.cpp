#include<bits/stdc++.h>
using namespace std;

const int nmax=3e5+42,mod=998244353;

int n,m;

pair<int,int> inp[nmax];

pair<int,int> edges[nmax];

int pref[nmax];

long long mem[41][nmax];

long long fact[nmax],inv[nmax];

long long C(int n_,int k_)
{
    if(n_<0||k_<0||n_<k_)return 0;

    return fact[n_]*inv[k_]%mod*inv[n_-k_]%mod;
}

long long outp=0;

bool forced[nmax];

long long ask(int sub,int l,int r)
{
    long long lhs=mem[sub][r]-mem[sub][l-1];

    lhs=(lhs%mod+mod)%mod;

    return lhs;
}
void rec(int pos)
{
    if(pos>m)
    {
        set<int> in={};

        int coeff=1;

        for(int i=1;i<=m;i++)
            if(forced[i])
            {
                in.insert(edges[i].first);
                in.insert(edges[i].second);
                coeff=-coeff;
            }
        int l=in.size(),r=n;
        l=max(l,1);

        for(auto w:in)
        {
            int lq=inp[w].first;
            int rq=inp[w].second;

            l=max(l,lq);
            r=min(r,rq);

            if(l>r)return;
        }

        long long cur=ask(in.size(),l,r)*coeff;

        cur=(cur%mod+mod)%mod;

        outp=(outp+cur)%mod;

        return;
    }

    rec(pos+1);

    forced[pos]=1;

    rec(pos+1);

    forced[pos]=0;
}
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)
    {
        scanf("%i%i",&inp[i].first,&inp[i].second);

        pref[inp[i].first]++;
        pref[inp[i].second+1]--;
    }

    for(int i=1;i<=n;i++)
        pref[i]=pref[i-1]+pref[i];

    for(int i=1;i<=m;i++)
    {
        scanf("%i%i",&edges[i].first,&edges[i].second);
    }

    fact[0]=1;
    for(int i=1;i<=n;i++)
        fact[i]=fact[i-1]*i%mod;

    inv[0]=1;
    inv[1]=1;
    for(int i=2;i<=n;i++)
        inv[i]=1LL*(mod-mod/i)*inv[mod%i]%mod;

    for(int i=2;i<=n;i++)
        inv[i]=inv[i-1]*inv[i]%mod;

    for(int sub=0;sub<=2*m;sub++)
    {
        for(int i=1;i<=n;i++)
            mem[sub][i]=(mem[sub][i-1]+C(pref[i]-sub,i-sub))%mod;
    }

    rec(1);
    printf("%lld\n",outp);

    return 0;
}