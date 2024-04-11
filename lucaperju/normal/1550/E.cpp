#include <bits/stdc++.h>

using namespace std;
int v[200005];
int cnt[200005][18];
int nxt[200005][18];
int dp[131075];
void calcnext (int n, int l, int k)
{
    for(int kc=0;kc<k;++kc)
    {
        nxt[n+1][kc]=n+1;
        for(int i=n;i>=1;--i)
        {
            if(cnt[i][kc]>=l)
                nxt[i][kc]=i;
            else
                nxt[i][kc]=nxt[i+1][kc];
        }
    }
}
int getnext (int n, int pz, int kc, int l)
{
    if(pz>n)
        return n+1;
    return min(n+1,nxt[pz][kc]+l-1);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    long long i,t,s,n,k;
    cin>>n>>k;
    for(i=1;i<=n;++i)
    {
        char c;
        cin>>c;
        if(c=='?')
            v[i]=-1;
        else
            v[i]=c-'a';
    }
    for(int vlc=0;vlc<k;++vlc)
    {
        for(i=n;i>=1;--i)
        {
            if(v[i]==-1 || v[i]==vlc)
                cnt[i][vlc]=1+cnt[i+1][vlc];
            else
                cnt[i][vlc]=0;
        }
    }
    long long pas=(1<<17),rz=0;
    while(pas)
    {
        long long kc=rz+pas;
        if(kc*1LL*k>n)
        {
            pas>>=1;
            continue;
        }
        calcnext(n,kc,k);
        dp[0]=0;
        for(i=1;i<(1<<k);++i)
        {
            dp[i]=n+1;
            for(int j=0;j<k;++j)
            {
                if(i&(1<<j))
                {
                    dp[i]=min(dp[i],getnext(n,dp[i^(1<<j)]+1,j,kc));
                }
            }
        }
        if(dp[(1<<k)-1]<=n)
            rz=kc;
        pas>>=1;
    }
    cout<<rz;
    return 0;
}