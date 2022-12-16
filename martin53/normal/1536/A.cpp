#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    for(int i=1;i<=n;i++)
        if(inp[i]<0)
        {
            printf("NO\n");
            return;
        }

    printf("YES\n101\n");
    for(int i=0;i<=100;i++)printf("%i ",i);
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