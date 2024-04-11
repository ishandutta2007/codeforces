#include<bits/stdc++.h>
using namespace std;

const int nmax=2e3+42;

int n,k;

char inp[nmax];

string dp[nmax];

char mini[nmax];

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        cin>>inp[i];

    for(int i=0;i<=n;i++)dp[i]="";

    for(int i=1;i<=n;i++)
    {
        //u/d
        int letter=inp[i]-'a';

        int me=min(letter,min((letter+1)%k,(letter+k-1)%k));

        mini[i]=char(me+'a');
    }

    for(int i=1;i<=n;i++)
    {
        //u/d
        dp[i]=dp[i-1]+mini[i];

        //l
        if(i>=2)
        {
            dp[i]=min(dp[i],dp[i-1].substr(0,i-2)+inp[i]+dp[i-1][i-2]);
        }

        //r => u/d/l
        if(i>=2)
        {
            dp[i]=min(dp[i],dp[i-2]+mini[i]+inp[i-1]);
            if(i>=3)dp[i]=min(dp[i],dp[i-2].substr(0,i-3)+inp[i]+dp[i-2][i-3]+inp[i-1]);
        }

    }

    cout<<dp[n]<<endl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.tie();

    int t;
    cin>>t;

    while(t)
    {
        t--;
        solve();
    }

    return 0;
}