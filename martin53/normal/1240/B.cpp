#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

map<int,int> first_seen,last_seen;

int solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    first_seen={};
    last_seen={};

    for(int i=1;i<=n;i++)
    {
        last_seen[inp[i]]=i;
    }

    for(int i=n;i>=1;i--)
    {
        first_seen[inp[i]]=i;
    }

    vector< pair<int,int> > now={};
    for(auto k:first_seen)
    {
        now.push_back({first_seen[k.first],last_seen[k.first]});
    }

    int best=0;
    for(int i=0;i<now.size();i++)
    {
        int j=i+1;
        while(j<now.size()&&now[j-1].second<now[j].first)j++;

        best=max(best,j-i);

        i=j-1;
    }

    return first_seen.size()-best;
}

int main()
{
    int q;
    scanf("%i",&q);

    for(int i=1;i<=q;i++)
        printf("%i\n",solve());

    return 0;
}