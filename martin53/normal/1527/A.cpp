#include<bits/stdc++.h>
using namespace std;

int solve()
{
    int n;

    scanf("%i",&n);

    int  ret=1;

    while(ret*2<=n)ret=ret*2;

    return ret-1;
}

int main()
{
    int t;
    scanf("%i",&t);

    while(t)
    {
        t--;

        printf("%i\n",solve());
    }

    return 0;
}