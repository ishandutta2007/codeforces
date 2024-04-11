#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    deque<int> outp={inp[1]};
    for(int i=2;i<=n;i++)
        if(inp[i]<outp[0])outp.push_front(inp[i]);
        else outp.push_back(inp[i]);

    for(auto w:outp)printf("%i ",w);
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