#include<bits/stdc++.h>
using namespace std;

const int nmax=1e3+42,MX=1e6+42;

int n,inp[nmax];

int cnt[MX*2];

int solve()
{
    memset(cnt,0,sizeof(cnt));

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);
    for(int i=1;i<=n;i++)inp[i]+=MX;

    int need=(n+1)/2;

    sort(inp+1,inp+n+1);

    for(int i=need;i<=n;i++)
        if(inp[i]==inp[i-need+1])return -1;

    for(int i=n;i>=1;i--)
        inp[i]-=inp[1];

    for(int g=inp[n];g>=1;g--)
    {
        for(int i=1;i<=n;i++)
        {
            int cur=inp[i]%g;
            cnt[cur]++;
            if(cnt[cur]==need)return g;
        }

        for(int i=1;i<=n;i++)
            cnt[inp[i]%g]=0;
    }
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
}