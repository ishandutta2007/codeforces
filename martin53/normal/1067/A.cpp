#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353;

int n,inp[nmax];

int dp[nmax][201][2];

int rec(int pos,int prv,bool satisfied)
{
    if(pos>n)return satisfied;

    if(dp[pos][prv][satisfied]!=-1)return dp[pos][prv][satisfied];

    int ret=0;

    if(satisfied==1)
    {
        if(inp[pos]!=-1)
        {
            ret=(ret+rec(pos+1,inp[pos],prv>=inp[pos]))%mod;
        }
        else
        {
            /*
            for(int cur=1;cur<=200;cur++)
                ret=(ret+rec(pos+1,cur,prv>=cur))%mod;
            */

            if(prv==200)
            {
                for(int cur=1;cur<=200;cur++)
                    ret=(ret+rec(pos+1,cur,prv>=cur))%mod;
            }
            else
            {
                ret=(ret+rec(pos,prv+1,1))%mod;

                ret=(ret-rec(pos+1,prv+1,1)+mod)%mod;

                ret=(ret+rec(pos+1,prv+1,0))%mod;
            }

        }
    }
    else
    {
        if(inp[pos]!=-1)
        {
            if(prv<=inp[pos])ret=(ret+rec(pos+1,inp[pos],prv>=inp[pos]))%mod;
        }
        else
        {
            if(prv==200)
            {
                for(int cur=1;cur<=200;cur++)
                    if(prv<=cur)ret=(ret+rec(pos+1,cur,prv>=cur))%mod;
            }
            else
            {
                /*
                for(int cur=1;cur<=200;cur++)
                    if(prv<=cur)ret=(ret+rec(pos+1,cur,prv>=cur))%mod;
                */

                ret=(ret+rec(pos,prv+1,0))%mod;

                ret=(ret+rec(pos+1,prv,1))%mod;

                ret=(ret+rec(pos+1,prv+1,0))%mod;

                ret=(ret-rec(pos+1,prv+1,1)+mod)%mod;

            }

        }
    }
    dp[pos][prv][satisfied]=ret;
    return ret;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    memset(dp,-1,sizeof(dp));

    for(int pos=n;pos>=1;pos--)
        for(int prv=200;prv>=0;prv--)
            for(int satisfied=0;satisfied<2;satisfied++)
                rec(pos,prv,satisfied);

    printf("%i\n",rec(1,0,1));
    return 0;
}