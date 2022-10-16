#include <iostream>

using namespace std;
//ifstream cin ("plangaciosi.in");
//ofstream cout ("plangaciosi.out");
const long long mod=1000000007;
int v[1000006];
int dp[1<<22];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long k,n,t,i,j,mx,p,mxx=0,s,q,nr1=0,nr2=0,nr3=0;
    cin>>n;
    for(i=1;i<=n;++i)
    {
        cin>>v[i];
        dp[v[i]]=v[i];
    }
    for(i=0;i<22;++i)
    {
        for(int mask=(1<<i);mask<(1<<22);mask=((mask+1)|(1<<i)))
        {
            if(mask==33)
            {
                ++k;
            }
            if(dp[mask^(1<<i)]!=0)
                dp[mask]=dp[mask^(1<<i)];
        }
    }
    for(i=1;i<=n;++i)
    {
        int vlc=(1<<22)-1-v[i];
        if(dp[vlc]==0)
            cout<<"-1 ";
        else
            cout<<dp[vlc]<<' ';
    }
    return 0;
}