#include<bits/stdc++.h>
#define int long long
using namespace std;
const int nmax=1.5e5+42,mmax=3e2+5;
int n,m,d;
struct firework
{
int a,b,t;
};
firework inp[mmax];
deque< pair<int/*value*/,int/*position*/> > max_deque,idle;
long long dp[nmax][2];
signed main()
{
cin>>n>>m>>d;
for(int i=1;i<=m;i++)
    cin>>inp[i].a>>inp[i].b>>inp[i].t;

for(int i=1;i<=n;i++)
    {
    dp[i][m&1]=inp[m].b-abs(i-inp[m].a);
    //cout<<i<<" "<<m<<" -> "<<dp[i][m&1]<<endl;
    }
for(int j=m-1;j>=1;j--)
{
    max_deque=idle;
    int l=1-d*(inp[j+1].t-inp[j].t)-1,r=1+d*(inp[j+1].t-inp[j].t)-1;

    for(int i=max(1LL,l);i<=r&&i<=n;i++)
    {
        while(max_deque.size()&&dp[i][!(j&1)]>=max_deque.back().first)max_deque.pop_back();
        max_deque.push_back({dp[i][!(j&1)],i});
    }
    for(int i=1;i<=n;i++)
    {
        if(l>=1)
        {
            if(max_deque.front().second==l)max_deque.pop_front();
        }
        l++;

        r++;
        if(r<=n)
        {
            while(max_deque.size()&&dp[r][!(j&1)]>=max_deque.back().first)max_deque.pop_back();
            max_deque.push_back({dp[r][!(j&1)],r});
        }

        dp[i][j&1]=max_deque.front().first+(inp[j].b-abs(inp[j].a-i));
        //cout<<l<<" "<<r<<endl;
        //cout<<i<<" "<<j<<" -> "<<dp[i][j&1]<<endl;
    }
    //cout<<endl;
}
long long ans=-1e18;
for(int i=1;i<=n;i++)ans=max(ans,dp[i][1&1]);
cout<<ans<<endl;
return 0;
}