#include<bits/stdc++.h>
using namespace std;

const int nmax=250+5;

int dp[nmax][nmax][nmax];

int n,m;
int inp[nmax];

int pos_pancakes[nmax];

int rec(int pos_inp,int pos_cake,int prv)
{
    if(pos_cake>m)return 0;

    if(pos_inp>n)return 1e9;

    if(dp[pos_inp][pos_cake][prv]!=-1)return dp[pos_inp][pos_cake][prv];

    int ret=1e9;

    int score_now=0;

    for(int i=1;i+pos_cake-1<=m&&i<=prv;i++)
    {
        score_now+=abs(pos_inp-pos_pancakes[i+pos_cake-1]);

        ret=min(ret,score_now+rec(pos_inp+1,i+pos_cake,i));
    }

    dp[pos_inp][pos_cake][prv]=ret;
    return ret;
}

int main()
{
    scanf("%i%i",&n,&m);

    int pointer=0;

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        for(int j=1;j<=inp[i];j++)
        {
            pointer++;
            pos_pancakes[pointer]=i;
        }

    }

    memset(dp,-1,sizeof(dp));

    printf("%i\n",rec(1,1,m));

    return 0;
}