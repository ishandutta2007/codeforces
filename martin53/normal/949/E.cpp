#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

int least=20;
vector<int> outp;

vector<int> cur={};

void solve(int deg,set<int> remain)
{
    if(cur.size()>=least)return;

    if(remain.size()==0)
    {
        least=cur.size();
        outp=cur;
        return;
    }

    bool all_even=1;
    for(auto k:remain)
        if(k%2)all_even=0;

    if(all_even)
    {
        set<int> help={};

        for(auto k:remain)
            help.insert(k/2);

        solve(deg+1,help);
        return;
    }

    set<int> help[2]={{},{}};
    //+(1<<deg)
    for(auto k:remain)
    {
        if(k%2==0&&k/2)help[0].insert(k/2);
        else if((k-1)/2)help[0].insert((k-1)/2);
    }
    cur.push_back(1<<deg);
    solve(deg+1,help[0]);
    cur.pop_back();

    //-(1<<deg)
    for(auto k:remain)
    {
        if(k%2==0&&k/2)help[1].insert(k/2);
        else if((k+1)/2)help[1].insert((k+1)/2);
    }
    cur.push_back(-(1<<deg));
    solve(deg+1,help[1]);
    cur.pop_back();
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    set<int> active={};
    for(int i=1;i<=n;i++)
        if(inp[i])active.insert(inp[i]);

    solve(0,active);

    printf("%i\n",least);
    for(auto k:outp)printf("%i ",k);

    return 0;
}