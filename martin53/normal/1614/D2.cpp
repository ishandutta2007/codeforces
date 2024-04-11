#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,MX=2e7+42;

int n,inp[nmax];

int seen[MX];
int cnt[MX];
long long dp[MX];

int least[MX];
int CNT[MX];
int how_much[MX];

void precalc()
{
    for(int i=1;i<MX;i++)least[i]=i;

    int p=2;

    for(int p=2;p*p<MX;p++)
    if(least[p]==p)
    {
        for(int j=p*p;j<MX;j+=p)
            least[j]=min(least[j],p);
    }

    for(int i=2;i<MX;i++)
    {
        int j=i;

        how_much[j]=1;

        while(j%least[i]==0)
        {
            j=j/least[i];
            how_much[i]*=least[i];
            CNT[i]++;
        }
    }
}

vector< pair<int,int> > cur={};

void dfs(int pos,int num)
{
    if(pos==cur.size())
    {
        cnt[num]++;
        return;
    }

    for(int i=0;i<=cur[pos].second;i++)
    {
        dfs(pos+1,num);
        num=num*cur[pos].first;
    }
}

void add(int val)
{
    cur={};

    while(val>1)
    {
        cur.push_back({least[val],CNT[val]});
        val=val/how_much[val];
    }

    dfs(0,1);
}

int main()
{
    precalc();

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);

        add(inp[i]);
    }

    for(int i=1;i<MX;i++)dp[i]=cnt[i];

    for(int j=MX-1;j>=1;j--)
    {
        int d=j;

        while(d>1)
        {
            int p=least[d];

            int i=j/p;

            dp[i]=max(dp[i],p*dp[j]+cnt[i]-cnt[j]);

            d=d/how_much[d];
        }
    }

    printf("%lld\n",dp[1]);

    return 0;
}