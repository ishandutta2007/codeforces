#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

set<int> in={};

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    sort(inp+1,inp+n+1);

    in={};

    for(int i=1;i<=n;i++)
        if(in.count(inp[i]))in.insert(inp[i]+1);
        else in.insert(inp[i]);

    printf("%i\n",in.size());
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