#include <bits/stdc++.h>
using namespace std;
int lim,n,v[1003];
double dp[1003][51][51];
int cnt[1003][51][51];
pair<double,int> solve (double cost)
{
    for(int i=0;i<=n;++i)
        for(int j=0;j<=lim;++j)
            for(int k=0;k<=lim;++k)
                dp[i][j][k]=-1000000000,cnt[i][j][k]=0;
    dp[0][0][0]=0;
    for(int i=0;i<n;++i)
        for(int j=0;j<lim;++j)
            for(int k=0;k<lim;++k)
            {
                /// do nothing
                int nj=max(0,j-1);
                int nk=max(0,k-1);
                double vlc=dp[i][j][k]+(0<((v[i+1]&1&(j>0))|(v[i+1]&2&((k>0)<<1))));
                if(vlc>dp[i+1][nj][nk])
                {
                    dp[i+1][nj][nk]=vlc;
                    cnt[i+1][nj][nk]=cnt[i][j][k];
                }
                /// activate only first
                nj=lim-1;
                nk=max(0,k-1);
                vlc=dp[i][j][k]+(0<((v[i+1]&1)|(v[i+1]&2&((k>0)<<1))))-cost;
                if(vlc>dp[i+1][nj][nk])
                {
                    dp[i+1][nj][nk]=vlc;
                    cnt[i+1][nj][nk]=1+cnt[i][j][k];
                }
                /// activate only second
                nj=max(0,j-1);
                nk=lim-1;
                vlc=dp[i][j][k]+(0<((v[i+1]&1&(j>0))|(v[i+1]&2)))-cost;
                if(vlc>dp[i+1][nj][nk])
                {
                    dp[i+1][nj][nk]=vlc;
                    cnt[i+1][nj][nk]=1+cnt[i][j][k];
                }
                /// activate both
                nj=nk=lim-1;
                vlc=dp[i][j][k]+(0<((v[i+1]&1)|(v[i+1]&2)))-cost-cost;
                if(vlc>dp[i+1][nj][nk])
                {
                    dp[i+1][nj][nk]=vlc;
                    cnt[i+1][nj][nk]=2+cnt[i][j][k];
                }
            }
    double rz=-1000000000,cntc=0;
    for(int j=0;j<lim;++j)
        for(int k=0;k<lim;++k)
        {
            if(dp[n][j][k]>rz)
                rz=dp[n][j][k],cntc=cnt[n][j][k];
        }
    return make_pair(rz,cntc);
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    long long q,m,i,j,l,r,t;
    cin>>n>>m>>lim;
    int nc;
    cin>>nc;
    for(i=1;i<=nc;++i)
    {
        int a;
        cin>>a;
        ++v[a];
    }
    cin>>nc;
    for(i=1;i<=nc;++i)
    {
        int a;
        cin>>a;
        v[a]+=2;
    }
    double pas=1024,halflife=0;//haha funny joke
    while(pas>0.0001)
    {
        if(solve(halflife+pas).second>m)
            halflife+=pas;
        pas/=2.0;
    }
    pair<double,int>rz=solve(halflife);
    cout<<floor(rz.first+m*halflife+0.1);
    return 0;
}