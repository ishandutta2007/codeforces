#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax],outp[nmax];

void rec(int l,int r,int d)
{
    if(l>r)return;

    int MX=l;

    for(int i=l;i<=r;i++)
        if(inp[MX]<inp[i])MX=i;

    outp[MX]=d;

    rec(l,MX-1,d+1);
    rec(MX+1,r,d+1);
}

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    rec(1,n,0);

    for(int i=1;i<=n;i++)printf("%i ",outp[i]);
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