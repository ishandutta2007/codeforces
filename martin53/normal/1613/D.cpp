#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42,mod=998244353;

int n;

int dp[nmax][2];//dp[0]->normal, dp[1]->spam i-1 and i+1

int add(int cur)
{
    if(cur>=mod)cur=cur-mod;
    return cur;
}

int ask_dp(int pos,int coeff)
{
    if(pos<0||pos>n)return 0;

    return dp[pos][coeff];
}

int solve()
{
    for(int i=0;i<=n+1;i++)dp[i][0]=0,dp[i][1]=0;

    dp[0][0]=1;

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        int cur;
        scanf("%i",&cur);

        /*
        int f_cur_minus=0,f_cur=dp[cur][0],f_cur_plus=dp[cur+1][0];
        int g_cur_minus=dp[cur-1][1],g_cur_plus=dp[cur+1][1];

        dp[cur+1][0]=add(dp[cur+1][0]+dp[cur][0]);
        if(cur>0)dp[cur][0]=add(2*dp[cur][0]);
        */
        long long f_cur=0,f_cur_plus=0;
        f_cur+=ask_dp(cur,0);
        f_cur_plus+=ask_dp(cur,0);

        f_cur_plus+=2LL*ask_dp(cur+1,0);

        long long g_cur_minus=0,g_cur_plus=0;

        g_cur_minus+=2LL*ask_dp(cur-1,1)+ask_dp(cur-1,0);
        g_cur_plus+=2LL*ask_dp(cur+1,1);

        dp[cur][0]=f_cur%mod;
        dp[cur+1][0]=f_cur_plus%mod;

        if(cur>0)dp[cur-1][1]=g_cur_minus%mod;
        dp[cur+1][1]=g_cur_plus%mod;

        /*
        cout<<i<<" -> dp[0]= "<<dp[0][0]<<" "<<dp[1][0]<<" "<<dp[2][0]<<" "<<dp[3][0]<<endl;
        cout<<i<<" -> dp[1]= "<<dp[0][1]<<" "<<dp[1][1]<<" "<<dp[2][1]<<" "<<dp[3][1]<<endl;
        cout<<"---"<<endl;
        */
    }

    long long outp=-1;
    for(int i=0;i<=n+1;i++)outp+=dp[i][1]+dp[i][0];

    outp=outp%mod;

    return outp;
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