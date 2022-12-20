#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,parent[nmax],order[nmax];

int inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&parent[i]);
    for(int i=1;i<=n;i++)scanf("%i",&order[i]);

    for(int i=1;i<=n;i++)inp[i]=0;

    int wrong=0;

    for(int i=1;i<=n;i++)
    {
        int cur=order[i];

        if(inp[parent[cur]]==0)wrong++;

        inp[cur]=i;
    }

    if(wrong>1)
    {
        printf("-1\n");
        return;
    }

    for(int i=1;i<=n;i++)printf("%i ",inp[i]-inp[parent[i]]);

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