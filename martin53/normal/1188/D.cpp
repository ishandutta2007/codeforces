#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,MX=59;

int n;
long long inp[nmax];

int dp[MX][nmax];//least to make everything equal and the last position numbers have additional 1

long long help[MX][nmax];

int cnt(int bit,long long l,long long r)
{
    if(l>r)return 0;

    int LHS=lower_bound(help[bit]+1,help[bit]+n+1,l)-help[bit];
    int RHS=upper_bound(help[bit]+1,help[bit]+n+1,r)-help[bit];

    //cout<<"cnt "<<bit<<" "<<l<<" "<<r<<" "<<digit<<" -> "<<LHS<<" "<<RHS<<" "<<RHS-LHS<<endl;

    return RHS-LHS;
}

int eval(int bit,long long cur)
{
    if(cur<(1LL<<bit))return cnt(bit,(1LL<<bit)-cur,(1LL<<(bit+1))-1-cur);
    return cnt(bit,0,(1LL<<(bit+1))-1-cur)+cnt(bit,(1LL<<(bit+1))-cur+(1LL<<bit),(1LL<<(bit+1))-1);
}

//min bits[x+inp[1]]+...+bits[x+inp[n]]
int rec(int bit,int carry)
{
    if(bit==MX)
    {
        if(carry==n+1)return 0;
        return 1e9;
    }
    if(dp[bit][carry]!=-1)return dp[bit][carry];

    long long cur=0;
    if(bit&&carry!=n+1)cur=(1LL<<(bit))-help[bit-1][carry];

    //make this bit of x 0
    int next_carry_0=lower_bound(help[bit]+1,help[bit]+n+1,(1LL<<(bit+1))-cur)-help[bit];
    int option_0=rec(bit+1,next_carry_0)+eval(bit,cur);

    //make this bit of x 1
    int next_carry_1=lower_bound(help[bit]+1,help[bit]+n+1,(1LL<<(bit+1))-cur-(1LL<<(bit)))-help[bit];
    int option_1=rec(bit+1,next_carry_1)+eval(bit,cur+(1LL<<bit));

    dp[bit][carry]=min(option_0,option_1);

    /*
    cout<<bit<<" "<<carry<<" -> "<<dp[bit][carry];
    cout<<" option_1 "<<option_1<<" "<<rec(bit+1,min(carry,next_one))<<" + "<<cnt(bit,1,carry-1,0)<<" + "<<cnt(bit,carry,n,1)<<" ; ";
    cout<<" option_0 "<<option_0<<" "<<rec(bit+1,max(carry,next_one))<<" + "<<cnt(bit,1,carry-1,1)<<" + "<<cnt(bit,carry,n,0)<<endl;
    */

    /*
    cout<<bit<<" "<<carry<<" -> "<<dp[bit][carry]<<" "<<cur<<" with ";
    cout<<" option_1 "<<option_1<<" "<<next_carry_1<<" "<<rec(bit+1,next_carry_1)<<" ; ";
    cout<<" option_0 "<<option_0<<" "<<next_carry_0<<" "<<rec(bit+1,next_carry_0)<<endl;
    */
    return dp[bit][carry];
}

int dumb()
{
    int ret=1e9;

    for(int cur=0;cur<1e5;cur++)
    {
        int now=0;

        for(int j=1;j<=n;j++)
        {
            int diff=cur+inp[j];

            while(diff)
            {
                now+=diff%2;
                diff=diff/2;
            }
        }

        ret=min(ret,now);
    }

    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+n+1);
    for(int i=1;i<=n;i++)
        inp[i]=inp[n]-inp[i];

    //for(int i=1;i<=n;i++)cout<<inp[i]<<" ";cout<<endl;

    for(int bit=0;bit<MX;bit++)
    {
        for(int j=1;j<=n;j++)
            help[bit][j]=inp[j]&((1LL<<(bit+1))-1);

        sort(help[bit]+1,help[bit]+n+1);

        /*
        cout<<bit<<" -> ";
        for(int j=1;j<=n;j++)
            cout<<help[bit][j]<<" ";cout<<endl;
        */
    }

    memset(dp,-1,sizeof(dp));

    for(int bit=MX-1;bit>=0;bit--)
        for(int i=1;i<=n+1;i++)
            rec(bit,i);

    printf("%i\n",rec(0,n+1));

    //cout<<dumb()<<endl;

    return 0;
}