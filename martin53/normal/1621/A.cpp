#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,k;

    scanf("%i%i",&n,&k);

    if(k>(n+1)/2)
    {
        printf("-1\n");
        return;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j&&i%2&&k)
            {
                printf("R");
                k--;
            }
            else printf(".");
        }

        printf("\n");
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