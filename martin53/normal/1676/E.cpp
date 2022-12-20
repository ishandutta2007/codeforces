#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,q;
long long inp[nmax];

void solve()
{
    scanf("%i%i",&n,&q);

    for(int i=1;i<=n;i++)scanf("%lld",&inp[i]);

    sort(inp+1,inp+n+1);

    reverse(inp+1,inp+n+1);

    for(int i=2;i<=n;i++)inp[i]+=inp[i-1];

    for(int i=1;i<=q;i++)
    {
        long long cur;
        scanf("%lld",&cur);

        if(inp[n]<cur)printf("-1\n");
        else
        {
            int pos=lower_bound(inp+1,inp+n+1,cur)-inp;

            printf("%i\n",pos);
        }
    }
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