#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;
int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<n;i++)
        if(inp[i]!=inp[i+1])
        {
            if(i!=1)
            {
                printf("%i\n",i+1);
                return;
            }

            if(inp[1]==inp[3])printf("2\n");
            else printf("1\n");

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