#include<bits/stdc++.h>
using namespace std;

const int nmax=3e3+42;

int n,inp[nmax];

int dp[nmax][nmax];

int pref[nmax][nmax],suff_min[nmax][nmax];

int score(int l,int r,int sum)
{
    if(l>r)return 0;

    return pref[r][sum]-pref[l-1][sum];
}
void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n+1;i++)
        for(int j=i+1;j<=n+1;j++)
        {
            dp[i][j]=1e9;
            suff_min[i][j]=1e9;
        }
    for(int i=1;i<=n;i++)
        for(int sum=1;sum<=n;sum++)
        {
            pref[i][sum]=pref[i-1][sum]+(inp[i]+i>=sum);

            //cout<<i<<" "<<sum<<" -> "<<pref[i][sum]<<endl;
        }

    dp[n][n+1]=0;
    suff_min[n][n+1]=0;

    int ret=1e9;

    for(int pos=n-1;pos>=1;pos--)
    {
        for(int nxt=pos+1;nxt<=pos+inp[pos];nxt++)
        {
            /*
            for(int nxt_2=pos+inp[pos]+1;nxt_2<=n+1;nxt_2++)
                dp[pos][nxt]=min(dp[pos][nxt],dp[nxt][nxt_2]+score(pos+1,nxt-1,nxt));
            */
            dp[pos][nxt]=min(dp[pos][nxt],score(pos+1,nxt-1,nxt)+suff_min[nxt][pos+inp[pos]+1]);

            if(pos==1)ret=min(ret,dp[pos][nxt]);

            //cout<<pos<<" "<<nxt<<" with dp= "<<dp[pos][nxt]<<endl;
        }

        for(int nxt=pos+inp[pos];nxt>=pos+1;nxt--)
            suff_min[pos][nxt]=min(dp[pos][nxt],suff_min[pos][nxt+1]);
    }

    printf("%i\n",ret);
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