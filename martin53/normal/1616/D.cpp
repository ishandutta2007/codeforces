#include<bits/stdc++.h>
using namespace std;

const int nmax=5e4+42;

int n,inp[nmax],x;

int dp[nmax][2][2];

int rec(int pos,bool prev,bool prevprev)
{
    if(pos>n)return 0;

    if(dp[pos][prev][prevprev]!=-1)return dp[pos][prev][prevprev];

    int ret=rec(pos+1,0,prev);//do not use

    //use
    bool ok=1;
    if(prev&&inp[pos]+inp[pos-1]<0)ok=0;
    if(prev&&prevprev&&inp[pos]+inp[pos-1]+inp[pos-2]<0)ok=0;

    if(ok)ret=max(ret,1+rec(pos+1,1,prev));

    dp[pos][prev][prevprev]=ret;
    return ret;
}

int solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    scanf("%i",&x);

    for(int i=1;i<=n;i++)inp[i]-=x;

    memset(dp,-1,sizeof(dp));

    return rec(1,0,0);
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}