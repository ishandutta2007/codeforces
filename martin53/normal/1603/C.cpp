#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42,mod=998244353;

int n,inp[nmax];

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    long long outp=0;

    vector< pair<int,int> > seen={},help={};

    for(int i=n;i>=1;i--)
    {
        help={};

        for(auto w:seen)
        {
            int prv=w.first;

            int k=(inp[i]+prv-1)/prv;

            outp=(outp+1LL*w.second*(k-1)*i)%mod;

            help.push_back({inp[i]/k,w.second});
        }

        help.push_back({inp[i],1});

        seen={};

        for(auto w:help)
            if(seen.size()&&seen.back().first==w.first)seen.back().second+=w.second;
            else seen.push_back(w);
    }

    return outp;
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