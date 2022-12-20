#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    inp[0]=0;
    inp[n+1]=1;

    for(int i=1;i<=n+1;i++)
        if(inp[i-1]==0&&inp[i]==1)
        {
            for(int j=1;j<=i-1;j++)printf("%i ",j);
            printf("%i ",n+1);
            for(int j=i;j<=n;j++)printf("%i ",j);
            printf("\n");

            return;
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