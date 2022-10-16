#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
int v[1000006];
int dp[500005][10];
int dif (int mask1, int mask2)
{
    int mask=mask1^mask2;
    int cnt=0;
    while(mask)
    {
        cnt+=(mask&1);
        mask>>=1;
    }
    return cnt;
}
bool compatible (int mask1, int mask2, int m)
{
    if(m==2)
    {
        int mask=mask1^mask2;
        if(mask==0 || mask==3)
            return false;
        return true;
    }
    else
    {
        int mask=(mask1^mask2)&3;
        if(mask==0 || mask==3)
            return false;
        mask1>>=1;
        mask2>>=1;
        mask=(mask1^mask2)&3;
        if(mask==0 || mask==3)
            return false;
        return true;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long n,m,i,j,t;
    cin>>n>>m;
    if(n>=4 && m>=4)
    {
        cout<<-1;
        return 0;
    }
    if(n<=3)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                v[j]+=(c-'0')*(1<<(i-1));
            }
        }
    }
    else
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=m;++j)
            {
                char c;
                cin>>c;
                v[i]+=(c-'0')*(1<<(j-1));
            }
        }
    }
    if(m>3)
        swap(n,m);
    if(m==1)
    {
        cout<<0;
        return 0;
    }
        for(int mask=0;mask<(1<<m);++mask)
            dp[1][mask]=dif(mask,v[1]);
        for(i=2;i<=n;++i)
        {
            for(int mask=0;mask<(1<<m);++mask)
            {
                dp[i][mask]=10000007;
                for(int maskprec=0;maskprec<(1<<m);++maskprec)
                {
                    if(compatible(maskprec,mask,m))
                    {
                        dp[i][mask]=min(dp[i][mask],dp[i-1][maskprec]+dif(mask,v[i]));
                    }
                }
            }
        }
    int rz=dp[n][0];
    for(i=1;i<(1<<m);++i)
    {
        rz=min(rz,dp[n][i]);
    }
    cout<<rz;
    return 0;
}