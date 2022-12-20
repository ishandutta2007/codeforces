#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,C=1e5;

int dp[nmax];

int n,m;

void update_sum(int val,int use,int when)
{
    for(int i=0;i<=m;i++)
        if(dp[i]>=0&&dp[i]<when)
        {
            //cout<<i<<" "<<val<<" "<<when<<" "<<use<<endl;

            for(long long j=i+val,steps=1;steps<=use&&j<=m;j=j+val,steps++)
                if(dp[j]==-1)dp[j]=when;
                else break;
        }
}

long long mult(long long i,long long val)
{
    return (i*val+C-1)/C;
}

void update_mult(long long val,int use,int when)
{
    for(int i=0;i<=m;i++)
        if(dp[i]>=0&&dp[i]<when)
        {
            for(long long j=mult(i,val),steps=1;steps<=use&&j<=m;j=mult(j,val),steps++)
                if(dp[j]==-1)dp[j]=when;
                else break;
        }
}

int main()
{
    memset(dp,-1,sizeof(dp));
    dp[0]=0;

    scanf("%i%i",&n,&m);

    for(int i=1;i<=n;i++)
    {
        long long t,x,y;

        scanf("%lld%lld%lld",&t,&x,&y);

        if(t==1)
        {
            update_sum((x+C-1)/C,y,i);
        }
        else
        {
            update_mult(x,y,i);
        }

        //for(int i=1;i<=m;i++)printf("%i ",dp[i]);printf("\n");
    }

    for(int i=1;i<=m;i++)printf("%i ",dp[i]);printf("\n");

    return 0;
}