#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,kmax=18;

long long dp[kmax][nmax];

long long phi[nmax],pref[nmax];

long long c(int l,int r)
{
    long long ret=0;

    while(1LL*l*l<=r&&l<=r)
    {
        ret+=pref[r/l];
        l++;
    }

    for(int val=1;val<=r/l;val++)
    {
        int MX=r/val;
        int MN=(r+1+val+1-1)/(val+1);

        MX=min(MX,r);
        MN=max(MN,l);

        ret+=pref[val]*(MX-MN+1);
    }

    return ret;
}

void rec(int step,int lq,int rq,int l,int r)
{
    if(l>r)return;

    int av=(l+r)/2;

    int mini=lq;

    for(int i=lq;i<=rq&&i<=av;i++)
    {
        long long cur=dp[step-1][i-1]+c(i,av);

        if(cur<dp[step][av])
        {
            dp[step][av]=cur;
            mini=i;
        }
    }

    rec(step,lq,mini,l,av-1);
    rec(step,mini,rq,av+1,r);
}

void prec()
{
    for(int i=1;i<nmax;i++)phi[i]=i;

    for(int i=2;i<nmax;i++)
        if(phi[i]==i)
        {
            for(int j=i;j<nmax;j+=i)
                phi[j]=phi[j]/i*(i-1);
        }

    for(int i=1;i<nmax;i++)
        pref[i]=pref[i-1]+phi[i];

    for(int i=0;i<kmax;i++)
        for(int j=0;j<nmax;j++)
            dp[i][j]=1e18;

    dp[0][0]=0;

    for(int i=1;i<kmax;i++)
        rec(i,1,nmax-1,1,nmax-1);
}

int main()
{
    prec();

    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        int n,k;
        scanf("%i%i",&n,&k);

        if(k<kmax)printf("%lld\n",dp[k][n]);
        else printf("%i\n",n);
    }


    return 0;
}