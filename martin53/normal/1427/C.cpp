#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int SZ,n,t[nmax],x[nmax],y[nmax];

int dp[nmax],pref[nmax];

void solve()
{
    scanf("%i%i",&SZ,&n);

    t[0]=0;
    x[0]=1;
    y[0]=1;

    for(int i=1;i<=n;i++)
    {
        scanf("%i%i%i",&t[i],&x[i],&y[i]);

        dp[i]=-1e9;

        int j=i-1;

        while(j>=0&&t[i]-t[j]<=2*SZ)
        {
            if(abs(x[i]-x[j])+abs(y[i]-y[j])<=t[i]-t[j])dp[i]=max(dp[i],dp[j]+1);
            j--;
        }
        if(j>=0)dp[i]=max(dp[i],pref[j]+1);
        pref[i]=max(pref[i-1],dp[i]);

        //cout<<i<<" -> "<<dp[i]<<" "<<j<<endl;
    }

    printf("%i\n",pref[n]);
}
int main()
{
    int t=1;

    while(t)
    {
        solve();
        t--;
    }

    return 0;
}