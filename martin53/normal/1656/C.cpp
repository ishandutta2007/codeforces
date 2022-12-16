#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

bool solve()
{
    set<int> in={};

    scanf("%i",&n);

    for(int i=1;i<=n;i++)
    {
        scanf("%i",&inp[i]);
        in.insert(inp[i]);
    }

    if(in.size()==1)return 1;

    if(in.count(0)&&in.count(1))return 0;

    if(in.count(0))return 1;

    //no 0
    if(in.count(1)==0)return 1;

    sort(inp+1,inp+n+1);

    for(int i=n;i>1;i--)
        if(inp[i]-inp[i-1]==1)return 0;

    return 1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        if(solve())printf("YES\n");
        else printf("NO\n");
    }

    return 0;
}