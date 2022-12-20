#include<bits/stdc++.h>
using namespace std;

const int nmax=2e5+42;

int n,m;
long long inp[nmax],g[nmax];

int outp;

deque< pair<long long,int> > bck,help;

int solve()
{
    bck={};

    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    for(int i=1;i<n;i++)g[i]=abs(inp[i]-inp[i+1]);

    outp=0;

    for(int i=1;i<n;i++)
    {
        bck.push_back({g[i],1});

        for(auto &w:bck)
            w.first=__gcd(w.first,g[i]);

        while(bck.size()&&bck.front().first==1)bck.pop_front();

        help={};

        for(auto w:bck)
        {
            if(help.size()&&help.back().first==w.first)help[help.size()-1].second+=w.second;
            else help.push_back(w);
        }

        bck=help;

        int cur=0;
        for(auto w:bck)
            cur+=w.second;

        outp=max(outp,cur);
    }

    return outp+1;
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