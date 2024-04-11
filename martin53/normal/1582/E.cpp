#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

long long pref[nmax];

long long ask_sum(int l,int r)
{
    return pref[r]-pref[l-1];
}

bool can[nmax],help[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    reverse(inp+1,inp+n+1);
    for(int i=1;i<=n;i++)pref[i]=inp[i]+pref[i-1];

    for(int i=1;i<=n;i++)can[i]=1;

    for(int k=2;true;k++)
    {
        for(int i=1;i<=n;i++)help[i]=0;

        long long prv_max=0;

        for(int i=2*k-1;i<=n;i++)
        {
            if(i>=k&&can[i-k])prv_max=max(prv_max,ask_sum(i-2*k+2,i-k));

            if(prv_max>ask_sum(i-k+1,i))help[i]=1;
        }

        bool stop=1;

        for(int i=1;i<=n;i++)
        {
            can[i]=help[i];

            if(can[i])stop=0;
        }

        if(stop)return k-1;
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

    return 0;
}