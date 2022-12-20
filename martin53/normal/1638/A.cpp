#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);

    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        if(i!=inp[i])
        {
            int j=i;

            while(inp[j]!=i)j++;

            reverse(inp+i,inp+j+1);

            break;
        }

    for(int i=1;i<=n;i++)printf("%i ",inp[i]);printf("\n");
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