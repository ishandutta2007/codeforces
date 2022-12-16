#include<bits/stdc++.h>
using namespace std;

const int nmax=1e6+42;

int n,inp[nmax];

void solve()
{
    scanf("%i",&n);
    for(int i=1;i<=n;i++)scanf("%i",&inp[i]);

    printf("%i\n",n/2*6);

    for(int i=1;i<=n;i=i+2)
    {
        for(int t=1;t<=6;t++)
        {
            printf("%i %i %i\n",(t%2?1:2),i,i+1);
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