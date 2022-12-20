#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n;
pair<long long,long long> inp[nmax];

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    return a.second<b.second;
}

int main()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%lld%lld",&inp[i].first,&inp[i].second);

    sort(inp+1,inp+n+1,cmp);

    long long bought=0,outp=0;

    int l=1,r=n;

    while(l<=r)
    {
        if(inp[l].second<=bought)
        {
            outp+=inp[l].first;
            bought+=inp[l].first;
            l++;

            continue;
        }

        long long buy=min(inp[r].first,inp[l].second-bought);

        outp+=2*buy;
        bought+=buy;

        inp[r].first=inp[r].first-buy;

        if(inp[r].first==0)r--;
    }

    printf("%lld\n",outp);

    return 0;
}