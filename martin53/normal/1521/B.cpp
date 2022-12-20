#include<bits/stdc++.h>
using namespace std;

const int nmax=1e5+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    int mini=1;
    for(int i=2;i<=n;i++)
        if(inp[i]<inp[mini])mini=i;

    printf("%i\n",n-1);
    for(int i=1;i<=n;i++)
        if(i!=mini)
        {
            int need=inp[mini];

            if(i<mini)need+=mini-i;
            else need+=i-mini;

            printf("%i %i %i %i\n",i,mini,need,inp[mini]);
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