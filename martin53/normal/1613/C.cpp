#include<bits/stdc++.h>
using namespace std;

const int nmax=100+42;

long long n,h,inp[nmax];

vector< pair<long long,int> > seen;

long long can(long long cur)
{
    seen={};

    for(int i=1;i<=n;i++)
    {
        seen.push_back({inp[i],1});
        seen.push_back({inp[i]+cur,-1});
    }

    sort(seen.begin(),seen.end());

    long long outp=0;
    int sum=0;

    for(int i=0;i+1<seen.size();i++)
    {
        sum+=seen[i].second;
        if(sum>0)outp+=seen[i+1].first-seen[i].first;
    }


    return outp>=h;
}

long long solve()
{
    scanf("%lld%lld",&n,&h);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    long long ok=h,not_ok=0;
    while(ok-not_ok>1)
    {
        long long av=(ok+not_ok)/2;

        if(can(av))ok=av;
        else not_ok=av;
    }
    return ok;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;
        printf("%lld\n",solve());
    }

    return 0;
}