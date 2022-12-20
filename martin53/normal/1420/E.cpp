#include<bits/stdc++.h>
using namespace std;

const int nmax=80+5;

int n,inp[nmax];

int people[nmax],pointer=0;

int dp[nmax*nmax][nmax][nmax];

int score(int x)
{
    return x*(x-1)/2;
}
int rec(int changes,int who,int prv)
{
    if(who==0)return score(prv-1);

    if(dp[changes][who][prv]!=-1)return dp[changes][who][prv];

    if(prv-1<who)return 1e9;

    int ret=1e9;

    for(int me=1;me<prv;me++)
    {
        int changes_new=changes-abs(me-people[who]);

        if(changes_new<0)continue;

        ret=min(ret,rec(changes_new,who-1,me)+score(prv-me-1));
    }

    dp[changes][who][prv]=ret;
    return ret;
}
int main()
{
    memset(dp,-1,sizeof(dp));

    scanf("%i",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        if(inp[i]==1)
        {
            pointer++;
            people[pointer]=i;
        }
    }

    int start=n-pointer;

    start=score(start);

    for(int i=0;i<=n*(n-1)/2;i++)
        printf("%i ",start-rec(i,pointer,n+1));

    printf("\n");

    return 0;
}