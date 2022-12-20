#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],outp[nmax];

long long MX;

void solve()
{
    scanf("%i%lld",&n,&MX);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    vector<int> cur={};

    long long sum=0;

    for(int i=1;i<=n;i++)
        if(inp[i]<=MX)
        {
            cur.push_back(i);
            sum+=inp[i];
        }

    if(2*sum<MX)
    {
        printf("-1\n");
        return;
    }

    while(sum>MX)
    {
        vector<int> groups[2]={{},{}};
        long long sums[2]={0,0};

        for(int i=0;i<cur.size();i++)
        {
            int where=i%2;

            groups[where].push_back(cur[i]);
            sums[where]+=inp[cur[i]];
        }

        if(2*sums[0]>=MX)cur=groups[0],sum=sums[0];
        else cur=groups[1],sum=sums[1];
    }

    printf("%i\n",cur.size());
    for(auto k:cur)printf("%i ",k);
    printf("\n");
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        solve();
    }
    return 0;
}