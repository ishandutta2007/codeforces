#include<bits/stdc++.h>
using namespace std;
const int nmax=1e6+42;
int n,inp[nmax];

map<int,int> seen;
int extra=0;

void add(int val,int how)
{
    if(seen[val]>=2)extra--;
    seen[val]+=how;
    if(seen[val]>=2)extra++;
}
bool can(int sz)
{
    seen={};
    extra=0;
    for(int i=sz+1;i<=n;i++)
        add(inp[i],1);

    if(extra==0)return 1;

    for(int i=sz+1;i<=n;i++)
    {
        add(inp[i],-1);
        add(inp[i-sz],1);
        if(extra==0)return 1;
    }
    return 0;
}
int main()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)
        scanf("%i",&inp[i]);

    int ok=n,not_ok=-1;

    while(ok-not_ok>1)
    {
        int av=(ok+not_ok)/2;
        if(can(av))ok=av;
        else not_ok=av;
    }

    printf("%i\n",ok);
}