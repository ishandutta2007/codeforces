#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,u,v,inp[nmax];

void solve()
{
    scanf("%i%i%i",&n,&u,&v);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=2;i<=n;i++)
        if(abs(inp[i]-inp[i-1])>1)
        {
            printf("0\n");
            return;
        }

    bool two=1;

    for(int i=2;i<=n;i++)
        if(inp[i]!=inp[i-1])two=0;

    if(two)
    {
        printf("%i\n",v+min(u,v));
        return;
    }

    printf("%i\n",min(u,v));
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