#include<bits/stdc++.h>
using namespace std;

const int mod=998244353,nmax=36;

int n,m;

long long base[50];

long long outp[50],mult=1;

bool pick(long long val)
{
    for(int i=m-1;i>=0;i--)
        if((val&(1LL<<i)))
        {
            if(base[i]==0)
            {
                base[i]=val;
                return 1;
            }

            val=val^base[i];
        }
    return 0;
}

//2 groups of bits: [0, m/2] and [m/2+1, m-1]

long long dp[nmax][1<<(nmax/2)],help[nmax][1<<(nmax/2)];

void dfs(int pos,long long val)
{
    if(pos<=m/2)
    {
        int sz=1<<((m/2)+1);

        int remain=val%sz;

        dp[__builtin_popcountll(val/sz)][remain]++;

        //cout<<val<<" -> "<<__builtin_popcountll(val/sz)<<" "<<remain<<endl;

        return;
    }

    dfs(pos-1,val);
    if(base[pos])dfs(pos-1,val^base[pos]);
}
int main()
{
    scanf("%i%i",&n,&m);
    for(int i=1;i<=n;i++)
    {
        long long cur;
        scanf("%lld",&cur);

        if(pick(cur)==0)mult=mult*2%mod;
    }

    //cout<<"mult= "<<mult<<endl;

    //for(int i=0;i<m;i++)cout<<base[i]<<" ";cout<<endl;

    dfs(m-1,0);

    for(int pos=m/2;pos>=0;pos--)
    {
        memset(help,0,sizeof(help));

        for(int in=0;in<=m;in++)
            for(int num=0;num<(1<<(pos+1));num++)
            {
                //do nothing
                if(num<(1<<pos))help[in][num]=(help[in][num]+dp[in][num])%mod;
                else help[in+1][num-(1<<pos)]=(help[in+1][num-(1<<pos)]+dp[in][num])%mod;

                if(base[pos]==0)continue;

                num=num^base[pos];
                //xor
                if(num<(1<<pos))help[in][num]=(help[in][num]+dp[in][num^base[pos]])%mod;
                else help[in+1][num-(1<<pos)]=(help[in+1][num-(1<<pos)]+dp[in][num^base[pos]])%mod;

                num=num^base[pos];
            }

        //cout<<"pos= "<<pos<<endl;

        for(int in=0;in<=m;in++)
            for(int num=0;num<(1<<(pos));num++)
            {
                dp[in][num]=help[in][num];
                //if(dp[in][num])cout<<in<<" "<<num<<" -> "<<dp[in][num]<<endl;
            }
    }
    for(int i=0;i<=m;i++)
        printf("%lld ",dp[i][0]*mult%mod);

    return 0;
}